#include <iostream>
#include <fstream>
#include "../Account.pb.h"
#include "test.h"
using namespace std;

// protobuf 序列化
string ProtoBufHelper::serializeToStr(int id, string name, string password)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    IM::Account account1;
    account1.set_id(id);
    account1.set_name(name);
    account1.set_password(password);

    string serializeToStr;
    account1.SerializeToString(&serializeToStr);
    cout << "SerializeToString: " << serializeToStr << endl;

    return serializeToStr;
}

// protobuf 反序列化
void ProtoBufHelper::ParseFromString(string str)
{
    IM::Account account2;
    if (!account2.ParseFromString(str))
    {
        cerr << "failed to parse student." << endl;
    }
    else
    {
        cout << "ParseFromString: " << endl;
        cout << account2.id() << endl;
        cout << account2.name() << endl;
        cout << account2.password() << endl;
        google::protobuf::ShutdownProtobufLibrary();
    }
}