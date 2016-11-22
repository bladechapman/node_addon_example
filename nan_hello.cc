// using NAN
#include <nan.h>
#include <iostream>

void FibonacciMethod(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  int number = args[0]->IntegerValue();
  int ret = 0;

  if (number != 0) {
    int pre = 0;
    ret = 1;
    for (int i = 1; i < number; i++) {
      int temp = ret + pre;
      pre = ret;
      ret = temp;
    }
  }

  args.GetReturnValue().Set(Nan::New(ret));
}

void HelloWorldMethod(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Nan::New("hello world!").ToLocalChecked());
}

// Entry point for the module
// takes up to two arguments. the first is ```exports```, which is the same as
// module.exports. The second is ```module```, which is the same as
// ```module``` in a js file
//
// FunctionTemplate turns a regular C++ function into a compatible V8-callable
// function
void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("nan_hello").ToLocalChecked(),
              Nan::New<v8::FunctionTemplate>(HelloWorldMethod)->GetFunction());
  exports->Set(Nan::New("nan_fibonacci").ToLocalChecked(),
              Nan::New<v8::FunctionTemplate>(FibonacciMethod)->GetFunction());
}

// Entry point for the node addon, tells Node where to go once the libraray has
// been loaded into active memory. The first argument must match the target in
// binding.gyp. The second argument points to the function to invoke.
NODE_MODULE(nan_addon, Init)
