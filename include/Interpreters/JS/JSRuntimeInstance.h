#pragma once

#include <pch.hpp>
#include <Interpreters/IInterpreter.h>

class JSRuntimeInstance : public IInterpreter {
    INTERPRET_STATUSCODE Interpret();
};