/* Теоретическая часть:
	1. Уровни видимости
		"+" - открытое поле - public
		"-" - закрытое поле - private
		"#" - защищенное поле - protected
	2. virtual void - виртуальная функция - "один интерфейс - множество реализаций". 
	3. override - ключевое слово для виртуальной функции, чтобы показать, что мы хотим переопределить
		её, а не скрыть
*/

#include <iostream>

using namespace std;

class Shape {
public:
//	virtual void Scale(float ScaleFactor) = 0;
	virtual void ShowInfo() = 0;
	virtual string GetName() = 0;
};

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

class Square : public Shape2D { //наследование
private:
	float side;
public:
	Square(float side);
	void CalculateArea();
	string GetName();
	void ShowInfo();
};

class Triangle : public Shape2D { //наследование
private:
	float base;
	float height;
public:
	Triangle(float base, float height);
	void CalculateArea();
	string GetName();
	void ShowInfo();
};

class Circle : public Shape2D { //наследование
private:
	float radius;
public:
	Circle(float radius);
	void CalculateArea();
	string GetName();
	void ShowInfo();
};

class TriangularPiramid : public Shape3D { //наследование
private:
	Triangle start_triangle;
	float height;
public:
	TriangularPiramid(float base, float height);
	void CalculateVolume();
	string GetName();
	void ShowInfo();
};

class Cylinder : public Shape3D { //наследование
private:
	Circle start_circle;
	float height;
public:
	Cylinder(float radius, float height);
	void CalculateVolume();
	string GetName() override;
	void ShowInfo() override;
};

class Sphere : public Shape3D { //наследование
private:
	float radius;
public:
	Sphere(float radius);
	void CalculateVolume();
	string GetName();
	void ShowInfo();
};
