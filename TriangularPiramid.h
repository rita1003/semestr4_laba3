#pragma once

#include <iostream>
#include "Shape3D.h"
#include "Triangle.h"

using namespace std;

class TriangularPiramid : public Shape3D { //наследование
private:
	Triangle start_triangle;
	float height;
public:
	TriangularPiramid(float base, float height);
	void Scale(float scaleFactor);
	void CalculateVolume();
	string GetName();
	void ShowInfo();
};

TriangularPiramid::TriangularPiramid(float base, float height) : start_triangle(base, height), height(height) {
	CalculateVolume();
}
void TriangularPiramid::CalculateVolume() { SetVolume((1.0f / 3.0f) * height * start_triangle.GetArea()); }
string TriangularPiramid::GetName() { return "Triangular Piramid"; }

void TriangularPiramid::Scale(float scaleFactor) {
	start_triangle.Scale(scaleFactor);
	height *= scaleFactor;
	CalculateVolume();
}

void TriangularPiramid::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My volume = " << GetVolume() << endl;
	cout << "	My height = " << height << endl;
}