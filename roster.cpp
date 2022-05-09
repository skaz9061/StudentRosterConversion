#include "roster.h"
#include "student.h"
#include "degree.h"
#include <sstream>
#include <iostream>
using namespace std;

// Constructors

Roster::Roster()
{
	numStudents = 0;
	for (int i = 0; i < Roster::ORIG_NUM_STUDENTS; i++)
	{
		classRosterArray[i] = nullptr;
	}
}

// CRUD and Accessors

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int numDaysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[numStudents++] = new Student(studentId, firstName, lastName, emailAddress, age, numDaysInCourse, degreeProgram);
}

void Roster::remove(string studentId)
{
	int rmIndex = findIndexByStudentId(studentId);

	if (rmIndex < 0) {
		cout << "ERROR: no student found with student id " << studentId << endl;
	}
	else {
		const int len = --numStudents;

		delete classRosterArray[rmIndex];

		for (int i = rmIndex; i < len; i++)
		{
			classRosterArray[i] = classRosterArray[i + 1];
		}

		classRosterArray[len] = nullptr;
	}
}

int Roster::getNumStudents() const
{
	return numStudents;
}

// Returns a pointer to the student at index i, if i < numStudents.
// Returns nullptr if outside of range.
Student* Roster::getStudent(int i) const
{
	if (i < numStudents) {
		return classRosterArray[i];
	}
	else {
		return nullptr;
	}
}

// print Methods

void Roster::printAll() const
{
	for (int i = 0; i < numStudents; i++)
	{
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentId) const
{
	cout << studentId << " average days in course:\t" << (*findByStudentId(studentId)).averageDaysInCourse() << "\n";
}

void Roster::printInvalidEmails() const
{
	for (int i = 0; i < numStudents; i++)
	{
		if (!classRosterArray[i]->hasValidEmail()) {
			cout << classRosterArray[i]->getEmail() << "\n";
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const
{
	Student* current = nullptr;

	for (int i = 0; i < numStudents; i++)
	{
		current = classRosterArray[i];
		if (current->getDegreeProgram() == degreeProgram) {
			current->print();
		}
	}
}

// Public Operations

DegreeProgram Roster::stringToDegreeProgram(string degreeProgram)
{
	if (degreeProgram == "SECURITY") {
		return SECURITY;
	}
	else if (degreeProgram == "NETWORK") {
		return NETWORK;
	}
	else {
		return SOFTWARE;
	}
}

// Private Helpers

int Roster::findIndexByStudentId(string studentId) const
{
	int index = -1;
	
	for (int i = 0; i < numStudents; i++)
	{
		if (classRosterArray[i]->getStudentId() == studentId) {
			index = i;
			break;
		}
	}
	return index;
}

Student* Roster::findByStudentId(string studentId) const
{
	int i = findIndexByStudentId(studentId);

	if (i < 0) {
		// Returns nullptr if not found
		return nullptr;
	}
	else {
		return classRosterArray[i];
	}
}
