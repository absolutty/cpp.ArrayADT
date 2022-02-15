#include <algorithm>
#include "Array.h"

#pragma once
class Search
{
private:
	static int binarySearchRecursive(int low, int high, Array& arr, int key) {
		if (low <= high) {
			int mid = (low + high) / 2;
			int porovnavanaHodnota = arr.aPole[mid]; 

			if (key == porovnavanaHodnota) {
				return mid;
			}
			else {
				if (key < porovnavanaHodnota) //prezeraj LAVU stranu pola
					return binarySearchRecursive(low, high - 1, arr, key);
				
				else //prezeraj PRAVU stranu pola
					return binarySearchRecursive(mid + 1, high, arr, key);
				
			}
		}
		else { //hodnota nebola najdena
			return -1;
		}
	}

public:
	static int binarySearchRecursive(Array& arr, int key) {
		if (!arr.aJeUsporiadane) { //pole je najprv potreba USPORIADAT vzostupne (ak este nie je... atr aJeUsporiadane)
			sort(arr.aPole, arr.aPole + arr.aLength);
			arr.aJeUsporiadane = true;
		}

		int low = 0, mid, high = arr.aLength - 1;
		return binarySearchRecursive(low, high, arr, key);
	}

	//trvanie- min: O(1), max: O(log(n))
	static int binarySearch(Array& arr, int key) {
		if (!arr.aJeUsporiadane) { //pole je najprv potreba USPORIADAT vzostupne (ak este nie je... atr aJeUsporiadane)
			sort(arr.aPole, arr.aPole + arr.aLength);
			arr.aJeUsporiadane = true;
		}

		int low = 0, mid, high = arr.aLength - 1;
		mid = (low + high) / 2;

		while (low <= high) {
			int porovnavanaHodnota = arr.aPole[mid];

			if (porovnavanaHodnota == key) { //uspesne NAJDENIE hladaneho elementu
				return mid;
			}
			else {
				if (key < porovnavanaHodnota) //prezeraj LAVU stranu pola
					high = mid - 1;
				
				else // prezeraj PRAVU stranu pola
					low = mid + 1;
				
				mid = (low + high) / 2;
			}
		}
		throw invalid_argument("Takyto prvok sa v poli nenachadza!");
	}

	//trvanie- min: O(1), max: O(n)
	static int linearSearch(const Array& arr, int key) {
		for (int i = 0; i < arr.aLength; i++) {
			if (key == arr.aPole[i]) {
				//Metóda Transposition - improving linear search
				//ak je h¾adaný key najdený, jeho pozícia sa vymení z jeho predchádzajúcim
				//pri opakovanom vyh¾adávaní toho istého èísla, trvanie nájdenia sa zmenšuje o jeden prvok po¾a

				if (i == 0) { //key najdeny na prvom indexe, nema sa uz kde posunut dolava
					return i;
				}
				else { 
					int temp, a = arr.aPole[i], b = arr.aPole[i - 1];
					temp = a; a = b; b = temp; //vymena dvoch cisel
					arr.aPole[i] = a; arr.aPole[i - 1] = b; //pridelenie cisel na svoju novu poziciu

					return i - 1;
				}
			}
		}

		throw invalid_argument("Takyto prvok sa v poli nenachadza!");
	}
};

