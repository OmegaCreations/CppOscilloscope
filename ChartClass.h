#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include <string>
#include "ConfigClass.h"
#include "Buffer.h"

class Matrix;

class ChartClass
{
private:
	static void DrawLine2d(wxDC* dc, Matrix t, double x1, double y1, double x2, double y2);
	static void DrawTxt(wxDC* dc, Matrix t, double alpha, double x, double y, double value);
	static Matrix GetRotationMatrix(double alpha);
	static Matrix GetTranslationMatrix(double dx, double dy);
	static Matrix GetScaleMatrix(double w, double h, double x0, double x1, double y0, double y1);

private:
	std::shared_ptr<ConfigClass> cfg;
	int x_step;
	double x_min, x_max; // zakresy
	double y_min, y_max;

public:
	ChartClass(std::shared_ptr<ConfigClass> c);

public: // Public methods
	void Set_Range(const Buffer::TimeValueMap& dataMap); // ustala wartosci przedzialow
	double Get_Y_min(); // zwraca y_min
	double Get_Y_max(); // zwraca y_max
	void Draw(wxDC* dc, int w, int h); // rysuje wykres
};

#endif
