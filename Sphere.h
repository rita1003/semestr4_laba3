#pragma once

#include <iostream>
#include "Shape3D.h"

using namespace std;

class Sphere : public Shape3D { //наследование
private:
	float radius;
public:
	Sphere(float radius);
	void Scale(float scaleFactor);
	void CalculateVolume();
	string GetName();
	void ShowInfo();
};

Sphere::Sphere(float radius) : radius(radius) { CalculateVolume(); }
void Sphere::CalculateVolume() { SetVolume(4 / 3 * 3.14 * radius * radius * radius); }
string Sphere::GetName() { return "Sphere"; }

void Sphere::Scale(float scaleFactor) {
	radius *= scaleFactor;
	CalculateVolume();
}

void Sphere::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My volume = " << GetVolume() << endl;
	cout << "	My radius = " << radius << endl;
}
