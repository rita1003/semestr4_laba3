//Хочу обратить, что работа операций сравнений для 2D фигур демонстрирована только для квадратов
//и операции для 3D фигур только для сфер. Не вижу смысла расписывать работу каждой операции для
//каждой фигуры, т.к. мне необходимо лишь продемонстрировать работу этих самых операций.

#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include "TriangularPiramid.h"
#include "Cylinder.h"
#include "Sphere.h"

using namespace std;

int main() {
	int fig_type;
	int num_fig;
	float side, base, height, radius, scaleFactor;

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
				cout << endl<< "The result of operation > is " << (square.GetArea() > new_square.GetArea()) << endl;
				cout << "The result of operation < is " << (square.GetArea() < new_square.GetArea()) << endl;
				cout << "The result of opertation == is " << (square.GetArea() == new_square.GetArea()) << endl << endl;
				cout << "Testing of method Scale():" << endl;
				cout << endl << "Write a scale factor: " << endl<< endl;
				cin >> scaleFactor;
				cout << endl << "New square is: " << endl;
				new_square.Scale(scaleFactor);
				new_square.ShowInfo();
			}
			else if (num_fig == 2) {
				cout << endl << "Write base of triangle: " << endl << endl;
				cin >> base;
				cout << endl << "Write height of triangle: " << endl << endl;
				cin >> height;
				Triangle triangle(base, height);
				triangle.ShowInfo();
				cout << endl <<"Testing of method Scale():" << endl;
				cout << endl << "Write a scale factor: " << endl << endl;
				cin >> scaleFactor;
				cout << endl << "New square is: " << endl;
				triangle.Scale(scaleFactor);
				triangle.ShowInfo();
			}
			else if (num_fig == 3) {
				cout << endl << "Write radius of circle: " << endl << endl;
				cin >> radius;
				Circle circle(radius);
				circle.ShowInfo();
				cout << endl << "Testing of method Scale():" << endl;
				cout << endl << "Write a scale factor: " << endl << endl;
				cin >> scaleFactor;
				cout << endl << "New square is: " << endl;
				circle.Scale(scaleFactor);
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
				cout << endl << "Write a scale factor: " << endl << endl;
				cin >> scaleFactor;
				cout << endl << "New triangular piramid is: " << endl;
				triangular.Scale(scaleFactor);
				triangular.ShowInfo();
			}
			else if (num_fig == 2) {
				cout << endl << "Write height of cylinder: " << endl << endl;
				cin >> height;
				cout << endl << "Write radius of circle: " << endl << endl;
				cin >> radius;
				Cylinder cylin(radius, height);
				cylin.ShowInfo();
				cout << endl<< "Write a scale factor: " << endl << endl;
				cin >> scaleFactor;
				cout << endl << "New cylinder is: " << endl;
				cylin.Scale(scaleFactor);
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
				cout << endl << "Write a scale factor: " << endl << endl;
				cin >> scaleFactor;
				cout << endl << "New square is: " << endl;
				new_sphere.Scale(scaleFactor);
				new_sphere.ShowInfo();
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
