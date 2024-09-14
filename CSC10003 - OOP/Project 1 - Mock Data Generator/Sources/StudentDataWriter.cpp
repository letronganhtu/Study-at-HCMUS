#include <fstream>
#include <iomanip>
#include <regex>

#include "StudentDataWriter.h"

StudentDataWriter::StudentDataWriter(string filename) {
    _filename = filename;
}

void StudentDataWriter::writeAll(vector<Student> studentList) {
    ofstream out(_filename);

    for (int i = 0; i < studentList.size(); i++) {
        out << "Student: " << studentList[i].id() << " - " << studentList[i].name() << endl;
        out << fixed << setprecision(2) << "    GPA=" << studentList[i].gpa() << ", Telephone=" << studentList[i].telephone() << endl;
        out << "    Email=" << studentList[i].mail() << endl;
        out << "    DOB=" << setw(2) << setfill('0') << studentList[i].dob().day() << "/" << setw(2) << setfill('0') << studentList[i].dob().month() << "/" << studentList[i].dob().year() << endl;
        out << "    Address=" << studentList[i].address().numberAddress() << " " <<
            studentList[i].address().streetName() << ", ";

        const string pattern = "\\b\\d+\\b";
        regex numberPattern(pattern);

        if (regex_match(studentList[i].address().wardName(), numberPattern)) {
            out << "Ward " << studentList[i].address().wardName() << ", ";
        }
        else {
            out << studentList[i].address().wardName() << " Ward, ";
        }

        if (regex_match(studentList[i].address().districtName(), numberPattern)) {
            out << "District " << studentList[i].address().districtName() << ", ";
        }
        else {
            out << studentList[i].address().districtName() << " District, ";
        }

        out << studentList[i].address().cityName() << " city\n";
    }

    out.close();
}