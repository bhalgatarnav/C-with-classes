#ifndef HASHTABLELP_H
#define HASHTABLELP_H
using namespace std;

class HashTableLP {
private:
    static const int TABLE_SIZE = 500;
    int table[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

public:
    HashTableLP() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            // key: idx and respective values are stored at that index
            table[i] = -1;

            // This is a list tracking if an element is present at that index or not.
            // @type boolean
            occupied[i] = false;
        }
    }

    ~HashTableLP() {}

    // Returns a vector with attempts at the first index and key value at second index.

    int insert(int x, std::string r) {
        if (search(x, "i")>0) {
            if (r == "a")
                return 1;
            else
                return -1;
        }

        // index = x mod 500
        int index = x % TABLE_SIZE;
        int originalIndex = index;
        int attempts = 0;
        std::vector<int> myList;

        // This 'While Loop' implements Linear Probing Logic
        /**
         * Linear probing is a collision resolution technique used in hash tables.
         * When a key-value pair hashes to an already occupied slot, linear probing searches for the next available
         * slot by checking subsequent slots in a sequential manner
         *
         * If a key hashes to index 3, but index 3 is occupied, the algorithm checks index 4, then 5, and so on.
         * If the table wraps around, it continues from the beginning.
         *
         * This while loop interates index linearly to find the next empty slot in the hash table.
         */
        while (occupied[index]) {
            attempts++;
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {

                if (r == "a")
                    return attempts;
                else
                    return -1;
            }
        }

        table[index] = x;
        occupied[index] = true;
        attempts++;


        if (r == "a")
            return attempts;
        else
            return index;
    }

    // Search function
    int search(int x, std::string r) {
        int index = x % TABLE_SIZE;
        int originalIndex = index;
        int attempts = 0;

        while (occupied[index]) {
            attempts++;
            // attempts makes sure about the efficiency of the algorithm
            if (table[index] == x) {

                if (r == "a")
                    return attempts;
                else
                    return index;
            }

            // originalIndex checks if the complete round is complete and same index reappears.
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                break;
            }
        }
        if (r == "a")
            return attempts;
        else
            return -1;


    }


    int remove(int x, std::string r) {
        int index = x % TABLE_SIZE;
        int originalIndex = index;
        int attempts = 0;

        while (occupied[index]) {
            attempts++;

            if (table[index] == x) {

                // removing that value at certain key.
                table[index] = -1;
                occupied[index] = false;


                int nextIndex = (index + 1) % TABLE_SIZE;

                while (occupied[nextIndex]) {
                    // extracting value at that index
                    int rehashValue = table[nextIndex];

                    // Clears the next index
                    table[nextIndex] = -1;
                    occupied[nextIndex] = false;

                    // Inserting that value.
                    insert(rehashValue, "i");

                    // Iterating nextIndex
                    nextIndex = (nextIndex + 1) % TABLE_SIZE;
                }

                if (r == "a")
                    return attempts;
                else
                    return index;
            }


            index = (index + 1) % TABLE_SIZE;


            if (index == originalIndex) {
                break;
            }
        }
        if (r == "a")
            return attempts;
        else
            return -1;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (occupied[i]) {
                cout << "Slot " << i << ": " << table[i] << endl;
            } else {
                cout << "Slot " << i << ": Empty\n";
            }
        }
    }

};


#endif //HASHTABLELP_H
