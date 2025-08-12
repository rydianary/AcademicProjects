#include <iostream>

using namespace std;
Vehicle::Vehicle() :Vehicle(4) {
cout << "In constructor with 0 Parameters" << endl;
}
Vehicle::Vehicle(int w) : Vehicle(4, w) {
cout << "In constructor with 1 Parameters,wheels" << w << endl;
}
Vehicle::Vehicle(int w, int d) {
numWheels = w;
numDoors = d;
cout << "In constructor with 2 Parameters" << endl;
}
Vehicle::Vehicle(Vehicle& v) :Vehicle(v.numWheels, v.numDoors) {
cout << "In copy constructor through reference" << endl;
}
Vehicle::Vehicle(Vehicle* v) : Vehicle(v->numWheels, v->numDoors) {
cout << "In copy constructor through pointer" << endl;

}
void Vehicle::printVehicle() {
cout << "Vehicle Details:" << endl;
cout << "Wheels :" << numWheels << endl;
cout << "Doors :" << numDoors << endl;
}

Vehicle & Vehicle::operator =(const Vehicle & v)
{
numDoors = v.numDoors;
numWheels = v.numWheels;
return *this;
}


// returns true if numDoors and numWheels are equal
bool Vehicle::operator ==(const Vehicle & v)
{
return numDoors == v.numDoors && numWheels == v.numWheels;
}


// returns true if numDooor or numWheels is not equal
bool Vehicle::operator !=(const Vehicle & v)
{
return !(*this == v);
}


// increments the numDoors and numWheels by 1 and returns the new values
Vehicle& Vehicle::operator ++()
{
numDoors += 1;
numWheels += 1;
return *this;
}

// increments the numDoors and numWheels by 1 but returns the old value
Vehicle Vehicle::operator ++(int i)
{
Vehicle v = *this;
numDoors += 1;
numWheels += 1;
return v;
}

// decrements the numDoors and numWheels by 1 and returns the new values
Vehicle& Vehicle::operator --()
{
numDoors -= 1;
numWheels -= 1;
return *this;
}

// decrements the numDoors and numWheels by 1 but returns the old value
Vehicle Vehicle::operator --(int i)
{
Vehicle v = *this;
numDoors -= 1;
numWheels -= 1;
return v;
}

// writes the numWheels and numDoors to output stream
ostream & operator <<(ostream & out, const Vehicle & v)
{
out << "Vehicle Details (";
out << "Wheels: " << v.numWheels << ", ";
out << "Doors: " << v.numDoors << ")";
return out;
}

Vehicle.h:

#ifndef Vehicle_h
#define Vehicle_h
class Vehicle {
int numWheels;
int numDoors;
public:
Vehicle();
Vehicle(int w);
Vehicle(int w, int d);
Vehicle(Vehicle& v);
Vehicle(Vehicle* v);
void printVehicle();
~Vehicle();
Vehicle& operator = (const Vehicle& v);
bool operator == (const Vehicle& v);
bool operator != (const Vehicle& v);
Vehicle& operator ++(); // prefix increment
Vehicle operator ++(int i); // postfix increment
Vehicle& operator --(); // prefix decrement
Vehicle operator --(int i); // postfix decrement
friend std::ostream& operator << (std::ostream& out, const Vehicle& v);
};
#endif

week2.cpp (Main):

#include <iostream>

using namespace std;

void CreateVehicle(Vehicle& v, int w = 4, int d = 2)
{
v = Vehicle(w, d);
cout << "CreateVehicle function called" << endl;
}

int main(int argc, char** argv)
{
Vehicle original;
Vehicle copy(original);

cout << "Original is: " << original << " copy is: " << copy << endl;

cout << "Increment original: " << original++ << endl;
cout << "Increment copy: " << ++copy << endl;

cout << "Decrement original: " << --original << endl;
cout << "Decrement copy: " << copy-- << endl;

// should be true
cout << "Compare equality 1: " << (original == copy) << endl;

// should be false
cout << "Compare equality 2: " << (--original == ++copy) << endl;

// should be true
cout << "Compare inequality: " << (original != copy) << endl;

cout << "Assignment operator: " << (original = copy) << endl;
return 0;
}
