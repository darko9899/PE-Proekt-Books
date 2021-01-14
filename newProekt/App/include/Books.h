#ifndef BOOKS_H
#define BOOKS_H
#include<string>
#include "Authors.h"

using namespace std;
class Books
{
public:
	Books(string t, Authors a, string e, string I, string d, int q, string da, double pr);
	Books();

	friend ostream  &operator<< (ostream &out,  Books &b);

	string getTitle();
	Authors getAuthors();
	string getEdition();
	string getISBN();
	string getDateOfPublication();
	int getQuantity();
	string getDateOFApproval();
	double getPrice();

	void setTitle(string title);
	void setAuthors(Authors authors);
	void setEdition(string edition);
	void setISBN(string ISBN);
	void setDateOfPublication(string dateOfPublication);
	void setQuantity(int quantity);
	void setDateOFApproval(string dateOfApproval);
	void setPrice(double price);
    virtual ~Books();

private:
	string title;
	Authors authors;
	string edition;
	string ISBN;
	string dateOfPublication;
	int quantity;
	string dateOfApproval;
	double price;



};




#endif // BOOKS_H
