#include <iostream> 

using namespace std;

class Circle {

private:
	int x_axis;
	int y_axis;
	float radius;
	const double pi = 3.14159;

public:
	// mutator
	void set_x_axis(int x) {
		if (x >= -50 && x <= 50) {
			x_axis = x;
		}
		else {
			x_axis = 0;
		}
	}
	void set_y_axis(int y) {
		if (y >= -50 && y <= 50) {
			y_axis = y;
		}
		else {
			y_axis = 0;
		}
	}
	void set_radius(float r) {
		if (r >= 1 && r <= 10) {
			radius = r;
		}
		else {
			radius = 5;
		}
	}
	
	// accessor 
	int get_x_axis() {
		return x_axis;
	}
	int get_y_axis() {
		return y_axis;
	}
	float get_radius() {
		return radius;
	}
	double get_pi() {
		return pi;
	}
	// constructor
	Circle(int x, int y, float r) {
		set_x_axis(x);
		set_y_axis(y);
		set_radius(r);
	}

	Circle(int x, int y) {
		set_x_axis(x);
		set_x_axis(y);
		radius = 5;
	}

	Circle(int x, float r) {
		set_x_axis(x);
		set_radius(r);
		y_axis = 0;
	}
	// default constructor
	Circle() {
		x_axis = 0;
		y_axis = 0;
		radius = 5;
	}
	// copy constructor
	Circle(const Circle &obj) {
		x_axis = obj.x_axis;
		y_axis = obj.y_axis;
		radius = obj.radius;
	}
	// destructor
	~Circle() {
		cout << "Destructor executed..." << endl;
	}

	// member function
	void set_Circle(int x, int y, float r) {
		set_x_axis(x);
		set_y_axis(y);
		set_radius(r);
	}
	void get_Circle() {
		cout << "enter value of x axis : ";
		cin >> x_axis;
		cout << "enter value of y axis : ";
		cin >> y_axis;
		cout << "enter radius of Circle : ";
		cin >> radius;
		set_x_axis(x_axis);
		set_y_axis(y_axis);
		set_radius(radius);
	}
	void put_Circle() {
		cout << "value of x      : " << x_axis << endl;
		cout << "value of y      : " << y_axis << endl;
		cout << "value of radius : " << radius << endl;
		cout << "value of PI     : " << pi << endl;
	}

	float get_Area() {
		return ((float)pi * (radius * radius));
	}
	float get_diameter() {
		return (radius * 2);
	}

	float get_Circumference() {
		return (2 * (((float)pi) * radius));
	}

	Circle add_Circle(const Circle &obj) {
		Circle temp;
		temp.x_axis = this->x_axis + obj.x_axis;
		temp.y_axis = this->y_axis + obj.y_axis;
		temp.radius = this->radius + obj.radius;
		return temp;
	}

	bool is_equal(const Circle &obj) {
		if (this->x_axis == obj.x_axis && this->y_axis == obj.y_axis && this->radius == obj.radius) {
			return true;
		}
		return false;
	}

	int find_Circle(Circle array[], int size) {
		for (int i = 0; i < size; i++) {
			if (this->is_equal(array[i])) {
				return i;
			}
		}
		return -1;
	}

	void update_object(Circle array[], int size) {
		for (int i = 0; i < size; i++) {
			if (this->x_axis == array[i].x_axis && this->y_axis == array[i].y_axis) {
				array[i].radius = this->radius;
			}
		}
	}
};

int main() {
    // just for checking 
	Circle obj1(6, 5, 3), obj2(6, 5, 3);
	Circle array[5];
	obj1.put_Circle();
    cout << endl;
    cout << endl;
	obj2.put_Circle();
	cout << endl;
	cout << endl;
	obj1.add_Circle(obj2).put_Circle();
	Circle obj3;
    cout << endl;
	obj3.get_Circle();
    cout << endl;
    cout << endl;
    obj3.put_Circle();
	return 0;
}