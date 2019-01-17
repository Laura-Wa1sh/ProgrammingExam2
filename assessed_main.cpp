#include "xArray.h"
#include "uConvert.h"
#include <iostream>
using namespace std;

int main1()
{
	xArray array(3);
	array.character[0] = 'a';
	array.character[1] = '=';
	array.character[2] = '%';
	if (array.size > 0) {
		xArray array2 = array;
		// array.ascii holds ascii code of 'a', '=', '%'
		for (int i = 0; i < 3; i++) array.ascii[i] = array2.character[i];
	}
	// print ascii code of '%'
	cout << array.ascii[2] << endl;
	return 0;

}

int main2() {

	xArray a(3);
	a.ascii[0] = 1; a.ascii[1] = 2; a.ascii[2] = 5;
	xArray b(2);
	b.ascii[0] = 97; b.ascii[1] = 100;

	if (a <= (b))  cout << "a <= b is true" << endl; 
	if (!(b <= (a))) cout << "b <= a is false" << endl;

	return 0;
}

//Template function

template<typename T>int search_r(T* array, int array_len, T key)
{
	if (!array || array_len <= 0) {
		cout << "invalid array" << endl;
		return -1;
	}
	// return the index at which key is found
	for (int i = array_len - 1; i >= 0; i--)
		if (array[i] == key) return i;
	// return -1 if key is not found
	return -1;
}



int main() {
	int array_len = 5;
	double* d_array = new double[array_len];
	for (int i = 0; i < array_len; i++) {
		d_array[i] = i;
	}

	cout << search_r(d_array, array_len, d_array[3]) << endl;
	cout << search_r(d_array, array_len, d_array[7]) << endl;
	cout << search_r(d_array, array_len, 3.0) << endl;


	int array_len2 = 5;
	string* s_array = new string[array_len2];
	s_array[0] = "&ab";
	s_array[1] = "134";
	s_array[2] = "z3p";
	s_array[3] = "8ps";
	s_array[4] = "9j=";

	string s1 = "9j=";

	cout << search_r(s_array, array_len2, s_array[4]) << endl;
	cout << search_r(s_array, array_len2, s1) << endl;


    delete[] d_array;
    delete[] s_array;
	return 0;
}

int main4() {
	// a base class pointer
	uConvert* base_ptr = 0;

	// menu to take input from the users
	cout << "\nEnter 1 for litre to gallon conversion\n"
		<< "Enter 2 for Fahrenheit to Celsius conversion\n"
		<< "Enter 3 for feet to meter conversion\n";
	cout  << "Enter 4 for degrees to radians conversion\n";
	int option;
	cin >> option;

	// pointing base_ptr to the derived object of the user's choice
	switch (option) {
	case 1:
		base_ptr = new l2g;
		break;
	case 2:
		base_ptr = new f2c;
		break;
	case 3:
		base_ptr = new f2m;
		break;
	case 4:
		base_ptr = new d2r;
		break;
	default:
		return 0;
	}

	// invoking the conversion
	base_ptr->read_unit();
	base_ptr->convert();
	base_ptr->print();

	delete base_ptr;

	return 0;
}
