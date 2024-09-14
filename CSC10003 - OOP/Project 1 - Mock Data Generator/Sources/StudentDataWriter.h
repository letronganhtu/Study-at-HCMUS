#include <iostream>
#include <vector>
using namespace std;

#include "Student.h"

class StudentDataWriter {
private:
    string _filename;
public:
    StudentDataWriter(string);
public:
    void writeAll(vector<Student>);
};