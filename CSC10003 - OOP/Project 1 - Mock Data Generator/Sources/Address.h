#ifndef ADDRESS
#define ADDRESS

#include <iostream>
using namespace std;

class Address {
private:
    int _numberAddress;
    string _streetName;
    string _wardName;
    string _districtName;
    string _cityName;
public:
    void setNumberAddress(int);
    void setStreetName(string);
    void setWardName(string);
    void setDistrictName(string);
    void setCityName(string);

    int numberAddress();
    string streetName();
    string wardName();
    string districtName();
    string cityName();
public:
    Address(int, string, string, string, string);

    Address();
};

#endif