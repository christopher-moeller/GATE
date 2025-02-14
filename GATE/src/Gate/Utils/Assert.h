#pragma once

#include "Gate/Utils/Logger.h"

#define TEST_DEBUG

#ifdef TEST_DEBUG
    #ifdef GATE_PLATFORM_MACOS
        #define GATE_ASSERT(x, ...) { if(!(x)) { GATE_LOG_ERROR("Assertion Failed {}", __VA_ARGS__); __builtin_debugtrap(); } }
    #elif defined GATE_PLATFORM_ANDROID
        #define GATE_ASSERT(x, ...) { if(!(x)) { GATE_LOG_ERROR("Assertion Failed {}", __VA_ARGS__); __builtin_trap(); } }
    #else
        #define GATE_ASSERT(x, ...) { if(!(x)) { GATE_LOG_ERROR("Assertion Failed {}", __VA_ARGS__); } }
    #endif
#else
    #define GATE_ASSERT(x, ...)
#endif
