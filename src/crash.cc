#include <node.h>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  char a [1];
    //Create a index
    int i = 0;
    //Infinite loop to go around the compiler
    while(1)
    {
        //Write on case i of a, on the second iteration, it will write in unreserved memory => crash
        a[i] = 0;
        i = i + 1;
    }
  throw "Crash!";
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "crash", Method);
}

NODE_MODULE(crash, init)

}
