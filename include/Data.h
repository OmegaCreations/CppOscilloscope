#ifndef DATA_H
#define DATA_H

#include <utility>
#include <vector>

class Data {
 private:
  std::vector<std::pair<double, double>> data_points;
  double x_min, x_max, y_min, y_max;

  void updateMinMax(double x, double y);

 public:
  Data();
  void addDataPoint(double x, double y);

  const std::vector<std::pair<double, double>>& getDataPoints() const;
  double getXMin() const;
  double getXMax() const;
  double getYMin() const;
  double getYMax() const;

  bool operator==(const Data& other) const;
  bool operator!=(const Data& other) const;
};

#endif /* DATA_H */
