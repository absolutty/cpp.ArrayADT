# ArrayADT
https://lucasmagnum.medium.com/sidenotes-array-abstract-data-type-data-structure-b154140c8305#:~:text=The%20array%20is%20an%20abstract,types%20like%20instances%20of%20classes <br>

- pole je typu **abstract data type** (ADT), čo zn. že obsahuje prvky ku ktorým je možné
pristupovať na základe indexu
- pole ADT môže obsahovať rôzne druhy prvkov (primitívne typy, objekty, etc...)
- v mojom prípade pre jednoduchosť je možné ukladať do pola iba **int**
- (spravil som z dôvodu aby som nemusel riešiť generiká, keďže o to sa tu nejedná)
- každý prvok poľa je uložený na nejakom indexe, z ktorého je možné ho **.get()**
alebo **.set()**
- mnou vytvorená trieda Array na manipuláciu poľa obsahuje tieto metódy:
```cpp
class Array
{
    void display();
    void append(int pridavanyPrvok);
    void insert(int index, int vkladanyPrvok);
    int vymaz(int index);
    int get(int index);
    void set(int index, int hodnota);
    int max();
    int min();
    int sum();
    double avg();
    void reverse();
    void shiftLeft();
    void insertInSorted(int vkladaneCislo);
    bool isSorted();
    void negativeLeftPositiveRight();
}
```
- ďalej je možné vykonávať základné "search" algoritmy:
```cpp
class Search
{
    static int linearSearch(const Array& arr, int key) {...}
    static int binarySearch(Array& arr, int key) {...}
    static int binarySearchRecursive(Array& arr, int key) {...}
}
```
- a ako posledné "Set operations"
```cpp
class Operations
{
    static Array* merge(Array& arr1, Array& arr2) {...}
    static Array* Union(Array& arr1, Array& arr2) {...}
    static Array* UnionSorted(Array& arr1, Array& arr2) {...}
    static Array* intersection(Array& arr1, Array& arr2) {...}
    static Array* intersectionSorted(Array& arr1, Array& arr2) {...}
    static Array* difference(Array& arr1, Array& arr2) {...}
    static Array* differenceSorted(Array& arr1, Array& arr2) {...}
}
```


