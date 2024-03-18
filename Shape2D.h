#pragma once

#include <iostream>
#include "Shape.h"

using namespace std;

class Shape2D : public Shape { //наследование
private:
	float area = 0;
	virtual void CalculateArea() = 0;
public:
	float GetArea();
	void SetArea(float a);
	bool operator >(const Shape2D& other) {
		return area > other.area;
	};
	bool operator <(const Shape2D& other) {
		return area < other.area;
	};
	bool operator ==(const Shape2D& other) {
		return area == other.area;
	};
};

float Shape2D::GetArea() { return area; };
void Shape2D::SetArea(float a) { area = a; }