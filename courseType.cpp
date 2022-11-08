#include <string>
#include "course.h"
#include "faculty.h"
#include "dateTime.cpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Default constructor
Course::Course() {
	term ="NoTerm";
	year = 0;
	name = "NoName";
	section = "NoSection";
	id = "-1";
	meetDays = "NoMeetDays";
	location = "NoLocation";
	meetInfo = "NoMeetInfo";
	units = 0;
}


Course::~Course() {
	// todo
}

//Return the course information as a string in CSV format
string Course::getCourseInfoCSV() {
	return term + "," + to_string(year) + "," + startDate.toString() + ","
		+ endDate.toString() + "," + name + "," + section + ","
		+ id + "," + meetDays + "," + location + ","
		+ meetInfo + "," + instructor.getLastName() + "," + to_string(units);
}
//Print to console the course information in nice formatting
void Course::printCourseInfo()  {
	cout << left << setw(8) << term << setw(5) << year << setw(12) << startDate.getDate().toString() << setw(12)
		<< endDate.getDate().toString() << setw(32) << name << setw(10) << section
		<< setw(10) << id << setw(8) << meetDays << setw(10) << location
		<< setw(10) << meetInfo << setw(15) << instructor.getLastName() << endl
		<< setw(5) << units << endl;
}

bool Course::operator==(const Course& otherC) const{
	return false; // todo
}

bool Course::operator!=(const Course& otherC) const{
	return !(*this == otherC);
}

bool Course::operator>=(const Course& otherC) const{
	return !(*this < otherC);
}
bool Course::operator<=(const Course& otherC) const{
	return !(*this > otherC);
}
bool Course::operator<(const Course& otherC) const{
	return false; // todo
}
bool Course::operator>(const Course& otherC) const{
	//If not less than or equal to, must be greater than
	return !(*this < otherC || *this == otherC);
}

