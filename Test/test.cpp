#include "../Source/PhoneBook.h"
#include <set>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

int main()
{
	//auto cmp = [](Number a,Number b){return a>b;};
	std::multiset<Number>myPhoneBook;
	std::ifstream fin ("text.txt");
	if(!fin.is_open()){std::cout<< "it is a invalid argumet !!!"<<std::endl;return 5;}
	while(!fin.eof())
	{
		Number tmp;
		fin>>tmp;
		myPhoneBook.insert(tmp);
	}
	int k;
	do{
		std::cout<<"please enter a valid command" <<std::endl;
		std::cout<<"1: please enter 1 for Write :" <<std::endl;
		std::cout<<"2: please enter 2 for read :" <<std::endl;
		std::cout<<"3: please enter 3 for Edit :" <<std::endl;
		std::cout<<"4: please enter 4 for Delete :" <<std::endl;
		int a ;
		std::cin>>a;
		if(a==1)
		{
			Number tmp ;
			std::cin >> tmp ;
			myPhoneBook.insert(tmp);
		}
		else if(a == 2)
		{
			std::copy(myPhoneBook.begin(),myPhoneBook.end(),std::ostream_iterator<Number>(std::cout));
		}
		else if(a==3)
		{
			std::cout << "Enter the Name :" << std::endl;
			std::string n;
			std::cin >> n;
			std::cout << std::endl;
			std::string ln;
			std::cout<< "Enter the LastName :"<<std::endl;
			std::cin >> ln;
			for(auto it : myPhoneBook)
			{
				if(it.findNameSurname(n,ln))
				{
					it.edit();
					break;
				}
			}
		}
		else if(a==4)
		{
			std::cout << "Enter the Name :" << std::endl;
			std::string n;
			std::cin >> n;
			std::cout << std::endl;
			std::string ln;
			std::cout<< "Enter the LastName :"<<std::endl;
			std::cin >> ln;
			for(auto it : myPhoneBook)
			{
				if(it.findNameSurname(n,ln))
				{
					myPhoneBook.erase(it);
					break;
				}
			}
		}
		std::cout<<"For exit enter \"Q\" For Continues 1"<<std::endl;
	}while(std::cin>>k);
	std::ofstream fout ("text.txt", std::ios::binary);
/*	for(auto it : myPhoneBook)
	{
		fout<<it;
	}*/
	std::copy(myPhoneBook.begin(),myPhoneBook.end(),std::ostream_iterator<Number>(fout));
	return 0;
}
