#include "Plotter.h"
#include <iostream>

Plotter::Plotter(std::shared_ptr<Config> config)
    : _config{std::move(config)} {}

void Plotter::draw(wxDC& dc, const Data& currentData, const Data& previousData, const Data& historicData) {
  dc.SetBackground(*wxWHITE_BRUSH);
  dc.Clear();

  int width, height;
  width = dc.GetSize().GetWidth();
  height = dc.GetSize().GetHeight();

  dc.SetPen(wxPen(wxColour(255, 0, 0)));
  // dc.DrawRectangle(10, 10, width - 20, height - 20);
  // dc.SetClippingRegion(10, 10, width - 20, height - 20);

  // if we dont do this, we're screwed if macos decides to change the theme
  // light mode has dark system text
  // and dark mode has pure effing white...
  // sometimes its not you, who needs the meds
  // its the os...
  dc.SetTextForeground(wxColour(0, 0, 0));

  double x0, x1, y0, y1;

  switch (_config->getOperatingMode()) {
    case OperatingMode::CURRENT:
      x0 = currentData.getXMin();
      x1 = currentData.getXMax();
      y0 = currentData.getYMin();
      y1 = currentData.getYMax();
      break;

    case OperatingMode::CURRENT_AND_PREVIOUS:
      x0 = std::min(currentData.getXMin(), previousData.getXMin());
      x1 = std::max(currentData.getXMax(), previousData.getXMax());
      y0 = std::min(currentData.getYMin(), previousData.getYMin());
      y1 = std::max(currentData.getYMax(), previousData.getYMax());
      break;

    case OperatingMode::CONTINUOUS:
      x0 = historicData.getXMin();
      x1 = historicData.getXMax();
      y0 = historicData.getYMin();
      y1 = historicData.getYMax();
      break;
  }

  double Sx = width / (x1 - x0);
  double Sy = height / (y1 - y0);

  // windowing + scaling
  Matrix transformation = Matrix::Scale(Sx, Sy) * Matrix::Translate(-x0, -y0);

  // x-axis flip-flop fix
  // it needs to be on the rhs
  // because we actually want this transformation to happen first, before others
  transformation = transformation * Matrix::XFlip();

  // kinda fix
  transformation = Matrix::Translate(0, y1 * Sy) * transformation;
  transformation = Matrix::Translate(0, y0 * Sy) * transformation;
  // basically invert the blank space on the top with the one at the bottom

  // axis department
  if (_config->getShowGrid()) {
    dc.SetPen(wxPen(wxColour(255, 0, 0), 2));
    drawAxes(dc, transformation, x0, x1, y0, y1);
  }

  switch (_config->getOperatingMode()) {
    case OperatingMode::CURRENT_AND_PREVIOUS:
      if (previousData.getDataPoints().empty()) {
        break;
      }

      dc.SetPen(wxPen(wxColour(66, 135, 245), 2));

      // move_x = -previousData.getXMax();

      std::for_each(previousData.getDataPoints().begin(), previousData.getDataPoints().end() - 1, [&](const std::pair<double, double>& p) {
        line2d(dc, transformation, p, *std::next(&p));  // p is just a dereferenced iterator, so we can take its addres again, and then increment it and dereference it again :)
      });
      // fall through, no break

    case OperatingMode::CURRENT:               // Zwraca wykres tylko najnowszych danych
      dc.SetPen(wxPen(wxColour(0, 0, 0), 2));  // kolor linii

      // rysowanie linii dla ka�dego punktu w currentData
      std::for_each(currentData.getDataPoints().begin(), currentData.getDataPoints().end() - 1, [&](const std::pair<double, double>& p) {
        line2d(dc, transformation, p, *std::next(&p));  // rysuje wykres liniami 2d
      });
      break;

    case OperatingMode::CONTINUOUS:
      dc.SetPen(wxPen(wxColour(0, 0, 0), 2));

      std::for_each(historicData.getDataPoints().begin(), historicData.getDataPoints().end() - 1, [&](const std::pair<double, double>& p) {
        line2d(dc, transformation, p, *std::next(&p));
      });
      break;
  }
}

// Rysuje lini� 2d mi�dzy l
void Plotter::line2d(wxDC& dc, const Matrix& transformation, std::pair<double, double> p1, std::pair<double, double> p2) {
  Vector start{p1.first, p1.second};
  Vector end{p2.first, p2.second};

  start = transformation * start;
  end = transformation * end;

  dc.DrawLine(start.GetX(), start.GetY(), end.GetX(), end.GetY());
}

void Plotter::text2d(wxDC& dc, const Matrix& transformation, double x, double y, double alpha, double value) {
  Vector point{x, y};

  point = transformation * point;

  dc.DrawRotatedText(wxString::Format("%.2lf", value), point.GetX(), point.GetY(), alpha);
}

void Plotter::text2d(wxDC& dc, const Matrix& transformation, std::pair<double, double> point, double alpha, double value) {
  Vector _point{point.first, point.second};

  _point = transformation * _point;

  dc.DrawRotatedText(wxString::Format("%.2lf", value), _point.GetX(), _point.GetY(), alpha);
}

void Plotter::drawAxes(wxDC& dc, const Matrix& transformation, double x0, double x1, double y0, double y1, double step) {
  double width{x1 - x0};
  double height{y1 - y0};

  std::pair<double, double> startX{x0, y0};
  std::pair<double, double> stopX{x1, y0};
  std::pair<double, double> startY{x0, y0};
  std::pair<double, double> stopY{x0, y1};

  std::vector<std::pair<double, double>> xTics{};
  std::vector<std::pair<double, double>> yTics{};

  for (double dx = step; dx < 1; dx += step) {
    xTics.emplace_back(width * dx, y0);
    xTics.emplace_back(width * dx, y0 + 0.05 * height);

    yTics.emplace_back(x0, y0 + dx * height);
    yTics.emplace_back(width * 0.05, y0 + dx * height);
  }

  for (size_t i = 0; i < xTics.size(); i += 2) {
    line2d(dc, transformation, xTics[i], xTics[i + 1]);
    text2d(dc, transformation, xTics[i + 1].first - width * 0.01, xTics[i + 1].second + height * 0.04, 0.0, xTics[i].first);
    line2d(dc, transformation, yTics[i], yTics[i + 1]);
    text2d(dc, transformation, yTics[i + 1].first + width * 0.01, yTics[i + 1].second + height * 0.02, 0.0, yTics[i].second);
  }

  double dupa = xTics[1].first;
}