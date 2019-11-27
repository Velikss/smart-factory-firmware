#include <iostream>

#include <src/pch.hpp>
#include <src/Interpreters/JS/JSRuntimeInstance.hpp>
static duk_ret_t native_print(duk_context *ctx) 
{
  printf("%s\n", duk_to_string(ctx, 0));
  return 0;  /* no return value (= undefined) */
}
int main() {
    JSRuntimeInstance instance;
    instance.RegisterFunction(native_print, 1, "log");
    string code = "for(i = 0; i < 10; i+= ++i - --i) { log(i) }";
    instance.Interpret(code);
};