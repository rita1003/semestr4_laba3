//Хочу обратить, что работа операций сравнений для 2D фигур демонстрирована только для квадратов
//и операции для 3D фигур только для сфер. Не вижу смысла расписывать работу каждой операции для
//каждой фигуры, т.к. мне необходимо лишь продемонстрировать работу этих самых операций.

#include <iostream>
#include "header.h"

using namespace std;

//Для Shape2D:

float Shape2D::GetArea() { return area; };
void Shape2D::SetArea(float a) { area = a; }

//Для Shape3D:
float Shape3D::GetVolume() { return volume; };
void Shape3D::SetVolume(float a) { volume = a; }


//Для Square:

Square::Square(float side) : side(side) { CalculateArea(); }
void Square::CalculateArea() {SetArea(side * side);}
string Square::GetName() {return "Square";}

void Square::ShowInfo() {
	cout << endl<< "I am a " << GetName() << "!" << endl;
	cout << "	My area = " << GetArea() << endl;
	cout << "	My side = " << side << endl;
}

//Для Triangle:

Triangle::Triangle(float base, float height) : base(base), height(height) { CalculateArea(); }
void Triangle::CalculateArea() { SetArea(0.5 * base * height); }
string Triangle::GetName() { return "Triangle"; }

void Triangle::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My area = " << GetArea() << endl;
	cout << "	My base = " << base << endl;
	cout << "	My height = " << height << endl;
}

//Для Circle:

Circle::Circle(float radius) : radius(radius) { CalculateArea(); }
void Circle::CalculateArea() { SetArea(3.14 * radius * radius); }
string Circle::GetName() { return "Circle"; }

void Circle::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My area = " << GetArea() << endl;
	cout << "	My radius = " << radius << endl;
}

//Для Sphere:

Sphere::Sphere(float radius) : radius(radius) { CalculateVolume(); }
void Sphere::CalculateVolume() { SetVolume(4/3 * 3.14 * radius * radius * radius); }
string Sphere::GetName() { return "Sphere"; }

void Sphere::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My volume = " << GetVolume() << endl;
	cout << "	My radius = " << radius << endl;
}

//Для TriangularPiramid:

TriangularPiramid::TriangularPiramid(float base, float height) : start_triangle(base, height), height(height) {
	CalculateVolume();
}
void TriangularPiramid::CalculateVolume() { SetVolume((1.0f / 3.0f) * height * start_triangle.GetArea()); }
string TriangularPiramid::GetName() { return "Triangular Piramid"; }

void TriangularPiramid::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My volume = " << GetVolume() << endl;
	cout << "	My height = " << height << endl;
}

//Для Cylinder:

Cylinder::Cylinder(float radius, float height) : start_circle(radius), height(height) {
	CalculateVolume();
}
void Cylinder::CalculateVolume() { SetVolume(3.14 * height * start_circle.GetArea()); }
string Cylinder::GetName() { return "Cylinder"; }

void Cylinder::ShowInfo() {
	cout << endl << "I am a " << GetName() << "!" << endl;
	cout << "	My volume = " << GetVolume() << endl;
	cout << "	My height = " << height << endl;
}


int main() {
	int fig_type;
	int num_fig;
	float side, base, height, radius;

	cout << "Hello! There are 2 different type of figures." << endl << endl << "Choose:" << endl;
	cout << "1. Shape 2D" << endl;
	cout << "2. Shape 3D" << endl << endl;
	cin >> fig_type;
	if ((fig_type == 1) or (fig_type == 2)) {
		cout << endl<< "Very Well! Choose figure: " << endl;
		if (fig_type == 1) {
			cout << "1. Square" << endl;
			cout << "2. Triangle" << endl;
			cout << "3. Circle" << endl << endl;
			cin >> num_fig;
			if (num_fig == 1) {
				cout << endl << "Write side of square: " << endl << endl;
				cin >> side;
				Square square (side);
				square.ShowInfo();
				cout << endl << "Very good! Now let's check the comparison operations. Let's take another square" << endl;
				cout << "Write side of new square: " << endl << endl;
				cin >> side;
				Square new_square(side);
				new_square.ShowInfo();
				cout << "The result of operation > is " << (square.GetArea() > new_square.GetArea()) << endl;
				cout << "The result of operation < is " << (square.GetArea() < new_square.GetArea()) << endl;
				cout << "The result of opertation == is " << (square.GetArea() == new_square.GetArea()) << endl;
			}
			else if (num_fig == 2) {
				cout << endl << "Write base of triangle: " << endl << endl;
				cin >> base;
				cout << endl << "Write height of triangle: " << endl << endl;
				cin >> height;
				Triangle triangle(base, height);
				triangle.ShowInfo();
			}
			else if (num_fig == 3) {
				cout << endl << "Write radius of circle: " << endl << endl;
				cin >> radius;
				Circle circle(radius);
				circle.ShowInfo();
			}
			else {
				cout << endl << "ERROR" << endl;
			}
		}
		else if (fig_type == 2) {
			cout << "1. Triangular Piramid" << endl;
			cout << "2. Cylinder" << endl;
			cout << "3. Sphere" << endl << endl;
			cin >> num_fig;
			if (num_fig == 1) {
				cout << endl << "Write height of triangualar piramid: " << endl << endl;
				cin >> height;
				cout << endl << "Write base of triangle: " << endl << endl;
				cin >> base;
				TriangularPiramid triangular(base, height);
				triangular.ShowInfo();
			}
			else if (num_fig == 2) {
				cout << endl << "Write height of cylinder: " << endl << endl;
				cin >> height;
				cout << endl << "Write radius of circle: " << endl << endl;
				cin >> radius;
				Cylinder cylin(radius, height);
				cylin.ShowInfo();

			}
			else if (num_fig == 3) {
				cout << endl << "Write radius of sphere: " << endl << endl;
				cin >> radius;
				Sphere sphere(radius);
				sphere.ShowInfo();
				cout << endl << "Very good! Now let's check the comparison operations. Let's take another sphere" << endl;
				cout << "Write radius of new sphere: " << endl << endl;
				cin >> radius;
				Sphere new_sphere(radius);
				new_sphere.ShowInfo();
				cout << "The result of operation > is " << (sphere.GetVolume() > new_sphere.GetVolume()) << endl;
				cout << "The result of operation < is " << (sphere.GetVolume() < new_sphere.GetVolume()) << endl;
				cout << "The result of opertation == is " << (sphere.GetVolume() == new_sphere.GetVolume()) << endl;
			}
			else {
				cout << endl << "ERROR" << endl;
			}
		}
	}
	else
		cout << endl << "ERROR" << endl;

	return 0;
}
