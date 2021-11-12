#include "PhoneBook.h"

Number::Number (const std::string name, const std::string lastName = "" , const std::string address = "", const std::string number = "")
: firstName_{name} , lastName_{lastName} , address_{address} , number_{number}{}

Number::Number (const Number& rhs):firstName_{rhs.firstName_} , lastName_{rhs.lastName_} , address_{rhs.address_} , number_{rhs.number_}{}


Number::Number (Number&& rhs):firstName_{std::move(rhs.firstName_)} , lastName_{std::move(rhs.lastName_)} ,
					address_{std::move(rhs.address_)} , number_{std::move(rhs.number_)}{}
Number::~Number (){}

Number& Number::operator=(const Number& rhs)
{
	if(this == &rhs){return *this;}
	firstName_ = rhs.firstName_;
	lastName_ = rhs.lastName_;
	address_ = rhs.address_;
	number_ = rhs.number_;
	return *this;
}

Number& Number::operator=(Number&& rhs)
{

	if(this == &rhs){return *this;}
	firstName_ = std::move(rhs.firstName_);
	lastName_ = std::move(rhs.lastName_);
	address_ = std::move(rhs.address_);
	number_ = std::move(rhs.number_);
	return *this;
}
bool Number::operator< (const Number& rhs)const
{
	return this->firstName_<rhs.firstName_;
}

bool Number::operator> (const Number& rhs)const
{
	return this->firstName_>rhs.firstName_;
}

bool Number::operator== (const Number& rhs)const
{
	return this->firstName_==rhs.firstName_;
}
bool Number::operator>= (const Number& rhs)const
{
	return !(this->firstName_<rhs.firstName_);
}
bool Number::operator<= (const Number& rhs)const
{
	return !(this->firstName_>rhs.firstName_);
}

std::ostream& operator<< (std::ostream& os , const Number& rhs)
{
	os << rhs.firstName_ << "  " << rhs.lastName_ << " " << rhs.address_ << "  " << rhs.number_ << "\n";
	return os;
}

std::istream& operator>> (std::istream& is , Number& rhs)
{
	is >> rhs.firstName_ >> rhs.lastName_ >> rhs.address_ >> rhs.number_ ;
	return is;
}


bool Number::findNameSurname(const std::string& name,const std::string& surname)const
{
	return this->firstName_ == name && lastName_ == surname ;
}

void Number::edit()
{
	
	std::cout << "Whot du you du edit ?" << std::endl;	
	std::cout << "1: for number" << std::endl;
	std::cout << "2: for Addres" << std::endl;
	int k;
	std::cin >> k;
	std::string PN;
	std::cin>> PN;
	if(k==1)
	{
		this->number_= PN ;
	}
	else if(k == 2)
	{
		this->address_ = PN ;
	}
	return;
}
