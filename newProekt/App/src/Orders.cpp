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
Orders::Orders()
{
    //ctor
}

Orders::Orders(Booksellers bs,vector<Books> b,double p)
    : booksellers(bs),books(b),price(p)
{

}

ostream  &operator<< (ostream &out,  Orders &o){

   out << "BOOKSELLER: " << endl;
    out << "Name: "<<o.getBooksellers().getName()<<endl;
    out << "Address: "<<o.getBooksellers().getAddress()<<endl;
    out << "Phone: "<<o.getBooksellers().getPhone()<<endl;
    out<<"------------------------"<<endl;
    out << "BOOKS: " << endl;
    for(Books bo:o.getBooks()){
                    out << "Title: "<<bo.getTitle()<<endl;
                    out<<"Author: "<<bo.getAuthors().getfirstName()<<" "<<bo.getAuthors().getlastName()<<endl;
                    out<<"Edition: "<<bo.getEdition()<<endl;
                    out<<"ISBN: "<<bo.getISBN()<<endl;
                    out<<"Date of publication: "<<bo.getDateOfPublication()<<endl;
                    out<<"Circulation: "<<bo.getQuantity()<<endl;
                    out<<"Date oF approval: "<<bo.getDateOFApproval()<<endl;
                    out<<"Price: "<<bo.getPrice()<<"$"<<endl;
                    out<<"------------------------"<<endl;
       }
    out << "TOTAL PRICE: "<<o.getPrice()<<"$"<<endl;
    out<<"------------------------"<<endl;
    out<<"------------------------"<<endl<<endl;
       return out;

 }


vector<Books> Orders::getBooks()
{
	return books;
}

Booksellers  Orders::getBooksellers()
{
	return booksellers;
}

double Orders::getPrice()
{
	return price;
}



void Orders::setPrice(double price){
        this->price = price;
}

void Orders::setBooks(vector<Books> books)
{
	this->books = books;
}
void Orders::setBooksellers(Booksellers booksellers)
{
	this->booksellers = booksellers;
}

Orders::~Orders()
{
    //dtor
}
