#include <napi.h>
#include "test.h"

Napi::String Method_proHelper(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    ProtoBufHelper *proHelper = new ProtoBufHelper();

    if (!info[0].IsNumber())
    {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return Napi::String::New(env, "-----------------Method_proHelper-----------------Wrong arguments");
    }

    int32_t arg_id = info[0].As<Napi::Number>().Int32Value();
    std::string arg_name = info[1].As<Napi::String>();
    std::string arg_password = info[2].As<Napi::String>();
    std::string serStr = proHelper->serializeToStr(arg_id, arg_name, arg_password);
    proHelper->ParseFromString(serStr);
    return Napi::String::New(env, "-----------------Method_proHelper-----------------End");
}

Napi::String Method_shareMemoryHelper(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    ShareMemoryHelper *shareMHelper = new ShareMemoryHelper();
    shareMHelper->test();
    return Napi::String::New(env, "-----------------Method_shareMemoryHelper-- --------------End");
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "method_proHelper"),
                Napi::Function::New(env, Method_proHelper));

    exports.Set(Napi::String::New(env, "method_shareMemoryHelper"),
                Napi::Function::New(env, Method_shareMemoryHelper));
    return exports;
}

//module_name 必须对应上binding.gyp中的 target_name,此处使用宏NODE_GYP_MODULE_NAME
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)