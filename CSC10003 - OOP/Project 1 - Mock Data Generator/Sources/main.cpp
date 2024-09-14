#include <iomanip>

#include "StudentDataReader.h"
#include "RandomStudentGenerator.h"
#include "StudentDataWriter.h"

int main() {
	// Read file and save data back into a vector of Student
	StudentDataReader sdr("students.txt");
	vector<Student> studentList = sdr.readAll();

	// Generate randomly a number in the range of [5, 10]
	RandomIntegerGenerator rng;
	int n = rng.next(5, 10);
	cout << "n = " << n << endl;

	// Generate randomly n students and add to previous vector
	RandomStudentGenerator rsg;
	for (int i = 0; i < n; i++) {
		Student temp = rsg.randomStudent();
		studentList.push_back(temp);
	}

	// Overwrite "students.txt" with current vector of Student
	StudentDataWriter sdw("students.txt");
	sdw.writeAll(studentList);

	// Calculate and print the average GPA of all students
	double averageGPA = Student::calculateAverageGPA(studentList);
	cout << fixed << setprecision(2) << "\nThe average GPA of all students: " << averageGPA << endl << endl;

	// Print all the students that have GPA greater than average GPA
	string printGreaterGPA = Student::GreaterThanAverageUIConverter(studentList);
	cout << printGreaterGPA;

	// Test code
	/*cout << endl;
	for (int i = 0; i < studentList.size(); i++) {
		cout << studentList[i].id() << "           " << studentList[i].name() << endl;
		cout << studentList[i].gpa() << "\t" << studentList[i].telephone() << "\t" << studentList[i].mail() << endl;
		cout << studentList[i].dob().day() << "/" << studentList[i].dob().month() << "/" << studentList[i].dob().year() << endl;
		cout << studentList[i].address().numberAddress() << "--" << studentList[i].address().streetName() << "--"
			<< studentList[i].address().wardName() << "--" << studentList[i].address().districtName() << "--" <<
			studentList[i].address().cityName() << endl << endl;
	}*/

	cin.get();
	return 0;
}