#pragma once

#include "Application.h"

#define GATE_LOG_INFO(...)    ::Gate::Application::Get()->GetLogger()->Info(__VA_ARGS__)
#define GATE_LOG_ERROR(...)    ::Gate::Application::Get()->GetLogger()->Error(__VA_ARGS__)

#define TEST_DEBUG

#ifdef TEST_DEBUG
    #ifdef GATE_PLATFORM_MACOS
        #define GATE_ASSERT(x, ...) { if(!(x)) { GATE_LOG_ERROR("Assertion Failed {}", __VA_ARGS__); __builtin_debugtrap(); } }
    #elif defined GATE_PLATFORM_ANDROID
        #define GATE_ASSERT(x, ...) { if(!(x)) { GATE_LOG_ERROR("Assertion Failed {}", __VA_ARGS__); __builtin_debugtrap(); } }
    #else
        #define GATE_ASSERT(x, ...) { if(!(x)) { GATE_LOG_ERROR("Assertion Failed {}", __VA_ARGS__); } }
    #endif
#else
    #define GATE_ASSERT(x, ...)
#endif
