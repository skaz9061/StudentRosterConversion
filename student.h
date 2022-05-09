#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:	
	// Constants
	static const int NUM_DAYS = 3;

	// setters
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDaysCompleteCourse(int numDaysCompletedCourse[]);
	void setDegreeProgram(DegreeProgram degreePorgram);

	// getters
	string getStudentId() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	int getAge() const;
	const int* getNumDaysCompleteCourse() const;
	int getNumDaysCompleteCourse(int i) const;
	DegreeProgram getDegreeProgram() const;

	// Constructors
	Student();
	Student(string studentId, string firstName, string lastName, string email, int age, int numDaysCompleteCourse[], DegreeProgram degreeProgram);

	// Public Student Operations
	void print() const;
	string toString() const;
	bool hasValidEmail() const;
	double averageDaysInCourse() const;

private:
	// Member Variables
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDaysCompleteCourse[NUM_DAYS];
	DegreeProgram degreeProgram;


	// Private Helpers
};

