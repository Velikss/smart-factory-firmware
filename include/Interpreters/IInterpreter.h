#pragma once
#include <pch.hpp>

class IInterpreter {
    public:
    virtual INTERPRET_STATUSCODE Interpret(string &code) = 0;

};