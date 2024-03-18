#pragma once

#include<iostream>
#include"Shape2D.h"

using namespace std;

class Triangle : public Shape2D { //наследование
private:
	float base;
	float height;
public:
	Triangle(float base, float height);
	void Scale(float scaleFactor);
	void CalculateArea();
	string GetName();
	void ShowInfo();
}; 

Triangle::Triangle(float base, float height) : base(base), height(height) { CalculateArea(); }
void Triangle::CalculateArea() { SetArea(0.5 * base * height); }
string Triangle::GetName() { return "Triangle"; }

void Triangle::Scale(float scaleFactor) {
	base *= scaleFactor;
	height *= scaleFactor;
	CalculateArea();
}

void Triangle::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My area = " << GetArea() << endl;
	cout << "	My base = " << base << endl;
	cout << "	My height = " << height << endl;
}
