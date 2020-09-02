#include <node.h>

namespace demo{
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Number;

    // Method1 实现一个 输出"hello world ONE !" 的方法
    void Method1(const FunctionCallbackInfo<Value>& args){
        Isolate* isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, "hello world ONE !"));
    }

    // Method2 实现一个 加一 的方法
    void Method2(const FunctionCallbackInfo<Value>& args){
        Isolate* isolate = args.GetIsolate();
        // 获取参数，js Number 类型转换成 v8 Number 类型 
        Local<Number> value = Local<Number>::Cast(args[0]); 
        double num = value->NumberValue() + 1;

        // double 转 char*，这里我不知道有没有其他办法
        char buf[128] = {0};
        sprintf(buf,"%f", num);

        args.GetReturnValue().Set(String::NewFromUtf8(isolate, buf));
    }

    void init(Local<Object> exports){
        NODE_SET_METHOD(exports, "hello1", Method1);
        NODE_SET_METHOD(exports, "addOne", Method2);
    }

    NODE_MODULE(addon, init)
}