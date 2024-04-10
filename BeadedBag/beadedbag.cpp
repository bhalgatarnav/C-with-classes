#include <algorithm>
#include "beadedbag.h"
#include "item.h"
#include <vector>

// Implement the BeadedBag::size and BeadedBag::insert member functions here.

void BeadedBag::insert(Item to_insert){
  if (!this->contains(to_insert)){
  this->bag.push_back(to_insert);
}
}

/**
 * size()
 * Returns the size of the BeadedBag.
 *
 * input: nothing
 * output: @return The size of the BeadedBag.
 */
int BeadedBag::size(){
  return bag.size();
}

/**
 * BeadedBag(...)
 * Checks if the BeadedBag contains a specific item.
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