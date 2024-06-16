#ifndef CONFIG_H
#define CONFIG_H

#include <string>

enum class OperatingMode { CURRENT,
                           CURRENT_AND_PREVIOUS,
                           CONTINUOUS };

enum class DrawStyle { LINE,
                       INTERPOLATED_LINE,
                       BARS };

class Config {
 private:
  OperatingMode _operatingMode;
  DrawStyle _drawStyle;
  bool _showGrid;
  std::string _filepath;

 public:
  Config(OperatingMode operatingMode = OperatingMode::CURRENT,
         DrawStyle drawStyle = DrawStyle::LINE,
         bool showGrid = false,
         const std::string& filepath = "");

  OperatingMode getOperatingMode() const;
  void setOperatingMode(OperatingMode operatingMode);

  DrawStyle getDrawStyle() const;
  void setDrawStyle(DrawStyle drawStyle);

  bool getShowGrid() const;
  void setShowGrid(bool showGrid);

  std::string getFilepath() const;
  void setFilepath(const std::string& filepath);
};

#endif /* CONFIG_H */
