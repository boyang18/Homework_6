#include "ArrayDictionary.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dict, contain) {
// homework
    //set 1:
    ArrayDictionary<int, int> hashTableEmpty;
    ASSERT_FALSE(hashTableEmpty.contain(-1));
    ASSERT_FALSE(hashTableEmpty.contain(0));
    ASSERT_FALSE(hashTableEmpty.contain(1));

    //set 2:
    ArrayDictionary<int, int> hashTable1(1);
    ASSERT_TRUE(hashTable1.add(0,103));
    ASSERT_TRUE(hashTable1.contain(0));
    ASSERT_FALSE(hashTable1.contain(2));

    //set 3:
    ArrayDictionary<int, int> hashTable2(2);
    ASSERT_TRUE(hashTable2.add(0,103));
    ASSERT_TRUE(hashTable2.add(1,105));
    ASSERT_TRUE(hashTable2.contain(0));
    ASSERT_TRUE(hashTable2.contain(1));
    ASSERT_FALSE(hashTable2.contain(2));
    ASSERT_FALSE(hashTable2.contain(3));

    //set 4
    ArrayDictionary<int, int> hashTable3(3);
    ASSERT_TRUE(hashTable3.add(0,103));
    ASSERT_TRUE(hashTable3.add(1,105));
    ASSERT_FALSE(hashTable3.contain(3));
    ASSERT_TRUE(hashTable3.add(2,206));
    ASSERT_TRUE(hashTable3.contain(1));

    //set 5
    ArrayDictionary<int, int> hashTable4(3);
    ASSERT_TRUE(hashTable4.add(0,103));
    ASSERT_TRUE(hashTable4.add(1,105));
    ASSERT_TRUE(hashTable4.add(2,206));
    ASSERT_TRUE(hashTable4.add(4,407));
    ASSERT_TRUE(hashTable4.contain(1));
    ASSERT_TRUE(hashTable4.contain(4));
    ASSERT_FALSE(hashTable4.contain(7));
    ASSERT_FALSE(hashTable4.contain(8));
}

TEST(dict, remove) {
    // homework
    //set 1:
    ArrayDictionary<int, int> hashTableEmpty;
ASSERT_FALSE(hashTableEmpty.remove(-1));
ASSERT_FALSE(hashTableEmpty.remove(0));
ASSERT_FALSE(hashTableEmpty.remove(1));

//set 2:
ArrayDictionary<int, int> hashTable1(1);
ASSERT_TRUE(hashTable1.add(0,103));
ASSERT_TRUE(hashTable1.remove(0));
ASSERT_FALSE(hashTable1.remove(2));

//set 3:
ArrayDictionary<int, int> hashTable2(2);
ASSERT_TRUE(hashTable2.add(0,103));
ASSERT_TRUE(hashTable2.add(1,105));
ASSERT_TRUE(hashTable2.remove(0));
ASSERT_TRUE(hashTable2.remove(1));
ASSERT_FALSE(hashTable2.remove(2));
ASSERT_FALSE(hashTable2.remove(3));

//set 4
ArrayDictionary<int, int> hashTable3(3);
ASSERT_TRUE(hashTable3.add(0,103));
ASSERT_TRUE(hashTable3.add(1,105));
ASSERT_FALSE(hashTable3.remove(3));
ASSERT_TRUE(hashTable3.add(2,206));
ASSERT_TRUE(hashTable3.remove(1));

//set 5
ArrayDictionary<int, int> hashTable4(3);
ASSERT_TRUE(hashTable4.add(0,103));
ASSERT_TRUE(hashTable4.add(1,105));
ASSERT_TRUE(hashTable4.add(2,206));
ASSERT_TRUE(hashTable4.add(4,407));
#ifdef PRINT
hashTable4.print();
#endif
ASSERT_TRUE(hashTable4.remove(4));
ASSERT_TRUE(hashTable4.remove(1));
ASSERT_FALSE(hashTable4.remove(7));
ASSERT_FALSE(hashTable4.remove(8));
#ifdef PRINT
hashTable4.print();
#endif
}
