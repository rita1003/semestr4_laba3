#pragma once

#include <iostream>
#include "Shape3D.h"
#include "Circle.h"

using namespace std;

class Cylinder : public Shape3D { //наследование
private:
	Circle start_circle;
	float height;
public:
	Cylinder(float radius, float height);
	void Scale(float scaleFactor);
	void CalculateVolume();
	string GetName();
	void ShowInfo();
};

Cylinder::Cylinder(float radius, float height) : start_circle(radius), height(height) {
	CalculateVolume();
}
void Cylinder::CalculateVolume() { SetVolume(3.14 * height * start_circle.GetArea()); }
string Cylinder::GetName() { return "Cylinder"; }

void Cylinder::Scale(float scaleFactor) {
	start_circle.Scale(scaleFactor);
	height *= scaleFactor;
	CalculateVolume();
}

void Cylinder::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My volume = " << GetVolume() << endl;
	cout << "	My height = " << height << endl;
}