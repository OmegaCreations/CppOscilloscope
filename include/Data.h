#ifndef DATA_H
#define DATA_H

#include <utility>
#include <vector>

class Data {
 private:
  std::vector<std::pair<double, double>> data_points; // zbiór wspó³rzêdnych za³adowanych punktów
  double x_min, x_max, y_min, y_max; // wartoœci minimalne i maksymalne danych

  void updateMinMax(double x, double y); // aktualizuje maksima i minima globalne dla przedzia³u czasowego

 public:
  // konstruktor
  Data();

  // dodaje punkt
  void addDataPoint(double x, double y);

  // zwraca wszystkie za³adowane punkty
  const std::vector<std::pair<double, double>>& getDataPoints() const;

  // gettery maksimów i minimów
  double getXMin() const;
  double getXMax() const;
  double getYMin() const;
  double getYMax() const;

  // operatory
  bool operator==(const Data& other) const;
  bool operator!=(const Data& other) const;
};

#endif /* DATA_H */
