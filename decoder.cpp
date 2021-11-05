#include <iostream>
#include "schema_generated.h"
#include <vector>
#include <fstream>

using namespace test;
using namespace std;

int main(int argc , char **argv)
{
	char buffer[1024];

	if (argc != 2)
	{
		cout << "pass file name as argument" << endl;
		exit(0);
	}

        ifstream myFile (argv[1], ios::in | ios::binary);
        myFile.read (buffer, 1024);
        myFile.close();
        auto clientPtr = Getclient(buffer);

	if ( clientPtr->test_type() == Any_Person)
	{
		std::cout << "=== Decoding Person ===" << endl;
		auto person = reinterpret_cast<const Person *> (clientPtr->test());
        	cout << "person name is " << person->name()->str() << endl;
        	cout << "age is " << person->age() << endl;
        	cout << "weight is " << person->weight() << endl;
        	cout << "gender is " << person->gender() << endl;
	}
	if ( clientPtr->test_type() == test::Any_GroupOfPerson)
	{
		std::cout << "=== Decoding groupOfPerson ===" << endl;
		auto groupOfPerson = reinterpret_cast<const GroupOfPerson *> (clientPtr->test());
		cout << "group name is " << groupOfPerson->group_name()->str() << endl;
        	cout << "average hight is " << groupOfPerson->average_hight() << endl;
        	cout << "average weight is " << groupOfPerson->average_weight() << endl;

        	auto v = groupOfPerson->list_of_name() ;
        	auto len = v->size();

        	for ( int i=0;i<len;i++)
                	std::cout << v->Get(i)->str() << ' ';
	}

	cout << endl;
	return 0;
}
