#pragma once
#include "student.h"
class Roster {
private:
	int finalIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];


public:
	void parse(string row);//will look for commas within the strings given to seperate attributes and take information
	//then will pass it through the add function to create students
	void add(string studId, string studFirst, string studLast, string studEmail, int studAge, int studDays1, int studDays2, int studDays3, DegreeProgram studDegree);
	void printAll();
	void printAverageDaysInCourse(string studId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram studDegree);
	void remove(string studId);
	~Roster();
}
;