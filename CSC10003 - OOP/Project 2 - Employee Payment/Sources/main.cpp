#include "Employee.h"
#include "DailyEmployee.h"
#include "HourlyEmployee.h"
#include "ProductEmployee.h"
#include "Manager.h"
#include "EmployeeFactory.h"
#include "EmployeeDataReader.h"
#include "EmployeeConverter.h"

int main() {
    // Read file
    shared_ptr<EmployeeDataReader> readEmployee = EmployeeDataReader::instance("November2021.txt");
    vector<shared_ptr<Employee>> employeeInfo = readEmployee->readAll();

    // Print out employee's information and the final payment
    EmployeeConverter ec;
    for (int i = 0; i < employeeInfo.size(); i++) {
        cout << ec.converter(employeeInfo[i]) << endl;
    }

    cin.get();
    return 0;
}