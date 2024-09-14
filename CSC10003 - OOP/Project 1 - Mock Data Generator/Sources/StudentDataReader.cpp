#include <fstream>
#include <sstream>

#include "StudentDataReader.h"

StudentDataReader::StudentDataReader(string filename) {
    _filename = filename;
}

vector<Student> StudentDataReader::readAll() {
    vector<Student> res;
    ifstream inp(_filename);
    string line, name, phone, mail;
    int id;
    double gpa;
    Date dob;

    while (!inp.eof()) {
        getline(inp, line);
        if (line == "") break;
        int begin_idx = line.find(' ') + 1;
        int end_idx = line.find('-') - 2;
        id = stoi(line.substr(begin_idx, end_idx - begin_idx + 1));
        name = line.substr(line.find('-') + 2, line.length() - line.find('-') - 1);
        getline(inp, line);
        gpa = stof(line.substr(line.find('=') + 1, line.find(',') - line.find('=') - 1));
        line = line.substr(line.find(','), line.length() - line.find(','));
        phone = line.substr(line.find('=') + 1, line.length() - line.find('='));
        getline(inp, line);
        mail = line.substr(line.find('=') + 1, line.length() - line.find('='));
        getline(inp, line);
        line = line.substr(line.find('=') + 1, line.length() - line.find('='));
        string tempstr;
        stringstream pstr(line);
        getline(pstr, tempstr, '/');
        dob.setDay(stoi(tempstr));
        getline(pstr, tempstr, '/');
        dob.setMonth(stoi(tempstr));
        getline(pstr, tempstr, '/');
        dob.setYear(stoi(tempstr));
        getline(inp, line);
        Address address;
        line = line.substr(line.find('=') + 1, line.length() - line.find('='));
        address.setNumberAddress(stoi(line.substr(0, line.find(' '))));
        address.setStreetName(line.substr(line.find(' ') + 1, line.find(',') - line.find(' ') - 1));
        line = line.substr(line.find(',') + 2, line.length() - line.find(',') - 2);
        if (line.find("Ward,") == -1) {
            address.setWardName(line.substr(line.find(' ') + 1, line.find(',') - line.find(' ') - 1));
        }
        else {
            address.setWardName(line.substr(0, line.find(" Ward,")));
        }
        line = line.substr(line.find(',') + 2, line.length() - line.find(',') - 2);
        if (line.find("District,") == -1) { // District 1
            address.setDistrictName(line.substr(line.find(' ') + 1, line.find(',') - line.find(' ') - 1));
        }
        else {
            address.setDistrictName(line.substr(0, line.find(" District,")));
        }
        line = line.substr(line.find(',') + 2, line.length() - line.find(',') - 2);
        address.setCityName(line.substr(0, line.find(" city")));
        Student temp(id, name, gpa, phone, mail, dob, address);
        res.push_back(temp);
    }

    inp.close();
    return res;
}