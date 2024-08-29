#include "student.h"
Student::Student() { //setting default constructor without parameters to make default values
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = -1;
	for (int i = 0; i < numDayArraySize; i++) this->days[i] = -1;
	this->degreeProgram = DegreeProgram::SECURITY;
}
 //setting full constructor with parameters
Student::Student(string studentId, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram) { 	
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < numDayArraySize; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {} //I set the destructor but I dont think there's really any dynamic data

string Student::getId() { return this->studentId; }       //
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }        //these are all the getters
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() const { return this->degreeProgram; } //


void Student::setId(string id) { this->studentId = id; }     //
void Student::setFirstName(string first) { this->firstName = first; }
void Student::setLastName(string last) { this->lastName = last; }
void Student::setEmail(string email) { this->email = email; } 
void Student::setAge(int age) { this->age = age; }						//and these are the setters
void Student::setDays(int days[]) { 
	for (int i = 0; i < numDayArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }//

void Student::printHeader() {
	cout << "Output Format:  ID|First|Last|Email|Age|Days|Degree\n";
}

void Student::print() {
	cout << this->getId() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}