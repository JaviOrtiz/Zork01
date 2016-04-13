#include "My_String.h"
#include <string.h>
#include <stdio.h>

#define CRT_SECURE_NO_WARNINGS

String::String(const char* str){

	int len = strlen(str);
	max_mem = len + 1;
	buffer = new char[len + 1];
	strcpy_s(buffer, len + 1, str);

};

String::String(const String& J){

	int len = strlen(J.buffer);
	max_mem = len + 1;
	buffer = new char[len + 1];
	strcpy_s(buffer, len + 1, J.buffer);

}

unsigned int String::Lenght()const{

	unsigned int i = strlen(buffer);
	return i;
};


const char* String::C_str()const{

	return buffer;

}

bool String::Empty()const{

	if (strlen(buffer) == 0){
		return true;
	}
	else return false;


};


bool String::operator==(const String& G)const{

	int i = strcmp(buffer, G.buffer);

	if (i == 0){
		return true;
	}
	else return false;



};



void String::operator=(const String& H){


	if (H.Lenght() + 1 <= max_mem){
		strcpy_s(buffer, max_mem, H.buffer);
		printf("mas pequeño o igual\n");
	}
	else{

		delete[] buffer;
		max_mem = H.Lenght() + 1;
		printf("\n%i\n", max_mem);
		buffer = new char[max_mem];
		strcpy_s(buffer, max_mem, H.buffer);
		printf("mas grande\n");

	}


};


void String::operator+=(const String& I){

	if (I.Lenght() + 1 <= max_mem){
		//strcat(buffer, I.buffer);

	}

	else{

		char* buffer2 = buffer;
		max_mem = I.Lenght() + strlen(buffer);
		delete[] buffer;
		buffer = new char[max_mem];
		//strcat(buffer2, I.buffer);
		buffer = buffer2;
	}






};

unsigned int String::getmax_allocation()const{


	return max_mem;

};

String::~String(){
	delete[] buffer;
};