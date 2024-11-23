#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "../HashFunc/HashTableLP.h"
#include "../HashFunc/HashTable2D.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    // Step 1: Generate a list of 100 random, unique integers between 1 and 1000
    vector<int> dataset;
    while (dataset.size() < 100) {
        int num = rand() % 1000 + 1;
        if (find(dataset.begin(), dataset.end(), num) == dataset.end()) {
            dataset.push_back(num);
        }
    }

    vector<int> first_50(dataset.begin(), dataset.begin() + 50);
    vector<int> remaining_50(dataset.begin() + 50, dataset.end());

    // Step 2: Initialize hash tables
    HashTableLP ht1d;
    HashTable2D ht2d;

    int at1D, idx1D;
    int at2D, idx2D;

    cout << "\nInserting 50 integers in the hash table\n"<<endl;
    // Initial Insertion
    int spots_checked_1d = 0, spots_checked_2d = 0;
    for (int value : first_50) {

        at1D = ht1d.insert(value, "a");
        idx1D = ht1d.insert(value, "i");

        at2D = ht2d.insert(value, "a");
        idx2D = ht2d.insert(value, "i");

        spots_checked_1d += at1D;
        spots_checked_2d += at2D;

        cout << "LP) Value Inserted: " << value <<" Index of insertion: "<< idx1D <<" Attempts taken: "<< at1D << endl;
        cout << "2D) Value Inserted: " << value <<" Index of insertion: "<< idx2D <<" Attempts taken: "<< at2D << endl;
        cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    }
    cout << "\nInitial insertion - Spots checked: 1D = " << spots_checked_1d
         << ", 2D = " << spots_checked_2d << endl;
    cout <<"*******************************************"<< endl;

    // Selective Removal
    cout << "\n\nRemoving values which are divisible by 7\n" << endl;
    cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    spots_checked_1d = spots_checked_2d = 0;
    for (int value : first_50) {
        if (value % 7 == 0) {
            at1D = ht1d.remove(value, "a");
            idx1D = ht1d.remove(value, "i");
            spots_checked_1d += at1D;
            cout << "LP) Value removed: " << value <<" Index of value removed "<< idx1D <<" Attempts taken: "<< at1D << endl;


            at2D = ht2d.remove(value, "a");
            idx2D = ht2d.remove(value, "i");
            spots_checked_2d += at2D;
            cout << "2D) Value removed: " << value <<" Index of value removed "<< idx2D <<" Attempts taken: "<< at2D << endl;
            cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
        }
    }
    cout << "\nSelective removal - Spots checked: 1D = " << spots_checked_1d
         << ", 2D = " << spots_checked_2d << endl;
    cout <<"*******************************************"<< endl;

    // Second Insertion
    spots_checked_1d = spots_checked_2d = 0;
    for (int value : remaining_50) {
        spots_checked_1d += ht1d.insert(value, "a");
        spots_checked_2d += ht2d.insert(value, "a");
    }
    cout << "\nSecond insertion - Spots checked: 1D = " << spots_checked_1d
         << ", 2D = " << spots_checked_2d << endl;
    cout <<"*******************************************\n"<< endl;

    // Search Operation
    cout<<"\nSearching integers that are divisible by 9 :-"<< endl;
    cout <<"*******************************************\n"<< endl;
    spots_checked_1d = spots_checked_2d = 0;
    for (int value : dataset) {
        if (value % 9 == 0) {
            at1D = ht1d.search(value, "a");
            idx1D = ht1d.search(value, "i");
            spots_checked_1d += at1D;
            cout << "LP) Value: " << value << " Index: "<< idx1D << " Attempts: "<< at1D<< endl;

            at2D = ht2d.search(value, "a");
            idx2D = ht2d.search(value, "i");
            spots_checked_1d += at1D;
            cout << "2D) Value: " << value << " Index: "<< idx2D << " Attempts: "<< at2D<< endl;

            cout <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
        }
    }
    cout << "\nSearch operation - Spots checked: 1D = " << spots_checked_1d
         << ", 2D = " << spots_checked_2d << endl;
    cout <<"*******************************************"<< endl;
    return 0;
}
