#include "Config.h"

Config::Config(OperatingMode operatingMode, DrawStyle drawStyle, bool showGrid, const std::string& filepath)
    : _operatingMode(operatingMode), _drawStyle(drawStyle), _showGrid(showGrid), _filepath(filepath) {}

OperatingMode Config::getOperatingMode() const {
  return _operatingMode;
}

void Config::setOperatingMode(OperatingMode operatingMode) {
  _operatingMode = operatingMode;
}

DrawStyle Config::getDrawStyle() const {
  return _drawStyle;
}

void Config::setDrawStyle(DrawStyle drawStyle) {
  _drawStyle = drawStyle;
}

bool Config::getShowGrid() const {
  return _showGrid;
}

void Config::setShowGrid(bool showGrid) {
  _showGrid = showGrid;
}

std::string Config::getFilepath() const {
  return _filepath;
}

void Config::setFilepath(const std::string& filepath) {
  _filepath = filepath;
}