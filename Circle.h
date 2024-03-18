#pragma once

#include <iostream>
#include "Shape2D.h"

using namespace std;

class Circle : public Shape2D { //наследование
private:
	float radius;
public:
	Circle(float radius);
	void Scale(float scaleFactor);
	void CalculateArea();
	string GetName();
	void ShowInfo();
};

Circle::Circle(float radius) : radius(radius) { CalculateArea(); }
void Circle::CalculateArea() { SetArea(3.14 * radius * radius); }
string Circle::GetName() { return "Circle"; }

void Circle::Scale(float scaleFactor) {
	radius *= scaleFactor;
	CalculateArea();
}

void Circle::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My area = " << GetArea() << endl;
	cout << "	My radius = " << radius << endl;
}
