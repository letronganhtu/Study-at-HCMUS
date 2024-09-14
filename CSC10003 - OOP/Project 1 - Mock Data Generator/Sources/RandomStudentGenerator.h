#include <iostream>
#include <sstream>
#include <tuple>
using namespace std;

#include "RandomNameGenerator.h"
#include "Date.h"
#include "Address.h"
#include "Student.h"

class RandomStudentGenerator {
private:
    RandomIntegerGenerator _rng;
    RandomNameGenerator _rfng;
public:
    int randomStudentId();

    tuple<string, string> randomStudentName();

    double randomGPA();

    string randomStudentPhone();

    Date randomDob();

    Address randomStudentAddress();

    Student randomStudent();
};