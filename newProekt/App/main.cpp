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
#include <regex>

vector<Orders> orders;


using namespace std;
void addBook();
void addBookseller();
vector<Books> printBooks();
vector<Booksellers> printBookseller();
void makeOrder();
Booksellers searchBooksellerByName(vector<Booksellers> booksellers);
vector<Books> searchBooksByName(vector<Books> books);
void showOrders();
bool validDate(string dateForCheck);
bool f=false;

/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

    int a;
    do{
        cout<<"Choose option:\n 1. Add new books\n 2. Add new booksellers\n 3. Show list of books\n 4. Show list of booksellers\n 5. Make order\n 6. Show orders\n 7. EXIT\n------------------------------"<<endl;
       do{
        cout<<"Insert a number: ";
        cin >> a;
            if(a<1||a>7){
                cout<<"Wrong number!!!"<<endl;
            }
       }while(a<1&&a>7);

        switch (a) {
        case 1:
                cout << "Your choise: 1. Add new books "<<endl<<endl;
                addBook();
            break;
        case 2:
                cout << "Your choise: 2. Add new booksellers "<<endl<<endl;
                addBookseller();
            break;
        case 3:
                cout << "Your choise: 3. Show list of books"<<endl<<endl;
                printBooks();
            break;
        case 4:
                cout << "Your choise: 4. Show list of booksellers"<<endl<<endl;
                printBookseller();
            break;
        case 5:
                cout << "Your choise: 5. Make order"<<endl<<endl;
                makeOrder();
            break;
        case 6:
                cout << "Your choise: 6. Show orders"<<endl<<endl;
                showOrders();
            break;
            }
        }while(a!=7);
            cout << "Your choise: 7. EXIT\n      BYE! :D";
}
/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
void addBook() {


    string title;
    string firstName;
    string lastName;
    string edition;
    string ISBN;
    string dateOfPublication;
    int quantity;
    string dateOfApproval;
    double price;

    ofstream outFile;
    outFile.open("Books.txt",ios_base::app);
    if(outFile.fail()){
            cerr<<"Error opening file!!!"<<endl;
            exit(1);
    }

    int n;
    cout<<"How many books you want to add?"<<endl;
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i=0;i<n;i++){

            bool flag=false,sflag=false;

            cout << "Title:";
            getline(cin,title);
            cout << "Authors first name:";
            getline(cin,firstName);
            cout << "Authors last name:";
            getline(cin,lastName);
            cout << "Edition:";
            getline(cin,edition);
            cout << "ISBN:";
            getline(cin,ISBN);


     while(flag==false){
            cout << "Insert date in format:  DD/MM/YYYY"<<endl;
            cout << "Date of publication:";
            getline(cin,dateOfPublication);
            flag=validDate(dateOfPublication);
            if(flag==false ){
                cout<<"Wrong format of date!!!"<<endl;
            }
    }

    do{
        cout << "Quantity:";
        cin>>quantity;
        if(quantity<0){
            cout<<"Quantity can't be neagtive!!!"<<endl;
        }
    }while(quantity<0);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(sflag==false){
        cout << "Insert date in format:  DD/MM/YYYY or insert 'NOT APPROVED YET' if it's not approved!"<<endl;
        cout << "Date of approval:";
        getline(cin,dateOfApproval,'\n');
        if(dateOfApproval=="NOT APPROVED YET"){
                break;
        } else{
            sflag=validDate(dateOfApproval);
            if(sflag==false )cout<<"Wrong format of date!!!"<<endl;
          }
    }

    do{
        cout << "Price:";
        cin>>price;
        if(price<0){
            cout<<"Price can't be neagtive!!!"<<endl;
        }
      }while(price<0);

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout<<"------------------------------------"<<endl;

    //Authors a;
    /*a.setfirstName(firstName);
      a.setlastName(lastName);*/

      Authors a(firstName,lastName);

      Books b(title,a,edition,ISBN,dateOfPublication,quantity,dateOfApproval,price);

   /* Books b;
      b.setTitle(title);
      b.setAuthors(a);
      b.setEdition(edition);
      b.setISBN(ISBN);
      b.setDateOfPublication(dateOfPublication);
      b.setQuantity(quantity);
      b.setDateOFApproval(dateOfApproval);
      b.setPrice(price);*/

      outFile << b.getTitle() << endl;
      outFile << b.getAuthors().getfirstName()<<endl;
      outFile<<b.getAuthors().getlastName() << endl;
      outFile  << b.getEdition() << endl;
      outFile  << b.getISBN() << endl;
      outFile  << b.getDateOfPublication()<< endl;
      outFile << b.getQuantity()<< endl;
      outFile  << b.getDateOFApproval()<< endl;
      outFile  << b.getPrice()<< endl;
      cout<<"Book added!!!"<<endl;
    }
      outFile.close();

}
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////

