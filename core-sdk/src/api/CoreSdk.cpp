#include <iostream>
#include "CoreSdk.h"
#include "User.h"

using namespace std;

int getUserAge() {
	cout << "CoreSdk.cpp handler" << endl;
	return getAge();
}