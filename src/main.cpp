//main.cpp
#include <common/common.h>
#include <iostream>
#include "pigeon.pb.h"

int main(int argc, char *argv[])
{
    CommonFct Common;
    tutorial::Mail MailSent;
    tutorial::Mail MailReceived;

    std::cout << "========== Demo C++ Protobuf ==========" << std::endl;
    std::cout << "Set protobuf..." << std::endl;
    MailSent.set_message("Hello World!");
    MailSent.set_from("Luc");
    MailSent.set_to("World");

    std::cout << "Message:" << MailSent.message() << std::endl;
    std::cout << "From:" << MailSent.from() << std::endl;
    std::cout << "To:" << MailSent.to() << std::endl;

    CHECK(Common.WriteAllBytes("test.data", MailSent.SerializeAsString()));

    std::cout << "\nImagine a flying pigeon transporting your message...\n"
              << std::endl;
    std::cout << "Read protobuf..." << std::endl;
    std::vector<char> data = Common.ReadAllBytes("test.data");

    MailReceived.ParseFromArray(data.data(), data.size());

    std::cout << "Message:" << MailReceived.message() << std::endl;
    std::cout << "From:" << MailReceived.from() << std::endl;
    std::cout << "To:" << MailReceived.to() << std::endl;

    return 0;
}