bool validDate(string dateForCheck){

    bool flag=false;
    smatch matches;
    regex reg("^[0-3]+[0-9]/[0-3]+[0-9]/(?:[0-9]{2})?[0-9]{4}$");

    if(regex_match(dateForCheck,matches,reg)){
            flag=true;
    }
    return flag;

}
////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////
void addBookseller(){

    string name;
	string address;
	string phone;
 // Booksellers bs;
    ofstream outFile;
    outFile.open("Booksellers.txt",ios_base::app);
    if(outFile.fail()){
        cerr<<"Error opening file!!!"<<endl;
        exit(2);
    }
    int n;
    cout<<"How many booksellers you want to add?"<<endl;
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i=0;i<n;i++){

            cout << "Name:";
            getline(cin,name);
            cout << "Address:";
            getline(cin,address);
            cout << "Phone number:";
            getline(cin,phone);
            cout<<"------------------------------------"<<endl;

            Booksellers bs(name,address,phone);
            /*bs.setName(name);
            bs.setAddress(address);
            bs.setPhone(phone);*/

            outFile<<bs.getName()<<endl;
            outFile<<bs.getAddress()<<endl;
            outFile<<bs.getPhone()<<endl;
             cout<<"Bookseller added!!!"<<endl;

    }

    outFile.close();
}

/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

vector<Books> printBooks(){

    vector<Books> books;
    string x ,y;

    string title;
    string firstName;
    string lastName;
    string edition;
    string ISBN;
    string dateOfPublication;
    int quantity;
    string dateOfApproval;
    double price;


    ifstream inFile("Books.txt");
    if(inFile.fail()){
        cerr<<"Error opening file!!!"<<endl;
                exit(3);
    }

    while(1){

        getline(inFile,title,'\n');
        getline(inFile,firstName,'\n');
        getline(inFile,lastName,'\n');




        Authors a(firstName,lastName);
        getline(inFile,edition,'\n');
               if (inFile.eof()) break;

        getline(inFile,ISBN,'\n');
        getline(inFile,dateOfPublication,'\n');
        getline(inFile,x,'\n');
        stringstream geek(x);
        geek >> quantity;
        getline(inFile,dateOfApproval,'\n');
        getline(inFile,y,'\n');
        stringstream gek(y);
        gek >> price;

        Books b(title,a,edition,ISBN,dateOfPublication,quantity,dateOfApproval,price);

        books.push_back(b);

        if (inFile.eof()) break;

    }


    for(Books bo:books){

        cout<<bo<<endl;
    }
    inFile.close();

    return books;

}

/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

vector <Booksellers> printBookseller(){

        vector<Booksellers> booksellers;
        string n,a,p;
     // Booksellers bs;
        ifstream inFile("Booksellers.txt");
        if(inFile.fail()){
            cerr<<"Error opening file!!!"<<endl;
            exit(3);
        }

        while(1){

           getline(inFile,n,'\n');
           if (inFile.eof()) break;

            getline(inFile,a,'\n');
            getline(inFile,p,'\n');
            Booksellers bs(n,a,p);
           /* bs.setName(n);
            bs.setAddress(a);
            bs.setPhone(p);*/

             booksellers.push_back(bs);

         }
        for(Booksellers bsel:booksellers){

            cout<<bsel<<endl;

        }

        inFile.close();
        return booksellers;
}
/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

void makeOrder(){

            cout<<"Choose a bookseller:"<<endl<<endl;
            Booksellers bs;
            vector<Booksellers> booksellers;
            vector<Books> books;
            vector<Books> orederedBooks;
            double totalPrice;

            booksellers=printBookseller();
            cout<<endl;
            bs=searchBooksellerByName(booksellers);
            cout<<endl;
            cout<<"Your choise:"<<endl;
            cout<<bs<<endl;
            cout<<"Choose a books:"<<endl<<endl;
            books=printBooks();
            cout<<endl;
            orederedBooks=searchBooksByName(books);
            cout<<endl;

            cout<<"Order complete!!!"<<endl<<endl;

            for(Books b:orederedBooks){

                    totalPrice+=b.getPrice();
                    }


            Orders order(bs,orederedBooks,totalPrice);

                 orders.push_back(order);
            f=true;

}

/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

Booksellers searchBooksellerByName(vector<Booksellers> booksellers){

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string nameOfBookseller;


       while(1){

                cout<<"Insert name of bookseller:"<<endl;
                getline(cin,nameOfBookseller,'\n');

                for(Booksellers bsel:booksellers){

                        if(nameOfBookseller==bsel.getName()){

                                return bsel;
                        }

                }

         cout<<"Wrong name!!!"<<endl;
       }

}
/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////

vector<Books> searchBooksByName(vector<Books> books){


             string nameOfBook;
             vector<Books> orederedBooks;
             int num;
             bool flag;

             cout<<"How many books you want to order?"<<endl;
             cin>>num;
             cin.ignore(numeric_limits<streamsize>::max(), '\n');

             for(int i=0;i<num;i++){
                    flag=false;
                    while(flag==false){

                            cout<<"Insert title of book:"<<endl;

                            getline(cin,nameOfBook, '\n');

                            for(Books b:books){

                                    if(nameOfBook==b.getTitle()){
                                            cout<<"Ordered!!!"<<endl;
                                            orederedBooks.push_back(b);
                                            flag=true;
                                    }


                            }
                            if(flag==false){
                                    cout<<"Wrong title!!!"<<endl;
                                    }

                    }

             }

     return orederedBooks;

}

void showOrders(){
        if(f==false){
            cout<<"YOU DIDN'T MAKE ORDER YET!!!"<<endl<<endl;
        }
        else{
            for(Orders o:orders){
                cout<<o;
            }
        }

}

