// Telma.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void pushDifferent(string* buf, short int * bit)
{
	*buf += "{";
	// C++11 are requered for converting int to char
	*buf += to_string(*bit);
	*buf += "}";
}

short int inline getBit(const char* buf, int * byte_number, int * bit_number)
{
	return buf[*byte_number] & (1 << *bit_number) ? 1 : 0;
}

void dumpCompare(const char* buf1, const char* buf2, int size)
{
	const int byte_size = 8;
	const int char_size = byte_size*size;
	string* buf1_print = new string ("");
	string* buf2_print = new string("");

	for (int k = 0; k < size; k++) {
		// Bit size is always similar. 8 iterations are requeried
		for (int i = byte_size - 1; i >= 0; i--)
		{
			short int buf1_bit = buf1[k] & (1 << i) ? 1 : 0;
			short int buf2_bit = buf2[k] & (1 << i) ? 1 : 0;
			if (buf1_bit == buf2_bit)
			{
				// Put bit to string

				// C++11 are requered for converting int to char
				*buf1_print += to_string(buf1_bit);
				*buf2_print += to_string(buf2_bit);
				// Old school way is using itoa
				/*
				char* tmp[3];
				buf1_print += itoa(buf1_bit, tmp, 2);
				buf2_print += itoa(buf2_bit, tmp, 2);
				*/
			}
			else
			{
				// Put bit to string and emphasize them by brackets
				pushDifferent(buf1_print, &buf1_bit);
				pushDifferent(buf2_print, &buf2_bit);
			}
		}
		// Add space after each byte
		*buf1_print += " ";
		*buf2_print += " ";
	}

	// Print the results
	printf("String1:[ %s]\n", (*buf1_print).c_str());
	printf("String2:[ %s]\n", (*buf2_print).c_str());

	// Remove created strings
	delete buf1_print;
	delete buf2_print;
};

int main()
{
	dumpCompare( "0123", "1124", 4);
    return 0;
}

