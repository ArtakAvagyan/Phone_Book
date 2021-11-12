#ifndef PHONEBOOK_H
#define PHONEBOOK_H


#include <iostream>
#include <string>


class Number
{
public:
	Number (){};
	Number (const std::string , const std::string , const std::string , const std::string );
	Number (const Number& rhs);
	Number (Number&& rhs);
	~Number ();
	bool findNameSurname(const std::string&,const std::string&)const;
	void edit();
public:
	Number& operator= (const Number& rhs);
	Number& operator= (Number&& rhs);
	bool operator< (const Number& rhs)const;
	bool operator> (const Number& rhs)const;
	bool operator>= (const Number& rhs)const;
	bool operator<= (const Number& rhs)const;
	bool operator== (const Number& rhs)const;
public:
	friend std::ostream& operator<< (std::ostream& os , const Number& rhs);
	friend std::istream& operator>> (std::istream& is , Number& rhs);
private:
	std::string firstName_;
	std::string lastName_;
	std::string address_;
	std::string number_;
};




#endif /*PHONEBOOK_H */

