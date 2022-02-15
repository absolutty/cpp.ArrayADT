#include <iostream>
#include "Array.h"
#include "Operations.h"


//Array as ADT --> Abstract Data Type
int main()
{
   
    Array A(new int[5]{ 3, 4, 5, 6, 10 }, 5, 5);
    Array B(new int[5]{ 2, 4, 5, 7, 12 }, 5, 5);

    Array novaArray = *Operations::differenceSorted(A, B);
    novaArray.display();

    return 0;
}