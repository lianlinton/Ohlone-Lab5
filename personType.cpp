#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"

using namespace std;


//Constructor
Person::Person(int id, string f, string l, string a, string c,
		string s, string z, string p, string e){
	this->id = id;
	firstName = f;
	lastName = l;
	address = a;
	city = c;
	state = s;
	zip = z;
	phone = p;
	email = e;
}
//Copy constructor
Person::Person(const Person& otherObject){
	id = otherObject.getId();
	firstName = otherObject.getFirstName();
	lastName = otherObject.getLastName();
	address = otherObject.getAddress();
	city = otherObject.getCity();
	state = otherObject.getState();
	zip = otherObject.getZip();
	phone = otherObject.getPhone();
	email = otherObject.getEmail();
}