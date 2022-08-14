#pragma once

typedef void (*ByteEventCallback)(void* p_this, long long callback_time_since_epoch, const char* func_name, const char* json);

#define JSON_INDENT 4
#define STR(str) (str?str:"")

#define CALLBACK_BLOCK_BEGIN     \
    if (_callback)\
    {\
        std::string func_name{ __FUNCTION__ };\
        func_name = func_name.substr(func_name.rfind(':') + 1);

#define CALLBACK_BLOCK_END      \
        _callback(this, EpochMicroseconds(), func_name.c_str(), json_str.c_str());\
    }
