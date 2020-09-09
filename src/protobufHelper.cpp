#include <iostream>
#include <fstream>
#include "../Account.pb.h"
#include "test.h"
using namespace std;


void ProtoBufHelper::test()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    IM::Account account1;
    account1.set_id(1);
    account1.set_name("windsun");
    account1.set_password("123456");

    string serializeToStr;
    account1.SerializeToString(&serializeToStr);
    cout << "SerializeToString:" << serializeToStr << endl;

    IM::Account account2;
    if (!account2.ParseFromString(serializeToStr))
    {
        cerr << "failed to parse student." << endl;
    }
    else
    {
        cout << "ParseFromString:" << endl;
        cout << account2.id() << endl;
        cout << account2.name() << endl;
        cout << account2.password() << endl;
        google::protobuf::ShutdownProtobufLibrary();
    }
}