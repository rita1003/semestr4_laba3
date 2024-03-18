#pragma once

#include <iostream>;

using namespace std;

class Shape {
public:
	virtual void Scale(float ScaleFactor) = 0;
	virtual void ShowInfo() = 0;
	virtual string GetName() = 0;
};
