#include<string>
#include <iostream>
#include "Books.h"
#include "Authors.h"
#include "Booksellers.h"
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include "Orders.h"


using namespace std;

Authors::Authors(){}
Authors::Authors(string firstName, string lastName) {
	this->firstName = firstName;
	this->lastName = lastName;
}

ostream  &operator<< (ostream &out,  Authors &a){
    out  << a.getfirstName()<<a.getlastName() << endl;
    return out;

}

string Authors::getfirstName()
{
	return firstName;
}
string Authors::getlastName()
{
	return lastName;
}

void Authors::setfirstName(string firstName)
{
	this->firstName = firstName;
}
void Authors::setlastName(string lastName)
{
	this->lastName = lastName;
}

Authors::~Authors()
{
    //dtor
}
