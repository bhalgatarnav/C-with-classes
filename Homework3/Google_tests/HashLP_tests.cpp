#include <gtest/gtest.h>
#include "../HashFunc/HashTableLP.h"

TEST(HashTableLPTest, InsertUniqueValues) {
    HashTableLP ht;
    EXPECT_EQ(ht.insert(10, "i"), 10);
    EXPECT_EQ(ht.insert(20, "i"), 20);
    EXPECT_EQ(ht.search(10, "i"), 10);
    EXPECT_EQ(ht.search(30, "i"), -1);
}

TEST(HashTableLPTest, HandleCollisions) {
    HashTableLP ht;
    ht.insert(501, "i");
    ht.insert(1, "i");
    EXPECT_EQ(ht.search(501, "i"), 1);
    EXPECT_EQ(ht.search(1, "i"), 2);
}

TEST(HashTableLPTest, RemoveValue) {
    HashTableLP ht;
    ht.insert(10, "i");
    ht.insert(20, "i");
    EXPECT_EQ(ht.remove(10, "i"), 10);
    EXPECT_EQ(ht.search(10, "i"), -1);
    EXPECT_EQ(ht.remove(30, "i"), -1);
}

TEST(HashTableLPTest, InsertDuplicateValues) {
    HashTableLP ht;
    ht.insert(10, "i");
    EXPECT_EQ(ht.insert(10, "i"), -1);
}

TEST(HashTableLPTest, HandleEmptyTable) {
    HashTableLP ht;
    EXPECT_EQ(ht.search(1, "i"), -1);
    EXPECT_EQ(ht.remove(1, "i"), -1);
}
