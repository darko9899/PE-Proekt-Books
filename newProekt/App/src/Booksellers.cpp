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

Booksellers::Booksellers(string name, string address, string phone)
{
	this->name = name;
	this->address = address;
	this->phone = phone;
}

Booksellers::Booksellers(){}

ostream  &operator<< (ostream &out,  Booksellers &bs){

    out<<"Name: "<<bs.getName()<<endl;
    out<<"Address: "<<bs.getAddress()<<endl;
    out<<"Phone number: "<<bs.getPhone()<<endl;
    out<<"------------------------"<<endl;

    return out;

}

string Booksellers::getName()
{
	return name;
}

void Booksellers::setName(string name)
{
	this->name = name;
}

string Booksellers::getAddress()
{
	return address;
}

void Booksellers::setAddress(string address)
{
	this->address = address;
}

string Booksellers::getPhone()
{
	return phone;
}

void Booksellers::setPhone(string phone)
{
	this->phone = phone;
}


Booksellers::~Booksellers()
{
    //dtor
}
