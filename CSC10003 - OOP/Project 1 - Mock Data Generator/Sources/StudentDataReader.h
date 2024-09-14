#include <string>
#include <vector>
using namespace std;

#include "Student.h"

class StudentDataReader {
private:
    string _filename;
public:
    StudentDataReader(string);
public:
    vector<Student> readAll();
};