#include "Array.h"
#include "Search.h"
#include <algorithm>

#pragma once
class Operations
{
public:
	//trvanie- O(m+n), kde m je velkost prvej arr, n je velkost druhej arr
	static Array* merge(Array& arr1, Array& arr2) {
		// polia musia byt najskor usporiadane
		if (!arr1.aJeUsporiadane) { sort(arr1.aPole, arr1.aPole + arr1.aLength); arr1.aJeUsporiadane = true; }
		if (!arr2.aJeUsporiadane) { sort(arr2.aPole, arr2.aPole + arr2.aLength); arr2.aJeUsporiadane = true; }

		int novaVelkost = arr1.aLength + arr2.aLength;
		Array* spojenaArr = new Array(new int[novaVelkost] {0}, novaVelkost, 0);

		int i = 0, j = 0, k = 0;
		while (i < arr1.aLength && j < arr2.aLength) {
			if (arr1.get(i) < arr2.get(j))
				spojenaArr->set(k++, arr1.get(i++));
			else
				spojenaArr->set(k++, arr2.get(j++));
		}

		//ak v arr1 ostali nejake prvky, su pridane do spojenaArr
		for (; i < arr1.aLength; i++)
			spojenaArr->set(k++, arr1.get(i));

		//ak v arr2 ostali nejake prvky, su pridane do spojenaArr
		for (; j < arr2.aLength; j++)
			spojenaArr->set(k++, arr2.get(j));

		return spojenaArr;
	}

	//SET OPERATIONS
	/*
	patria sem:
		- Union
		- Intersection
		- Difference
	*/

	//trvanie- m+m*n -> n+n*n -> O(n^2)
	static Array* Union(Array& arr1, Array& arr2) {
		int novaVelkost = arr1.aLength + arr2.aLength;
		Array* spojenaArr = new Array(new int[novaVelkost] {0}, novaVelkost, 0);

		//najprv je potrebne pridat arr1
		int i = 0;
		for (; i < arr1.aLength; i++) {
			spojenaArr->set(i, arr1.get(i));
		}

		cout << "arr1: "; arr1.display();
		cout << "arr2: "; arr2.display();
		cout << "spojena: "; spojenaArr->display();
		cout << "-----------------" << endl;

		//pridanie arr2, ak sa prvky rovnaju nie je pridany duplikativne
		int j = 0;
		for (; j < arr2.aLength; j++) {
			int pridavanyKey = arr2.get(j);

			try {
				Search::linearSearch(arr1, pridavanyKey);
			}
			catch (invalid_argument) { //key sa NENACHADZA, mozne sa pridat do spojenaArr
				spojenaArr->set(i, pridavanyKey);
				i++;
			}
		}

		return spojenaArr;
	}

	//najprv polia usporiada (ak nie su), potom vykoná union
	//trvanie- m+n -> n+n -> 2n -> O(n)
	static Array* UnionSorted(Array& arr1, Array& arr2) {
		// polia musia byt najskor usporiadane
		if (!arr1.aJeUsporiadane) { sort(arr1.aPole, arr1.aPole + arr1.aLength); arr1.aJeUsporiadane = true; }
		if (!arr2.aJeUsporiadane) { sort(arr2.aPole, arr2.aPole + arr2.aLength); arr2.aJeUsporiadane = true; }

		int novaVelkost = arr1.aLength + arr2.aLength;
		Array* spojenaArr = new Array(new int[novaVelkost] {0}, novaVelkost, 0);

		int i = 0, j = 0, k = 0;
		while (i < arr1.aLength && j < arr2.aLength) {
			if (arr1.get(i) < arr2.get(j))					//hodnota na LAVO je vacsia
				spojenaArr->set(k++, arr1.get(i++));
			else if (arr1.get(i) > arr2.get(j))				//hodnota na PRAVO je vacsia
				spojenaArr->set(k++, arr2.get(j++));
			else {											//ak sa hodnoty ROVNAJU
				spojenaArr->set(k++, arr1.get(i++));
				j++;
			}

		}

		//ak v arr1 ostali nejake prvky, su pridane do spojenaArr
		for (; i < arr1.aLength; i++)
			spojenaArr->set(k++, arr1.get(i));

		//ak v arr2 ostali nejake prvky, su pridane do spojenaArr
		for (; j < arr2.aLength; j++)
			spojenaArr->set(k++, arr2.get(j));

		return spojenaArr;
	}

