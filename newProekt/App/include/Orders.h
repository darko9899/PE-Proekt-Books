#ifndef ORDERS_H
#define ORDERS_H

#include<string>
#include<vector>
#include "Books.h"
#include "Authors.h"
#include "Booksellers.h"

using namespace std;

class Orders
{
    public:
        Orders();
        Orders(Booksellers bs,vector<Books> b,double p);
        friend ostream  &operator<< (ostream &out,  Orders &o);

        void setBooksellers(Booksellers booksellers);
        void setBooks(vector<Books> books);
        void setPrice(double price);

        Booksellers getBooksellers();
        vector<Books> getBooks();
        double  getPrice();



        virtual ~Orders();



    private:
        Booksellers booksellers;
        vector<Books> books;
        double price;
};

#endif // ORDERS_H
