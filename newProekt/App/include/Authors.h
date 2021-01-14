#ifndef AUTHORS_H
#define AUTHORS_H

#include<string>
using namespace std;
class Authors
{
public:
    Authors();
	Authors(string firstName, string lastName);
	string getfirstName();
	void setfirstName(string firstName);
	string getlastName();
	void setlastName(string lastName);
	virtual ~Authors();
    friend ostream  &operator<< (ostream &out,  Authors &a);


private:
	string firstName;
	string lastName;
};


#endif // AUTHORS_H

