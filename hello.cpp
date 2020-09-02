#include <node.h>
using namespace v8;

namespace demo
{
    // using v8::FunctionCallbackInfo;
    // using v8::Isolate;
    // using v8::Local;
    // using v8::Number;
    // using v8::Object;
    // using v8::String;
    // using v8::Value;

    // Method1 实现一个 输出"hello world ONE !" 的方法
    void Method1(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, "hello world ONE !"));
    }

    // Method2 实现一个 加一 的方法
    void Method2(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        // 获取参数，js Number 类型转换成 v8 Number 类型
        Local<Number> value = Local<Number>::Cast(args[0]);
        double num = value->NumberValue() + 1;

        // double 转 char*，这里我不知道有没有其他办法
        char buf[128] = {0};
        sprintf(buf, "%f", num);

        args.GetReturnValue().Set(String::NewFromUtf8(isolate, buf));
    }

    //callback
    void CallThis(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Function> cb = Local<Function>::Cast(args[0]);
        cb->Call(Null(isolate), 0, nullptr);
    }
    void CallThisWithThis(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();
        Local<Function> cb = Local<Function>::Cast(args[0]);
        Local<Value> argv[1] = {args[1]};
        cb->Call(Null(isolate), 1, argv);
    }

    //add
    void Add(const FunctionCallbackInfo<Value> &args)
    {
        Isolate *isolate = args.GetIsolate();

        if (args.Length() < 2)
        {
            return;
        }

        double value = args[0]->NumberValue() + args[1]->NumberValue();

        Local<Number> num = Number::New(isolate, value);
        args.GetReturnValue().Set(num);
    }

    void init(Local<Object> exports)
    {
        NODE_SET_METHOD(exports, "hello", Method1);
        NODE_SET_METHOD(exports, "addOne", Method2);

        //callback
        NODE_SET_METHOD(exports, "callthis", CallThis); // we'll create Add in a moment...
        NODE_SET_METHOD(exports, "callthis_withthis", CallThisWithThis);
        //add
        NODE_SET_METHOD(exports, "add", Add);
    }

    NODE_MODULE(addon, init)
} // namespace demo