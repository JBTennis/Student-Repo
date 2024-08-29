#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Joshua,Baar,Jbaar1@wgu.edu,26,30,15,55,SOFTWARE"
	};
	
	const int numStudents = 5;
	Roster classRoster;

	cout << "C867, C++, 011540261, Joshua Baar" << endl << endl;



	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
	cout << "showing all students: " << endl;
	classRoster.printAll();
	cout << endl;

	cout << "showing invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "showing average days in course: " << endl;
	classRoster.printAverageDaysInCourse("");
	cout << endl << endl;

	for (int i = 0; i < 3; i++) {
		cout << "organizing by degree: " << degreeProgramStrings[i] << endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "removing student A3: " << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "showing all students: " << endl;
	classRoster.printAll();
	cout << endl << endl;

	cout << "removing student A3: " << endl;
	classRoster.remove("A3");

	return 0;
}