#pragma once
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster
{
public:
	// Public Constants
	static const int ORIG_NUM_STUDENTS = 5;

	// Constructors
	Roster();
	Roster(const string rawData[]);

	// CRUD
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentId);
	int getNumStudents() const;
	Student* getStudent(int i) const;

	// print Methods
	void printAll() const;
	void printAverageDaysInCourse(string studentId) const;
	void printInvalidEmails() const;
	void printByDegreeProgram(DegreeProgram degreeProgram) const;

	// Public Operations
	static DegreeProgram stringToDegreeProgram(string degreeProgram);

private:
	// Member Variables
	int numStudents;
	Student* classRosterArray[ORIG_NUM_STUDENTS];

	// Private Helpers
	Student* parseString(string s);
	Student* findByStudentId(string studentId) const;
	int findIndexByStudentId(string studentId) const;
};

