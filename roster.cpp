#include "roster.h"
#include <string>
#include <iostream>

void Roster::parse (string line) {
	DegreeProgram studDegree = SECURITY; //I set a default value for studDegree up here so it would be easier to change down below
	
	int rhs = line.find(",");
	string studId = line.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = line.find(",", lhs);
	string studFirst = line.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = line.find(",", lhs);
	string studLast = line.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = line.find(",", lhs);
	string studEmail = line.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = line.find(",", lhs);
	int studAge = std::stoi(line.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = line.find(",", lhs);
	int days1 = std::stoi(line.substr(lhs, rhs - lhs)); //wasn't sure how to convert string to integer so had to look it up

	lhs = rhs + 1;
	rhs = line.find(",", lhs);
	int days2 = std::stoi(line.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = line.find(",", lhs);
	int days3 = std::stoi(line.substr(lhs, rhs - lhs));
	
	lhs = rhs + 1;
	rhs = line.find(",", lhs);
	string temp = line.substr(lhs, rhs - lhs);

	if (temp.at(2) == 'T') studDegree = NETWORK;         //im using the 3rd character in the string to determine degree because
	else if (temp.at(2) == 'F') studDegree = SOFTWARE;   //there are duplicates in the first and second but not the third

	add(studId, studFirst, studLast, studEmail, studAge, days1, days2, days3, studDegree);
}

void Roster::add(string studId, string studFirst, string studLast, string studEmail, int studAge, int days1, int days2, int days3, DegreeProgram studDegree) {
	int dayArr[3] = { days1, days2, days3 }; //turning days into an array for the constructor

	classRosterArray[++finalIndex] = new Student(studId, studFirst, studLast, studEmail, studAge, dayArr, studDegree);
}

void Roster::printAll(){
	cout << "Output Format:  ID|First|Last|Email|Age|Days|Degree" << endl;
	for (int i = 0; i <= Roster::finalIndex; i++) {
		cout << classRosterArray[i]->getId() << '\t';
		cout << classRosterArray[i]->getFirstName() << '\t';
		cout << classRosterArray[i]->getLastName() << '\t';
		cout << classRosterArray[i]->getEmail() << '\t';
		cout << classRosterArray[i]->getAge() << '\t';
		cout << classRosterArray[i]->getDays()[0] << '\t';
		cout << classRosterArray[i]->getDays()[1] << '\t';
		cout << classRosterArray[i]->getDays()[2] << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << endl;
	}

}
void Roster::printByDegreeProgram(DegreeProgram studDegree) {
	cout << "Output Format:  ID|First|Last|Email|Age|Days|Degree" << endl;
	for (int i = 0; i <= Roster::finalIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == studDegree) classRosterArray[i]->print();
	}
	cout << endl;
}

void Roster::printInvalidEmails() { // must include an '@' and a '.' and cannot include any spaces
	bool isValid = true;
	for (int i = 0; i <= Roster::finalIndex; i++) {
		string studEmail = (classRosterArray[i]->getEmail());
		if (studEmail.find('@') == string::npos || studEmail.find('.') == string::npos || studEmail.find(' ') != string::npos) {
			isValid = false;
			cout << studEmail << ": " << classRosterArray[i]->getEmail() << endl;
		}
	}
	if (isValid) cout << "no invalid emails" << endl;
}

void Roster::remove(string studId)
{
	bool found = false;
	for (int i = 0; i <= Roster::finalIndex; i++)
	{
		if (classRosterArray[i]->getId() == studId)
		{
			found = true;
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::finalIndex--;
		}
	}
	if (found) {
		cout << studId << " student removed from roster" << endl << endl;
		this->printAll();
	}
	else cout << studId << " no student found" << endl << endl;
}

void Roster::printAverageDaysInCourse(string studId) {
	for (int i = 0; i <= Roster::finalIndex; i++)
	{
		cout << classRosterArray[i]->getId() << ": ";
		cout << (classRosterArray[i]->getDays()[0]
			+ classRosterArray[i]->getDays()[1]
			+ classRosterArray[i]->getDays()[2]) / 3 << '\t';
	}
}
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
	}
}