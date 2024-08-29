#pragma once
#include "degree.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
public:
	const int numDayArraySize = 3; //There are only going to be 3 different inputs for days in the array

private:
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[3]; //i wanted to set numDayArraySize in here but the compiler didn't like that
	DegreeProgram degreeProgram;

public:
	Student(); //default constructor
	Student(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
	//full constructor
	~Student(); //destructor

	//these are the accesors or getters
	string getId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram() const;

	//there are the mutators or setters
	void setId(string id);
	void setFirstName(string first);
	void setLastName(string last);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram dp);

	void printHeader();

	void print();

};