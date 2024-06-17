#ifndef PLOTTER_H
#define PLOTTER_H

#include <wx/dc.h>
#include <memory>
#include "Config.h"
#include "Data.h"
#include "VecMat.h"

class Plotter {
 private:
  std::shared_ptr<Config> _config;

  void line2d(wxDC& dc, const Matrix& transformation, std::pair<double, double> p1, std::pair<double, double> p2);

  public:
  Plotter(std::shared_ptr<Config> config);
  void draw(wxDC& dc, const Data& currentData, const Data& previousData, const Data& historicData);
  void drawAxes(wxDC& dc, const Data& currentData, double x0, double x1, double y0, double y1);
};

#endif /* PLOTTER_H */
