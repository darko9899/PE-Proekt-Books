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

Books::Books(string t, Authors a, string e, string I, string d, int q, string da, double pr)
	:title(t), authors(a), edition(e),
	ISBN(I), dateOfPublication(d), quantity(q), dateOfApproval(da), price(pr)
{

}
Books::Books(){};

////////////////////////////////////////////////////////////////get
string Books::getTitle()
{
	return title;
}

Authors Books::getAuthors()
{
	return authors;
}

string Books::getEdition()
{
	return edition;
}

string Books::getISBN()
{
	return ISBN;
}

string Books::getDateOfPublication()
{
	return dateOfPublication;
}

int Books::getQuantity()
{
	return quantity;
}

string Books::getDateOFApproval()
{
	return dateOfApproval;
}
double Books::getPrice()
{
	return price;
}
//////////////////////////////////////////////set
void Books::setTitle(string title)
{
	this->title = title;
}
void Books::setAuthors(Authors authors)
{
	this->authors = authors;
}
void Books::setEdition(string edition)
{
	this->edition = edition;
}
void Books::setISBN(string ISBN)
{
	this->ISBN = ISBN;
}
void Books::setDateOfPublication(string dateOfPublication)
{
	this->dateOfPublication = dateOfPublication;
}
void Books::setQuantity(int quantity)
{
	this->quantity = quantity;
}
void Books::setDateOFApproval(string dateOfApproval)
{
	this->dateOfApproval = dateOfApproval;
}
void Books::setPrice(double price)
{
	this->price = price;
}

ostream  &operator<< (ostream &out,  Books &b)
{

       out<<"Title: "<<b.getTitle()<<endl;
       out<<"Author: "<<b.getAuthors().getfirstName()<<" "<<b.getAuthors().getlastName()<<endl;
       out<<"Edition: "<<b.getEdition()<<endl;
       out<<"ISBN: "<<b.getISBN()<<endl;
       out<<"Date of publication: "<<b.getDateOfPublication()<<endl;
       out<<"Quantity: "<<b.getQuantity()<<endl;
       out<<"Date of approval: "<<b.getDateOFApproval()<<endl;
       out<<"Price: "<<b.getPrice()<<"$"<<endl;
       out<<"------------------------"<<endl;
       return out;

}

Books::~Books()
{
    //dtor
}
