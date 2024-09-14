#include "RandomStudentGenerator.h"

int RandomStudentGenerator::randomStudentId() {
    int result;

    result = _rng.next(2127000, 2127999);

    return result;
}

tuple<string, string> RandomStudentGenerator::randomStudentName() {
    string name, mail;
    name = _rfng.next();

    string temp = name;
    stringstream out;

    while (temp.find(' ') != -1) {
        out << temp.substr(0, 1);
        temp = temp.substr(temp.find(' ') + 1, temp.length() - temp.find(' '));
    }
    out << temp << "@student.hcmus.edu.vn";
    mail = out.str();

    for (int i = 0; i < mail.length(); i++) {
        if (mail[i] >= 'A' && mail[i] <= 'Z') mail[i] += 32;
    }

    auto result = make_tuple(name, mail);
    return result;
}

double RandomStudentGenerator::randomGPA() {
    double result;

    int phan_nguyen = _rng.next(11);
    int phan_thap_phan = _rng.next(100);

    if (phan_nguyen == 10) phan_thap_phan = 0;

    result = phan_nguyen + 1.0 * phan_thap_phan / 100;

    return result;
}

string RandomStudentGenerator::randomStudentPhone() {
    int n1 = _rng.next(10, 99);
    int n2 = _rng.next(100, 999);
    int n3 = _rng.next(100, 999);

    stringstream out;

    out << "09" << n1 << "-" << n2 << "-" << n3;

    string result = out.str();
    return result;
}

Date RandomStudentGenerator::randomDob() {
    int day, month, year;

    year = 2003;
    month = _rng.next(12) + 1;

    int dayOfMonth[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    day = _rng.next(1, dayOfMonth[month]);

    Date result(day, month, year);
    return result;
}

Address RandomStudentGenerator::randomStudentAddress() {
    int number = _rng.next(500) + 1;

    string city[] = { "Ho Chi Minh", "Ho Chi Minh", "Ho Chi Minh", "Da Nang", "Da Nang", "Da Nang", "Ha Noi", "Ha Noi" };
    string district[] = { "5", "Tan Phu", "7", "Hai Chau", "Son Tra", "Ngu Hanh Son", "Nam Tu Liem", "Tay Ho" };
    string ward[] = { "4", "Phu Tho Hoa", "Tan Phu", "Thuan Phuoc", "Man Thai", "Khue My", "My Dinh", "Buoi" };
    string street[] = { "Nguyen Van Cu", "Le Thuc Hoach", "Ton Dat Tien", "3 thang 2", "Nguyen Sang", "Da Phuoc 10", "Le Duc Tho", "Thuy Khue" };

    int temp = _rng.next(sizeof(city) / sizeof(string));
    Address result(number, street[temp], ward[temp], district[temp], city[temp]);
    return result;
}

Student RandomStudentGenerator::randomStudent() {
    int id = randomStudentId();
    string name, mail;
    auto name_mail = randomStudentName();
    name = get<0>(name_mail);
    double gpa = randomGPA();
    string phone = randomStudentPhone();
    mail = get<1>(name_mail);
    Date dob = randomDob();
    Address address = randomStudentAddress();
    Student result(id, name, gpa, phone, mail, dob, address);
    return result;
}