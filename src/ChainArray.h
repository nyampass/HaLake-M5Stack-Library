#ifndef ChainArray_h
#define ChainArray_h

#include <Arduino.h>
#include <vector>

class ChainArray{
  public:
    String get(String key);
    void add(std::vector<String> keys, std::vector<String> values);
    void add(String key, String value);
    std::vector<String> keys();
    void clear();

  private:
    void addElement(String key, String value);
    struct chainArray{
      String key = "";
      String value = "";
    };
    std::vector<struct chainArray> chainArrays;
};

#endif
