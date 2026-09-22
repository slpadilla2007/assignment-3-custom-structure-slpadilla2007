#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(Array *a);

int main(int argc, char **argv) {
	
	//Creates char pointer input equal to the string of argv with index of 1
	//The argv with index of 0 is the dot slash main
	char *input = argv[1];
	//Uses ASCII to Integer function to make variable theSize equal inputted size
	int theSize = atoi(input);
	
	//Creates pointer al with type Array
	Array *arr1;
	//Makes arr1 a dynamically allocated Array array of the size of 1 Array
	arr1 = (Array*) malloc(1*sizeof(Array));
	
	//Makes the allocated size to be theSize given earlier
	arr1->size = theSize;
	//Makes a dynamically allocated array of doubles of the given size
	arr1->data = (double*) malloc(arr1->size*sizeof(double));
	
	int maxSize = 50;

	for (int i = 0; i < arr1->size; i++) {
		
		arr1->data[i] = rand() % (maxSize + 1);
	
	}
	
	//Outputs initial array
	output_array(arr1);
	
	//Calls shift array func and then outputs new array
	shift_array(arr1);
	output_array(arr1);

	Array *arr2;
	arr2 = average_adjacent(arr1);
	output_array(arr2);

	free(arr1->data);
	free(arr1);
	free(arr2->data);
	free(arr2);

	return 0;

}

void output_array(Array *a) {
	
	printf("Array output: ");
	for (int i = 0; i < a->size; i++) {
		if (i != a->size - 1) {
			printf("%.2f, ", a->data[i]);
		} else {
			printf("%.2f\n", a->data[i]);
		}
	}

}

void shift_array(Array *a) {

	double initFirst = a->data[0];
	
	for (int i = 0; i < a->size; i++) {
		if (i != a->size - 1) {
			a->data[i] = a->data[i+1];
		} else {
			a->data[i] = initFirst;
		}
	}

}

Array *average_adjacent(Array *a) {
	
	Array *newArr;
	newArr = (Array*) malloc(1*sizeof(Array));

	if (a->size % 2 != 0) {
		newArr->size = (a->size - 1)/2;
	} else {
		newArr->size = a->size/2;
	}

	newArr->data = (double*) malloc(newArr->size*sizeof(double));

	for (int i = 0; i < newArr->size; ) {
		
		int testSize;

		if (a->size % 2 != 0) {
			testSize = a->size - 1;
		} else {
			testSize = a->size;
		}

		for (int j = 0; j < testSize; j += 2) {
			newArr->data[i] = (a->data[j] + a->data[j+1])/2;
			i++;
		}

	}

	return newArr;

}
