#pragma once

#include <src/pch.hpp>
#include <src/Interpreters/IInterpreter.hpp>

#include <vendor/duktape/duktape.h>

class JSRuntimeInstance : public IInterpreter {
    duk_context* ctx;
public:
    JSRuntimeInstance()
    {
        ctx = duk_create_heap_default();
    }
    ~JSRuntimeInstance()
    {
	    duk_destroy_heap(ctx);
    }
    INTERPRET_STATUSCODE Interpret(string & code)
    {
	    duk_eval_string_noresult(ctx, code.c_str());
        return INTERPRET_SUCCES;
    }

    bool RegisterFunction(duk_c_function func, uint args_size, const char* func_name)
    {
	    duk_push_c_function(ctx, func, args_size);
	    duk_put_global_string(ctx, func_name);
        return true;
    }
};