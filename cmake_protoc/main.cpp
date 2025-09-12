#include<iostream>
#include"gen/cpp/person.pb.h"

int main()
{
    // 创建person对象
    example::Person person;
    person.set_name("whisper");
    person.set_id(12345);
    person.set_email("whisper@example.com");

    // 序列化person对象
    std::string serialized_data;
    person.SerializeToString(&serialized_data);
    std::cout<<"Serialized size: " << serialized_data.size()<<std::endl;


    // 反序列化person对象
    example::Person parsed_person;
    parsed_person.ParseFromString(serialized_data);
    std::cout<<parsed_person.DebugString();

    return 0;
}