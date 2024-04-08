#include <string>
#include "item.h"

Item::Item(const std::string &item_name): m_name(item_name) {}

std::string Item::getName() {
  return "";
}

bool Item::isEqual(Item other_item) {
  return false;
}