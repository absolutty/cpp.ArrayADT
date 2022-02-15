#include "Array.h"
#include <algorithm>

void Array::display()
{
    cout << "Array ma nieto prvky: [ ";
    for (int i = 0; i < aSize; i++) {
        cout << aPole[i] << ", ";
    } cout << "]" << endl;
}

void Array::append(int pridavanyPrvok)
{
    overenie::velkost(*this);

    aPole[aLength] = pridavanyPrvok;
    aLength++;

    aJeUsporiadane = false;
}

void Array::insert(int index, int vkladanyPrvok)
{
    overenie::rozsah(*this, index);
    overenie::velkost(*this);

    //posun cisiel
    for (int i = aLength; i > index; i--) {
        aPole[i] = aPole[i - 1];
    }

    aPole[index] = vkladanyPrvok;
    aLength++;

    aJeUsporiadane = false;
}

int Array::vymaz(int index)
{
    overenie::rozsah(*this, index);

    int vymazavaneCislo = aPole[index];
    //posun cisel
    for (int i = index; i < aLength - 1; i++) {
        aPole[i] = aPole[i + 1];
    }

    aPole[aLength - 1] = 0; //vymazanie posledneho prvku 
    aLength--;

    aJeUsporiadane = false;
    return vymazavaneCislo;
}

int Array::get(int index)
{
    overenie::rozsah(*this, index);

    return aPole[index];
}

void Array::set(int index, int hodnota)
{
    overenie::rozsah(*this, index);

    aPole[index] = hodnota;
}

int Array::max()
{
    int x = aPole[0];

    for (int i = 1; i < aLength; i++) {
        if (aPole[i] > x) {
            x = aPole[i];
        }
    }

    return x;
}

int Array::min()
{
    int x = aPole[0];

    for (int i = 1; i < aLength; i++) {
        if (aPole[i] < x) {
            x = aPole[i];
        }
    }

    return x;
}

int Array::sum()
{
    int sum = 0;

    for (int i = 0; i < aLength; i++) {
        sum += aPole[i];
    }

    return sum;
}

double Array::avg()
{
    return (double)sum() / aLength;
}

void Array::reverse()
{
    int j = aLength-1;
    for (int i = 0; i < j; i++) {
        int temp = aPole[i];
        aPole[i] = aPole[j];
        aPole[j] = temp;

        j--;
    }
}

void Array::shiftLeft()
{
    for (int i=1; i<aLength; i++) {
        aPole[i-1] = aPole[i];
    }

    aPole[aLength - 1] = 0;    //treba vymazat NOVY posledny prvok arr, pretoze je na indexe A[i-1]
    aLength--;
}

void Array::insertInSorted(int vkladaneCislo)
{
    overenie::velkost(*this);

    if (!aJeUsporiadane) { //pole je najprv potreba USPORIADAT vzostupne (ak este nie je... atr aJeUsporiadane)
        sort(aPole, aPole + aLength);
        aJeUsporiadane = true;
    }

    int i = aLength - 1;
    while (i>=0 && aPole[i]>vkladaneCislo) {
        aPole[i + 1] = aPole[i];
        i--;
    }
    aPole[i+1] = vkladaneCislo;
    aLength++;

}

bool Array::isSorted()
{
    for (int i = 0; i < aLength-1; i++) {
        if (aPole[i + 1] < aPole[i]) {
            return false;
        }
    }

    return true;
}

void Array::negativeLeftPositiveRight()
{
    int i = 0, j = (aLength-1);

    while (i < j) {
        while (aPole[i] < 0) { //hladanie KLADNEHO cisla
            i++;
        }
        while (aPole[j] >= 0) { //hladanie ZAPORNEHO cisla
            j--;
        }

        if (i < j) {
            int temp = aPole[i];
            aPole[i] = aPole[j];
            aPole[j] = temp;
        }
    }
}
