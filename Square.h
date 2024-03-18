#pragma once

#include <iostream>
#include "Shape2D.h"

using namespace std;

class Square : public Shape2D { //наследование
private:
	float side;
public:
	Square(float side);
	void Scale(float scaleFactor);
	void CalculateArea();
	string GetName();
	void ShowInfo();
};

Square::Square(float side) : side(side) { CalculateArea(); }
void Square::CalculateArea() { SetArea(side * side); }
string Square::GetName() { return "Square"; }

void Square::Scale(float scaleFactor) {
	side *= scaleFactor;
	CalculateArea();
}

void Square::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My area = " << GetArea() << endl;
	cout << "	My side = " << side << endl;
}
