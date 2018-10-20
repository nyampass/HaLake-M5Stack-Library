#include "ChainArray.h"

void ChainArray::add(std::vector<String> keys, std::vector<String> values){
  for(int i = 0; i < keys.size(); i++){
    addElement(keys[i], values[i]);
  }
}

void ChainArray::add(String key, String value){
  addElement(key, value);
}

void ChainArray::addElement(String key, String value){
  struct chainArray element;

  element.key = key;
  element.value = value;
  chainArrays.push_back(element);
}

std::vector<String> ChainArray::keys(){
  std::vector<String> result;

  for(int i = 0; i < chainArrays.size(); i++){
    result.push_back(chainArrays[i].key);
  }

  return result;
}

void ChainArray::clear(){
  chainArrays.clear();
}

String ChainArray::get(String key){
  for(int i = 0; i < chainArrays.size(); i++){
    if(chainArrays[i].key == key) return chainArrays[i].value;
  }

  return "";
}