	//ret array obsahuje prvky, kt. sa nachadzaju zaroven v obidvoch poliach
	//trvanie- n*m -> O(n^2)
	static Array* intersection(Array& arr1, Array& arr2) {
		int novaVelkost = (arr1.aLength < arr2.aLength) ? (arr1.aLength) : (arr2.aLength);
		Array* novaArr = new Array(new int[novaVelkost] {0}, novaVelkost, 0);

		for (int i = 0; i < arr1.aLength; i++) {
			int prvokArr1 = arr1.get(i);

			for (int j = 0; j < arr2.aLength; j++) {
				int prvokArr2 = arr2.get(j);

				if (prvokArr1 == prvokArr2) {
					novaArr->append(prvokArr1);
					break;
				}
			}
		}

		return novaArr;
	}

	//ret array obsahuje prvky, kt. sa nachadzaju zaroven v obidvoch poliach
	//polia SU USPORIADANE
	//trvanie- m+n -> O(n)
	static Array* intersectionSorted(Array& arr1, Array& arr2) {
		// polia musia byt najskor usporiadane
		if (!arr1.aJeUsporiadane) { sort(arr1.aPole, arr1.aPole + arr1.aLength); arr1.aJeUsporiadane = true; }
		if (!arr2.aJeUsporiadane) { sort(arr2.aPole, arr2.aPole + arr2.aLength); arr2.aJeUsporiadane = true; }

		int novaVelkost = (arr1.aLength < arr2.aLength) ? (arr1.aLength) : (arr2.aLength);
		Array* novaArr = new Array(new int[novaVelkost] {0}, novaVelkost, 0);

		int i = 0, j = 0, k = 0;
		while (i < arr1.aLength && j < arr2.aLength) {
			if (arr1.get(i) < arr2.get(j))
				i++;
			else if (arr1.get(i) > arr2.get(j))
				j++;
			else {
				novaArr->set(k, arr1.get(i));
				i++; j++; k++;
			}
		}

		return novaArr;
	}

	//vrati arr, kt. obsahuje prvky arr1, kt. sa nenachadzaju v arr2 (arr1 - arr2)
	//polia SU USPORIADANE
	//trvanie- m*n -> n*n -> O(n^2)
	static Array* difference(Array& arr1, Array& arr2) {
		int novaVelkost = (arr1.aLength > arr2.aLength) ? (arr1.aLength) : (arr2.aLength);
		Array* novaArr = new Array(new int[novaVelkost] {0}, novaVelkost, 0);

		for (int i = 0; i < arr1.aLength; i++) {
			int kopirovanyPrvok = arr1.get(i);

			try {
				Search::linearSearch(arr2, kopirovanyPrvok);
			}
			catch (invalid_argument) { //prvok sa v arr2 NENACHADZA
				novaArr->append(kopirovanyPrvok);
			}
		}	

		return novaArr;
	}

	//vrati arr, kt. obsahuje prvky arr1, kt. sa nenachadzaju v arr2 (arr1 - arr2)
	//trvanie- m+n -> O(n)
	static Array* differenceSorted(Array& arr1, Array& arr2) {
		// polia musia byt najskor usporiadane
		if (!arr1.aJeUsporiadane) { sort(arr1.aPole, arr1.aPole + arr1.aLength); arr1.aJeUsporiadane = true; }
		if (!arr2.aJeUsporiadane) { sort(arr2.aPole, arr2.aPole + arr2.aLength); arr2.aJeUsporiadane = true; }

		int novaVelkost = (arr1.aLength > arr2.aLength) ? (arr1.aLength) : (arr2.aLength);
		Array* novaArr = new Array(new int[novaVelkost] {0}, novaVelkost, 0);

		int i = 0, j = 0, k = 0;
		while (i < arr1.aLength && j < arr2.aLength) {
			if (arr1.get(i) < arr2.get(j)) {
				novaArr->append(arr1.get(i));
				i++;
			}
			else if (arr2.get(j) < arr1.get(i))
				j++;
			else {
				i++; j++;
			}
		}

		return novaArr;
	}
};

