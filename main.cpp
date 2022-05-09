// StudentRosterConversionV2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

void parseString(string s, Roster* roster)
{
	// Variables to create Student 
	string studentId, firstName, lastName, email;
	int age, numDaysCompleteCourse[Student::NUM_DAYS];
	DegreeProgram degreeProgram;

	// Variables for converting string to int
	string temp;
	stringstream* ss = new stringstream;

	// Strategy is to start at index 0
	// Then find index (i) of first comma 
	// Take the substring [0, i) and store in variable
	// Remove the substring [0, i] from original string
	// Then start over for the next variable
	int i = 0;

	// find studentId
	i = s.find(',');
	studentId = s.substr(0, i);
	s = s.substr(i + 1, s.length());

	// find firstName
	i = s.find(',');
	firstName = s.substr(0, i);
	s = s.substr(i + 1, s.length());

	// find lastName
	i = s.find(',');
	lastName = s.substr(0, i);
	s = s.substr(i + 1, s.length());

	// find email
	i = s.find(',');
	email = s.substr(0, i);
	s = s.substr(i + 1, s.length());

	// find age
	i = s.find(',');
	temp = s.substr(0, i);
	ss = new stringstream(temp);
	*ss >> age;
	s = s.substr(i + 1, s.length());
	delete ss;

	// find numDaysCompleteCourse
	for (int j = 0; j < Student::NUM_DAYS; j++)
	{
		i = s.find(',');
		temp = s.substr(0, i);
		ss = new stringstream(temp);
		*ss >> numDaysCompleteCourse[j];
		s = s.substr(i + 1, s.length());
		delete ss;
	}

	// find DegreeProgram
	degreeProgram = Roster::stringToDegreeProgram(s);

	roster->add(studentId, firstName, lastName, email, age, numDaysCompleteCourse[0], numDaysCompleteCourse[1], numDaysCompleteCourse[2], degreeProgram);
}

int main()
{
    // print out of my information
    cout << "Course Title: \t\t\tScripting and Programming - Applications -- C867" << endl;
    cout << "Programmiing Language Used: \tC++" << endl;
    cout << "Student ID: \t\t\t#001367934" << endl;
    cout << "Student Name: \t\t\tSteven Kazmierkiewicz" << endl;
    cout << endl;

    // Input Data
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Steven,Kazmierkiewicz,skazmie@wgu.edu,34,7,6,30,SOFTWARE"
    };

	cout << "Creating classRoster..." << endl;
	Roster classRoster;

	cout << "Adding each student to classRoster" << endl;
	for (int i = 0; i < Roster::ORIG_NUM_STUDENTS; i++)
	{
		parseString(studentData[i], &classRoster);
	}

    cout << "printing all student records..." << endl;
    classRoster.printAll();
    cout << endl;

    cout << "printing Invalid Emails..." << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "printing Average Days In Course Per Student..." << endl;
    Student* temp = nullptr;
    
    for (int i = 0; i < classRoster.getNumStudents(); i++)
    {
        temp = classRoster.getStudent(i);
        classRoster.printAverageDaysInCourse(temp->getStudentId());
    }
    cout << endl;

    cout << "printing by Degree Program, SOFTWARE..." << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing Student 'A3'..." << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "printing updated Roster..." << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Attempting to remove A3 again..." << endl;
    classRoster.remove("A3");

    return 0;
}