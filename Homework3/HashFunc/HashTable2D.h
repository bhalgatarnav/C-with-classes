#ifndef HASHTABLE2D_H
#define HASHTABLE2D_H
using namespace std;
class HashTable2D {
private:
    static const int SIZE = 100;
    static const int SLOT_CAPACITY = 5;

    // key: idx and respective values are stored at that index
    int table[SIZE][SLOT_CAPACITY];

    // This is a list tracking if an element is present at that index or not.
    // @type boolean Size= 100 x 5
    bool occupied[SIZE][SLOT_CAPACITY];

public:
    // Constructor
    HashTable2D() {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SLOT_CAPACITY; ++j) {
                table[i][j] = -1;
                occupied[i][j] = false;
            }
    }

    // Destructor
    ~HashTable2D() {}

    int insert(int x, std::string r) {
        if (search(x, "i")>0) {
            if (r == "a")
                return 1;
            else
                return -1;
        }
        // SIZE = 100
        int index = x % SIZE;
        int attempts = 0;
        std::vector<int> myList;
        // i:- 0, 1, 2, 3, 4

        /** Understanding the 2D hash table
         *   0 1 2 3 4
         *  0 * * * * *
         *  1 * * * * *
         *  2 * * * * *
         *  3 * * * * *
         *
         */
        int j = 0;
        // Slot Capacity = 5
        while (j < SLOT_CAPACITY) {
            attempts++;

            // If the slot is empty
            if (occupied[index][j] == false) {
                table[index][j] = x;
                occupied[index][j] = true;

                if (r == "a") {
                    return attempts;
                } else {
                    return index;
                }
            }

            j++;
        }

        // Handle the case where no empty slot is found
        if (r == "a") {
            return attempts;
        } else {
            return -1;
        }
    }


    int search(int x,std::string r) {
        int index = x % SIZE;
        int attempts = 0;

        int j = 0;
        while (j < SLOT_CAPACITY) {
            attempts++;
            if (occupied[index][j] && table[index][j] == x) {
                if (r == "a")
                    return attempts;
                else
                    return index;
            }
            j++;
        }
        if (r == "a")
            return attempts;
        else
            return -1;
    }


    int remove(int x, std::string r) {
        int index = x % SIZE;
        int attempts = 0;

        int j = 0;
        while (j < SLOT_CAPACITY) {
            attempts++;
            if (occupied[index][j] && table[index][j] == x) {

                occupied[index][j] = false;
                table[index][j] = 0;

                if (r == "a")
                    return attempts;
                else
                    return index;
            }
            j++;
        }

        if (r == "a")
            return attempts;
        else
            return -1;
    }

    // Print function
    void print() {
        for (int i = 0; i < SIZE; ++i) {
            cout << "Slot " << i << ": ";
            for (int j = 0; j < SLOT_CAPACITY; ++j) {
                if (occupied[i][j])
                    cout << table[i][j] << " ";
                else
                    cout << "[empty] ";
            }
            cout << endl;
        }
    }
};
#endif //HASHTABLE2D_H
