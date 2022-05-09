#include "student.h"
#include <iostream>
#include <string>
using namespace std;


// Private Helpers

// setters

void Student::setStudentId(string studentId)
{
	this->studentId = studentId;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setNumDaysCompleteCourse(int numDaysCompletedCourse[])
{
	for (int i = 0; i < Student::NUM_DAYS; i++) {
			this->numDaysCompleteCourse[i] = numDaysCompleteCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreePorgram)
{
	this->degreeProgram = degreePorgram;
}

// getters

string Student::getStudentId() const
{
	return studentId;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

string Student::getEmail() const
{
	return email;
}

int Student::getAge() const
{
	return age;
}

const int* Student::getNumDaysCompleteCourse() const
{
	return numDaysCompleteCourse;
}

int Student::getNumDaysCompleteCourse(int i) const
{
	int days = 0;
	
	if (i < Student::NUM_DAYS) {
		cout << "ERROR in Student::getNumDaysCompleteCourse(int)" << endl;
		cout << "Index of " << i << " outside range. Max index = " << (Student::NUM_DAYS - 1) << endl;
	}
	else {
		days = numDaysCompleteCourse[i];
	}
	return days;
}

DegreeProgram Student::getDegreeProgram() const
{
	return degreeProgram;
}

// Constructors

Student::Student()
{
	studentId = "none";
	firstName = "none";
	lastName = "none";
	email = "none";
	age = -1;
	degreeProgram = SECURITY;

	// initialize numDaysCompleteCourse to { -1, -1, -1 }
	for (int i = 0; i < Student::NUM_DAYS; i++) {
		numDaysCompleteCourse[i] = -1;
	}
}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int numDaysCompleteCourse[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->degreeProgram = degreeProgram;

	// initialize this->numDaysCompleteCourse = numDaysCompeteCourse
	for (int i = 0; i < Student::NUM_DAYS; i++) {
		this->numDaysCompleteCourse[i] = numDaysCompleteCourse[i];
	}
}

// Public Student Operations

void Student::print() const
{
	cout << toString() << "\n";
}

string Student::toString() const {
	string out = "";
	out += studentId + "\tFirst Name: " + firstName + "\tLast Name: " + lastName += "\t";
	out += "Age: " + to_string(age) + "\tdaysInCourse: ";

	for (int i = 0; i < Student::NUM_DAYS; i++) {
		if (i == 0) {
			out += "[";
		}
		else {
			out += ", ";
		}

		out += to_string(numDaysCompleteCourse[i]);
	}
	out += "]\tDegree Program: ";

	switch (degreeProgram)
	{
	case SECURITY:
		out += "Security";
		break;
	case NETWORK:
		out += "Network";
		break;
	case SOFTWARE:
		out += "Software";
		break;
	default:
		out += "Invalid DegreeProgram";
		break;
	}

	return out;
}

bool Student::hasValidEmail() const
{
	bool valid = true;

	// If '@' NOT found in email, set valid = false
	if (email.find('@') == string::npos) {
		valid = false;
	}

	// If '.' NOT found in email, set valid = false
	if (email.find('.') == string::npos) {
		valid = false;
	}

	// If ' ' IS found in email, set valid = false
	if (email.find(' ') != string::npos) {
		valid = false;
	}

	return valid;
}

double Student::averageDaysInCourse() const
{
	int sum = 0;

	for (int i = 0; i < Student::NUM_DAYS; i++)
	{
		sum += numDaysCompleteCourse[i];
	}

	return static_cast<double>(sum) / Student::NUM_DAYS;
}


