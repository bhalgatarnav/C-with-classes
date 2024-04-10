#ifndef __BEADEDBAG_BEADEDBAG_HPP
#define __BEADEDBAG_BEADEDBAG_HPP

#include "item.h"
#include <vector>

class BeadedBag {
public:
  /**
   * Insert an Item into the Beaded Bag as long as it is not already present.
   * @param Input the Item to be inserted
   * @param Output nothing
  */
  
  void insert (Item  to_insert);
  
  /**
   * Insert an Item into the Beaded Bag as long as it is not already present.
   * @param Input nothing
   * @param Output the number of Items in the Beaded Bag
  */
  int size ();
  
  // Here's the declaration for contains, to get you started:
  bool contains(Item maybe_contained_item);

/**
 * The vector that stores the items in the Beaded Bag.
 * The internals of the type are hidden from the user and the user doesn't care what happens behind the curtain!
 * 
*/
private:
  std::vector<Item> bag;
};

#endif