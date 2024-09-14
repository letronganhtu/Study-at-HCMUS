#include <iostream>
#include <ctime>

#include "RandomIntegerGenerator.h"

RandomIntegerGenerator::RandomIntegerGenerator() {
	srand(time(NULL));
}

int RandomIntegerGenerator::next() {
	int result = rand();
	return result;
}

int RandomIntegerGenerator::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}

int RandomIntegerGenerator::next(int left, int right) {
	int result = left + rand() % (right - left + 1);
	return result;
}