#include <ctime>
#include <sstream>
#include <iomanip>

#include "Student.h"

Student::Student(int studentID, string studentName, double gpa, string telephone, string mail, Date dob, Address address) {
	_studentID = studentID;
	_studentName = studentName;
	_gpa = gpa;
	_telephone = telephone;
	_mail = mail;
	_dob = dob;
	_homeAddress = address;
}

int Student::id() { return _studentID; }
string Student::name() { return _studentName; }
double Student::gpa() { return _gpa; }
string Student::telephone() { return _telephone; }
string Student::mail() { return _mail; }
Date Student::dob() { return _dob; }
Address Student::address() { return _homeAddress; }

double Student::calculateAverageGPA(vector<Student> studentList) {
	double sum = 0;

	for (int i = 0; i < studentList.size(); i++) sum += studentList[i].gpa();

	return sum / studentList.size();
}

string Student::GreaterThanAverageUIConverter(vector<Student> studentList) {
	double averageGPA = calculateAverageGPA(studentList);
	stringstream builder;

	for (int i = 0; i < studentList.size(); i++) {
		if (studentList[i].gpa() >= averageGPA) {
			builder << studentList[i].id() << " - " << studentList[i].name() << ", GPA:" << fixed << setprecision(2) << studentList[i].gpa() << endl;
		}
	}

	string result = builder.str();
	return result;
}