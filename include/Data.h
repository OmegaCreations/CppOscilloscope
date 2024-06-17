#ifndef DATA_H
#define DATA_H

#include <utility>
#include <vector>

class Data {
 private:
  std::vector<std::pair<double, double>> data_points;  // zbi�r wsp�rz�dnych za�adowanych punkt�w
  double x_min, x_max, y_min, y_max;                   // warto�ci minimalne i maksymalne danych

  void updateMinMax(double x, double y);  // aktualizuje maksima i minima globalne dla przedzia�u czasowego

 public:
  // konstruktor
  Data();

  // dodaje punkt
  void addDataPoint(double x, double y);
  void addDataPoint(const std::pair<double, double>& point);

  // zwraca wszystkie za�adowane punkty
  const std::vector<std::pair<double, double>>& getDataPoints() const;

  // gettery maksim�w i minim�w
  double getXMin() const;
  double getXMax() const;
  double getYMin() const;
  double getYMax() const;

  // operatory
  bool operator==(const Data& other) const;
  bool operator!=(const Data& other) const;

  void clear();
};

#endif /* DATA_H */
