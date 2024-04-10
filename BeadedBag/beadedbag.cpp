#include <algorithm>
#include "beadedbag.h"
#include "item.h"
#include <vector>

// Implement the BeadedBag::size and BeadedBag::insert member functions here.

/**
 * insert(..)
 * Inserts an item into the beaded bag if not present already.
 * 
 * input: @param to_insert The item to be inserted.
 * output: nothing
 */
void BeadedBag::insert(Item to_insert){
  if (!this->contains(to_insert)){
  this->bag.push_back(to_insert);
}
}

/**
 * size()
 * This function will return the number of Items in the Beaded Bag.
 *
 * input: nothing
 * output: @return The size of the BeadedBag.
 */
int BeadedBag::size(){
  return bag.size();
}

/**
 * contains(...)
 * This function will return true if maybe_contained_item is already present in the Beaded Bag; 
 * it will return false otherwise.
 * 
 * input: @param maybe_contained_item The item to check for.
 * output: @return True if the item is found in the bag, false otherwise.
 */
bool BeadedBag::contains(Item maybe_contained_item) {
  for (auto item : bag) {
    if (item.isEqual(maybe_contained_item)) {
      return true;
    }
  }
  return false;
}