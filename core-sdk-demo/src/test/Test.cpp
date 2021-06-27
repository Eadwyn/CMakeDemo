#include <iostream>
#include "CoreSdk.h"
#include "Test.h"
 
using namespace std;
 
void print_user_age() {
	cout << "Test.cpp handler" << endl;
	int age = getUserAge();
	cout << "user age = " << age << endl;
}