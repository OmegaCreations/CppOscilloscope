#include "Data.h"
#include <limits>

// konstruktor
Data::Data()
    // wykorzystanie limit�w do ograniczenia maksim�w i minim�w
    : x_min(std::numeric_limits<double>::max()),
      x_max(std::numeric_limits<double>::min()),
      y_min(std::numeric_limits<double>::max()),
      y_max(std::numeric_limits<double>::min()),
      data_points{} {}


// dodawanie nowego punktu do danych
void Data::addDataPoint(double x, double y) {
  data_points.emplace_back(x, y);
  updateMinMax(x, y);
}

void Data::addDataPoint(const std::pair<double, double>& point) {
  data_points.push_back(point);
  updateMinMax(point.first, point.second);
}

// aktualizacja minim�w i maksim�w
void Data::updateMinMax(double x, double y) {
  x_min = std::min(x_min, x);
  x_max = std::max(x_max, x);
  y_min = std::min(y_min, y);
  y_max = std::max(y_max, y);
}

// zwracanie wektora par
const std::vector<std::pair<double, double>>& Data::getDataPoints() const {
  return data_points;
}

// gettery minim�w i maksim�w
double Data::getXMin() const {
  return x_min;
}

double Data::getXMax() const {
  return x_max;
}

double Data::getYMin() const {
  return y_min;
}

double Data::getYMax() const {
  return y_max;
}

// operatory
bool Data::operator==(const Data& other) const {
  return data_points == other.data_points;
}

bool Data::operator!=(const Data& other) const {
  return !(*this == other);
}

void Data::clear() {
  data_points.clear();
  x_min = std::numeric_limits<double>::max();
  x_max = std::numeric_limits<double>::min();
  y_min = std::numeric_limits<double>::max();
  y_max = std::numeric_limits<double>::min();
}
