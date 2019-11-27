#pragma once

#include <src/pch.hpp>
#include <src/Interpreters/IInterpreter.hpp>

class JSRuntimeInstance : public IInterpreter {
    INTERPRET_STATUSCODE Interpret();
};