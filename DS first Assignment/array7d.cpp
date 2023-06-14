#include "array7d.h";

array7d::array7d() {
	int size = 0;
	for (int i = 0; i < 7; i++) {
		indices[i] = rand() % 5 + 1;
		size += indices[i];
	}
	arr = new int[size];
}
array7d::array7d(int i0, int i1, int i2, int i3, int i4, int i5, int i6) {
	indices[0] = i0;
	indices[1] = i1;
	indices[2] = i2;
	indices[3] = i3;
	indices[4] = i4;
	indices[5] = i5;
	indices[6] = i6;
	int size = i0 + i1 + i2 + i3 + i4 + i5 + i6;
	arr = new int[size];
}

void array7d::Insert(int index0, int index1, int index2, int index3, int index4, int index5, int index6, int data) {
	if (index0 >= indices[0] || index1 >= indices[1] || index2 >= indices[2] || index3 >= indices[3] || index4 >= indices[4] || index5 >= indices[5] || index6 >= indices[6]) {
		cout << "Wrong Index\n";
		return;
	}
	arr[index0*indices[6]*indices[5]*indices[4]*indices[3]*indices[2]*indices[1] + index1 * indices[6] * indices[5] * indices[4] * indices[3] * indices[2]+ index2 * indices[6] * indices[5] * indices[4] * indices[3] + index3 * indices[6] * indices[5] * indices[4] + index4 * indices[6] * indices[5] + index5 * indices[6] + index6] = data;
}

int array7d::retrieve(int index0, int index1, int index2, int index3, int index4, int index5, int index6) {
	if (index0 >= indices[0] || index1 >= indices[1] || index2 >= indices[2] || index3 >= indices[3] || index4 >= indices[4] || index5 >= indices[5] || index6 >= indices[6]) {
		cout << "Wrong Index\n";
		return 0;
	}
	return arr[index0 * indices[6] * indices[5] * indices[4] * indices[3] * indices[2] * indices[1] + index1 * indices[6] * indices[5] * indices[4] * indices[3] * indices[2] + index2 * indices[6] * indices[5] * indices[4] * indices[3] + index3 * indices[6] * indices[5] * indices[4] + index4 * indices[6] * indices[5] + index5 * indices[6] + index6];
}