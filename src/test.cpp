#include <nan.h>
#include "test.h"

// using namespace v8;
// using v8::FunctionCallbackInfo;
// using v8::Isolate;
using v8::Local;
// using v8::Number;
using v8::Object;
// using v8::String;
using v8::Context;
using v8::FunctionTemplate;
using v8::Value;

void Method_proHelper(const Nan::FunctionCallbackInfo<Value> &info)
{
    ProtoBufHelper *proHelper = new ProtoBufHelper();
    proHelper->test();
    info.GetReturnValue()
        .Set(Nan::New("-----------------Method_proHelper----------------End").ToLocalChecked());
}

void Method_shareMemoryHelper(const Nan::FunctionCallbackInfo<Value> &info)
{
    ShareMemoryHelper *shareMHelper = new ShareMemoryHelper();
    shareMHelper->test();
    info.GetReturnValue()
        .Set(Nan::New("-----------------Method_shareMemoryHelper----------------End").ToLocalChecked());
}

void Init(Local<Object> exports)
{
    Local<Context> context = exports->CreationContext();
    exports->Set(context,
                 Nan::New("method_proHelper").ToLocalChecked(),
                 Nan::New<FunctionTemplate>(Method_proHelper)
                     ->GetFunction(context)
                     .ToLocalChecked());
    exports->Set(context,
                 Nan::New("method_shareMemoryHelper").ToLocalChecked(),
                 Nan::New<FunctionTemplate>(Method_shareMemoryHelper)
                     ->GetFunction(context)
                     .ToLocalChecked());
}

//module_name 必须对应上binding.gyp中的 target_name,此处使用宏NODE_GYP_MODULE_NAME
NODE_MODULE(NODE_GYP_MODULE_NAME, Init)