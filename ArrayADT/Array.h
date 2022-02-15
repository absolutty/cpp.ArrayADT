#include <iostream>

#pragma once
using namespace std;
class Array
{
private:
    int* aPole;
    int aSize;
    int aLength;

    //urcuje ci uz pole BOLO usporiadane (atr. sluzi pre binarySearch)
    bool aJeUsporiadane;

public:
    Array(int* pole, int size, int length) {
        aPole = pole;
        aSize = size;
        aLength = length;
        aJeUsporiadane = false;
    }

    void display();                                     // ✔ funguje

    void append(int pridavanyPrvok);                    // ✔ funguje
    void insert(int index, int vkladanyPrvok);          // ✔ funguje
    int vymaz(int index);                               // ✔ funguje
    int get(int index);                                 // ✔ funguje
    void set(int index, int hodnota);                   // ✔ funguje

    int max();                                          // ✔ funguje
    int min();                                          // ✔ funguje
    int sum();                                          // ✔ funguje
    double avg();                                       // ✔ funguje

    void reverse();                                     // ✔ funguje
    void shiftLeft();                                   // ✔ funguje
        
    void insertInSorted(int vkladaneCislo);             // ✔ funguje
    bool isSorted();                                    // ✔ funguje

    void negativeLeftPositiveRight();

    friend struct overenie;
    friend class Search;
    friend class Operations;
};

struct overenie {
    //overi ci zadavany index je v rosahu daneho pola
    static void rozsah(const Array& arr, int index) {
        if (index < 0 || index >= arr.aSize) {
            throw out_of_range("Index je mimo rozsahu!");
        }
    }
    //overi ci pole NIE JE plne, to zn. ze prvky je mozne: append, insert
    static void velkost(const Array& arr) {
        if (arr.aLength == arr.aSize) {
            throw length_error("Array je uz plna!");
        }
    }

};



