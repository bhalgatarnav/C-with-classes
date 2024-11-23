#include <gtest/gtest.h>
#include "../HashFunc/HashTable2D.h"

TEST(HashTable2DTest, InsertUniqueValues) {
    HashTable2D ht;
    EXPECT_EQ(ht.insert(10, "i"), 10);
    EXPECT_EQ(ht.insert(20, "i"), 20);
    EXPECT_EQ(ht.search(10, "i"), 10);
    EXPECT_EQ(ht.search(30, "i"), -1);
}

TEST(HashTable2DTest, HandleCollisions) {
    HashTable2D ht;
    ht.insert(5, "i");
    ht.insert(15, "i");
    EXPECT_EQ(ht.search(5, "i"), 5);
    EXPECT_EQ(ht.search(15, "i"), 15);
}

TEST(HashTable2DTest, RemoveValue) {
    HashTable2D ht;
    ht.insert(10, "i");
    ht.insert(20, "i");
    EXPECT_EQ(ht.remove(10, "i"), 10);
    EXPECT_EQ(ht.search(10, "i"), -1);
    EXPECT_EQ(ht.remove(30, "i"), -1);
}

TEST(HashTable2DTest, InsertDuplicateValues) {
    HashTable2D ht;
    ht.insert(10, "i");
    EXPECT_EQ(ht.insert(10, "i"), -1);
}

TEST(HashTable2DTest, HandleEmptyTable) {
    HashTable2D ht;
    EXPECT_EQ(ht.search(1, "i"), -1);
    EXPECT_EQ(ht.remove(1, "i"), -1);
}
