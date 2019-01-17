#include "xArray.h"
#include<cstdlib>


xArray::xArray(int size)
	: size(size)
{
	character = new char[size];
	ascii = new int[size];
}


//copy constructor
	xArray::xArray(const xArray &o) {
		size = o.size;
		character = new char[o.size];
		ascii = new int[o.size];
		


		for (int i = 0; i < size; i++) {
			character[i] = o.character[i];
		}
		for (int i = 0; i < size; i++) {
			ascii[i] = o.ascii[i];
		}
		
	}


	xArray::~xArray(){
	delete[] character;
	delete[] ascii;}bool xArray::operator<=(const xArray &o) const{
	int asciiSumx = 0;
	for (int i = 0; i < size; i++) {		asciiSumx += ascii[i];
	}	int asciiSumy = 0;	for (int i = 0; i < o.size; i++) {		asciiSumy += o.ascii[i];
	}	return (asciiSumx) <= (asciiSumy);}