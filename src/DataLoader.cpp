#include "DataLoader.h"
#include <fstream>

// �aduje dane z pliku
void DataLoader::loadDataFromFile(const std::string& filepath, Data& current, Data& previous, Data& historic) {

    std::ifstream file(filepath); // plik

    if (!file.good()) {
        return;
    }

    double x, y;
    if (current.getDataPoints().size() == 0) {
        current.addDataPoint(0, 0);
    }

    Data newData; // tymczasowa zmienna nowych danych
    bool isNew = false; // flaga sprawdzaj�ca czy wczytujemy nowe dane
    while (file >> x >> y) {
        // sprawdzamy czy kolejne dane kt�re zczytujemy posiadaj� nowy przedzia� czasowy
        if (x < (*(current.getDataPoints().end()-1)).first && !isNew) {
            isNew = true;
        }

        // zczytywanie nowych par punkt�w
        if (!isNew) {
            current.addDataPoint(x, y);
        }
        else {
            newData.addDataPoint(x, y);
        }
    }

    if (newData.getDataPoints().size() > 0) {

        // przepisanie nowych danych do ca�ej historii punkt�w
        for (const auto& point : newData.getDataPoints()) {
            historic.addDataPoint(point.first, point.second);
        }

        previous = current; // poprzednie punkty to by�e aktualne
        current = newData; // aktualne to nowo za�adowane
    }
  
}