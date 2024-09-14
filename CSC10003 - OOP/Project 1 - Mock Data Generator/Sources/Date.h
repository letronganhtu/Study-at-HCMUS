#ifndef My_Class
#define My_Class

class Date {
private:
    int _day;
    int _month;
    int _year;
public:
    int day();
    int month();
    int year();

    void setDay(int);
    void setMonth(int);
    void setYear(int);
public:
    Date();

    Date(int, int, int);
};

#endif