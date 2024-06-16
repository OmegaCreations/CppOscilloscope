#include "DataLoader.h"
#include <fstream>

void DataLoader::loadDataFromFile(const std::string& filepath, Data& current, Data& previous, Data& historic) {
  Data newData;
  std::ifstream file(filepath);

  if (!file.good()) {
    return;
  }

  double x, y;
  while (file >> x >> y) {
    newData.addDataPoint(x, y);
  }

  if (newData != current) {
    previous = current;
    current = newData;

    for (const auto& point : newData.getDataPoints()) {
      historic.addDataPoint(point.first, point.second);
    }
  }
}