#include "DataLoader.h"
#include <algorithm>
#include <fstream>

// �aduje dane z pliku
void DataLoader::loadDataFromFile(const std::string& filepath, Data& current, Data& previous, Data& historic) {
  std::ifstream file(filepath);  // plik

  if (!file.good()) {
    return;
  }

  double x, y;
  Data newData{};

  while (file >> x >> y) {
    newData.addDataPoint(x, y);
  }

  size_t newSize{newData.getDataPoints().size()};
  size_t currentSize{current.getDataPoints().size()};

  if (newSize >= currentSize) {
    double historic_time_offset{historic.getDataPoints().empty() ? 0.0 : historic.getDataPoints().back().first + 0.0001};
    for (auto it = newData.getDataPoints().begin() + currentSize; it != newData.getDataPoints().end(); ++it) {
      historic.addDataPoint(it->first + historic_time_offset, it->second);
    }
  } else {
    previous = current;
  }

  current = newData;
}