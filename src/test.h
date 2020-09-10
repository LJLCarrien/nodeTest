class ProtoBufHelper
{
public:
    std::string serializeToStr(int id, std::string name, std::string password);
    void ParseFromString(std::string str);
};
class ShareMemoryHelper
{
public:
    void test();
};
