#ifndef Utils_h
#define Utils_h

#include <Arduino.h>
#include <array>
#include <vector>
#include "ChainArray.h"

class Utils{
  public:
    ChainArray analyzeGetRequest(String request);
    String split(String target, char sep, uint8_t index);
    ChainArray analyzeQuery(String str);
    std::vector<uint8_t> vector_find(std::vector<String> target, String str);
};

#endif
