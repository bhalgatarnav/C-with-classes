#ifndef __BEADEDBAG_ITEM_HPP
#define __BEADEDBAG_ITEM_HPP

#include <string>

class Item {
public:
  Item(const std::string &item_name);
  std::string getName();
  bool isEqual(Item other);

/**
 * The member variable m_name is declared as private in the Item class for encapsulation purposes. 
 * Encapsulation is a fundamental principle of object-oriented programming that aims to hide the internal implementation details of a class and provide controlled access to its members.
 * By declaring m_name as private, it cannot be accessed directly from outside the class. 
 * Instead, it can only be accessed through public member functions such as getName(). 
 * This allows the class to maintain control over how the member variable is accessed and modified, ensuring data integrity and providing a consistent interface for interacting with the class.
 * Encapsulating the member variable also provides flexibility in terms of implementation changes. If, in the future, you decide to modify the internal representation of m_name or add additional logic, you can do so without affecting the code that uses the Item class.
*/
private:
  std::string m_name;
};

#endif