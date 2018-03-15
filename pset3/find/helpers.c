/**************************************************************************** 
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/

#include <cc50.h>
#include <stdio.h>
#include "helpers.h"

/*
 * Returns true if value is in array of n values, else false.
 */

/* Código Original

bool 
search(int value, int array[], int n)
{
	// TODO: re-implement as binary search
	for (int i = 0; i < n; i++)
		if (array[i] == value)
			return true;
	return false;
}

*/

bool 
search(int value, int array[], int n)
{
	int inf = 0, sup = n-1, meio;
	while (inf <= sup) {
		meio = (inf+sup)/2;
		if (value == array[meio])
			return true;
		if (value < array[meio])
			sup = meio-1;
		else
			inf = meio+1;
	}
	return false;
}

/*
 * Sorts array of n values.
 */

void 
sort(int values[], int n)
{
	// TODO: implement an O(n^2) sort
	int i, j, men, aux;
	for (i = 0; i < n; i++) {
		men = i;
		for (j = i+1; j < n; j++)
			if (values[j] < values[men])
				men = j;
		if (values[i] != values[men]) {
			aux = values[i];
			values[i] = values[men];
			values[men] = aux;
		}
	}
	return;
}
