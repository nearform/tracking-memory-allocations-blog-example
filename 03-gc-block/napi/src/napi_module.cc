#include <napi.h>
#include <memory>
#include <iostream>

using namespace Napi;

#define MEM_SIZE_3MB ( 500 * 1024 * 1024 )

char* buffer = nullptr;

Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (buffer == nullptr) {
    std::cout << "Allocating buffer" << std::endl;
    buffer = (char*) malloc(MEM_SIZE_3MB * sizeof(char) );
    for (int i = 0; i < MEM_SIZE_3MB; ++i) {
      buffer[i] = 'A';
    }
    buffer[MEM_SIZE_3MB - 1] = '\0';
  }
  return Napi::String::New(env, buffer);
}

Napi::String FreeBuff(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  free(buffer);
  buffer = nullptr;
  return Napi::String::New(env, "Free");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "NapiModule"),
              Napi::Function::New(env, Method));
  exports.Set(Napi::String::New(env, "FreeBuff"),
              Napi::Function::New(env, FreeBuff));
  return exports;
}

NODE_API_MODULE(addon, Init)
