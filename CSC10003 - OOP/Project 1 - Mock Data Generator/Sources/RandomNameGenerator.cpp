#include "RandomNameGenerator.h"

string RandomNameGenerator::next() {
    string firstNames[] = { "Le", "Phan", "Pham", "Nguyen", "Tran", "Ngo" };
    string middleNames[] = { "Duc", "Nhat", "Hoang", "Dieu", "Quang" };
    string lastNames[] = { "Tuan", "Thuan", "Huy", "Thinh", "Khai", "Linh" };

    int n1 = _rng.next(sizeof(firstNames) / sizeof(string));
    int n2 = _rng.next(sizeof(middleNames) / sizeof(string));
    int n3 = _rng.next(sizeof(lastNames) / sizeof(string));

    stringstream out;

    out << firstNames[n1] << " " << middleNames[n2] << " " << lastNames[n3];

    string result = out.str();
    return result;
}