#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>



// klasa przechowujaca wszystkie zaladowane funkcje
class Buffer {

public:

    using TimeValueMap = std::map<double, double>; // mapa czas-wartosc
    using ChartMap = std::map<std::string, TimeValueMap>; // mapa roznych przebiegow
    static ChartMap _chartData; // zainicjalizowana mapa wykresow
    
    
    // funkcja zczytuj¹ca punkty z pliku
    static bool readDataFromFile(const std::string& filename, const std::string& chartName) {
        
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Nie udalo sie otworzyc pliku: " << filename << std::endl;
            return false;
        }

        // dane
        double time, value;
        TimeValueMap dataMap;
        
        // zapisywanie danych
        while (file >> time >> value) {
            dataMap[time] = value;
        }

        file.close();

        // nazwa wykresu mo¿e byæ ustalana odgórnie b¹dŸ statycznie liczona
        Buffer::_chartData[chartName] = dataMap;
        
        
        return true;
    }

    // zwrócenie wartoœci x_start, x_stop, y_min, y_max dla ChartClass.cpp
    static std::tuple<double, double, double, double> getChartLimits(const std::string& chartName) {
        
        auto it = Buffer::_chartData.find(chartName);
        if (it == Buffer::_chartData.end()) {
            return { 0, 0, 0, 0 }; // no data
        }

        const TimeValueMap& dataMap = it->second;
        if (dataMap.empty()) {
            return { 0, 0, 0, 0 }; // no data
        }

        // limity x (czasu)
        double x_start = dataMap.begin()->first;
        double x_stop = dataMap.rbegin()->first;
        
        // zliczanie maxymalnej i minimalnej wartosci
        double y_min = std::numeric_limits<double>::max(); // wartosc max double
        double y_max = std::numeric_limits<double>::min(); // wartosc min double

        for (const auto& entry : dataMap) {
            if (entry.second < y_min) y_min = entry.second;
            if (entry.second > y_max) y_max = entry.second;
        }

        return { x_start, x_stop, y_min, y_max };
    }
};