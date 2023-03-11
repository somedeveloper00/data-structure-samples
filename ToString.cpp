#include "includes.cpp"

namespace ToString {
    std::function<std::string(int)> int2str() {
        return [](int v) { return std::to_string(v); };
    }
    std::function<std::string(float)> float2str() {
        return [](float v) { return std::to_string(v); };
    }
}