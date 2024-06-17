#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include "Data.h"

class DataLoader {
 public:
  static void loadDataFromFile(const std::string& filepath, Data& current, Data& previous, Data& historic);
};

#endif /* DATALOADER_H */
