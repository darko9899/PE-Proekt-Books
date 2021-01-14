#ifndef BOOKSELLERS_H
#define BOOKSELLERS_H
#include<string>
#include <iostream>
using namespace std;
class Booksellers
{
public:
	Booksellers(string name, string address, string phone);
	Booksellers();
	friend ostream  &operator<< (ostream &out,  Booksellers &bs);

	string getName();
	void setName(string name);
	string getAddress();
	void setAddress(string address);
	string getPhone();
	void setPhone(string phone);
    virtual ~Booksellers();


private:
	string name;
	string address;
	string phone;
};

#endif // BOOKSELLERS_H
