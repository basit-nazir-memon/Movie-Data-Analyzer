#pragma once
#include <iostream>
using namespace std;

class array7d {
public:
	int* arr;
	int indices[7];
public:
	array7d();
	array7d(int i0, int i1, int i2, int i3, int i4, int i5, int i6);
	void Insert(int, int, int, int, int, int, int, int);
	int retrieve(int, int, int, int, int, int, int);
};
