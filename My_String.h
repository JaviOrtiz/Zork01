#ifndef   _My_String
#define   _My_String


#include <string.h>
class String{
private:

	char *buffer = nullptr;
	unsigned int max_mem = 0;



public:

	String(const char* str);
	String(const String& J);
	~String();

public:
	unsigned int Lenght()const;
	const char* C_str() const;
	bool Empty()const;
	bool operator ==(const String& G) const;
	void operator =(const String& H);
	void operator +=(const String&I);
	unsigned int getmax_allocation() const;



};

#endif