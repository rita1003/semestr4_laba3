#pragma once

#include <iostream>
#include "Shape.h"

using namespace std;

class Shape3D : public Shape { //наследование
private:
	float volume = 0;
	virtual void CalculateVolume() = 0;
public:
	float GetVolume();
	void SetVolume(float a);
	bool operator >(const Shape3D& other) {
		return volume > other.volume;
	};
	bool operator <(const Shape3D& other) {
		return volume < other.volume;
	};
	bool operator ==(const Shape3D& other) {
		return volume == other.volume;
	};
};

float Shape3D::GetVolume() { return volume; };
void Shape3D::SetVolume(float a) { volume = a; }