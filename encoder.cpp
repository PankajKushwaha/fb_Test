#include <iostream>
#include "schema_generated.h"
#include <vector>
#include <fstream>

using namespace test;
using namespace std;

void encode_person(char* filename)
{
        flatbuffers::FlatBufferBuilder builder(1024);
        int age = 40 ;
        float weight = 70 ;
        char gender = 'M';
        auto name = builder.CreateString("Pankaj");
        auto person = CreatePerson(builder, name,age,weight,gender);
       // builder.Finish(person);

        clientBuilder client_builder(builder);

        client_builder.add_test_type(Any_Person); // Union type
        client_builder.add_test(person.Union()); // Union data
	
	auto client_instance = client_builder.Finish();
	builder.Finish(client_instance);


	// write to file
        uint8_t *buf = builder.GetBufferPointer();
        int size = builder.GetSize();
        std::ofstream ofile(filename , std::ios::binary|std::ios::out);
        ofile.write((char *)buf, size);
        ofile.close();

}

void encode_group(char* filename)
{
        flatbuffers::FlatBufferBuilder builder(1024);
        vector<std::string> nameList{"pankaj","nitin","anil","vijay","sourabh"};
        int average_weight = 40 , average_hight=170;
        auto list_of_name = builder.CreateVectorOfStrings(nameList.begin(),nameList.end());
        auto group_name = builder.CreateString("PankajGroup");
        auto personGroup = CreateGroupOfPerson(builder, group_name,average_weight,average_hight,list_of_name);
       // builder.Finish(personGroup);
        
	clientBuilder client_builder(builder);
        client_builder.add_test_type(Any_GroupOfPerson); // Union type
        client_builder.add_test(personGroup.Union()); // Union data

	auto client_instance = client_builder.Finish();
	builder.Finish(client_instance);


        //write buffer to file
        uint8_t *buf = builder.GetBufferPointer();
        int size = builder.GetSize();
        std::ofstream ofile(filename , std::ios::binary|std::ios::out);
        ofile.write((char *)buf, size);
        ofile.close();
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		cout << " please pass -p for person , -g for group , last argument for filename" << endl;
		cout << " example: ./a.out -p person.bin" << endl;
		exit(0);
	}

	if (strcmp(argv[1] , "-p") == 0)
		encode_person(argv[2]);
	if (strcmp(argv[1] , "-g") == 0)
		encode_group(argv[2]);
	return 0;
}
