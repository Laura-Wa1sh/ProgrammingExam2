#ifndef X_ARRAY_H
#define X_ARRAY_H

class xArray {
public:
	xArray(int size);
	~xArray();
	xArray(const xArray &o);
	bool operator<=(const xArray &o) const;
	int size;
	char* character;
	int* ascii;
	int asciiSum;
	
};



#endif