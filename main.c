#include <stdio.h>
#include <stdlib.h>
#include "array.h"

//Function prototypes
void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(Array *a);

//main func with user input arguments
//**argv = *argv[]
int main(int argc, char **argv) {

	/*Creates char pointer input equal to the string of argv with index 
	  of 1*/
	//The argv with index of 0 is the dot slash main
	char *input = argv[1];
	/*Uses ASCII to Integer function to make variable theSize equal
	  inputted size*/
	int theSize = atoi(input);
	
	//Creates pointer arr1 with type Array
	Array *arr1;
	/*Makes arr1 a dynamically allocated Array array of the size of 1
	  Array*/
	//*arr1 = &((Array*) malloc(1*sizeof(Array))), essentially
	arr1 = (Array*) malloc(1*sizeof(Array));
	
	//Makes the allocated size to be theSize given earlier
	arr1->size = theSize;
	/*Makes data be a dynamically allocated array of doubles of the
	  given size*/
	arr1->data = (double*) malloc(arr1->size*sizeof(double));
	
	//Creates maxSize variable for random numbers
	int maxSize = 50;
	
	/*Populates all members of data of arr1 with random numbers using
	  the rand func*/
	for (int i = 0; i < arr1->size; i++) {
	
		arr1->data[i] = rand() % (maxSize + 1);
	
	}
	
	//Outputs initial array
	output_array(arr1);
	
	//Calls shift array func and then outputs new array
	shift_array(arr1);
	output_array(arr1);

	//Creates pointer arr2 with type Array
	Array *arr2;
	/*Makes arr2 equal the values received from the average_adjacent
	  func*/
	arr2 = average_adjacent(arr1);
	//Outputs arr2
	output_array(arr2);
	
	//Frees previously allocated memory
	free(arr1->data);
	free(arr1);
	free(arr2);
	free(arr2->data);

	//Code done yippee yay
	return 0;

}

void output_array(Array *a) {
	
	//Initial print
	printf("Array output: ");
	//Prints each array member of data, no comma for the last member
	for (int i = 0; i < a->size; i++) {
		if (i != a->size - 1) {
			printf("%.2f, ", a->data[i]);
		} else {
			printf("%.2f\n", a->data[i]);
		}
	}

}

void shift_array(Array *a) {
	
	//Creates initFirst variable initialized to the value of data[0]
	double initFirst = a->data[0];
	
	/*Makes every data member except the last equal to the next value
	  and the last equal to the initial data[0]*/
	for (int i = 0; i < a->size; i++) {
		if (i != a->size - 1) {
			a->data[i] = a->data[i+1];
		} else {
			a->data[i] = initFirst;
		}
	}

}

/*Important to note, this function has a return type of "Array *" and isn't 
  a pointer to a function*/
Array *average_adjacent(Array *a) {
	
	//Creates pointer newArr with type Array
	Array *newArr;
	/*Makes newArr a dynamically allocated Array array of the size of 1 
	  Array*/
	newArr = (Array*) malloc(1*sizeof(Array));
	
	/*If the size in the Array given has a remainder when divided by 2,
	  makes the size in newArr equal to the initial size minus 1 divided
	  by 2*/
	/*Else, just makes the size in newArr equal to the initial size
	  divided by 2*/
	if (a->size % 2 != 0) {
		newArr->size = (a->size - 1)/2;
	} else {
		newArr->size = a->size/2;
	}
	
	/*Makes data be a dynamically allocated array of doubles of the size
	  in newArr*/
	newArr->data = (double*) malloc(newArr->size*sizeof(double));
	
	//For each member of data in newArr,
	for (int i = 0; i < newArr->size; ) {
		/*sets the value of the data member in newArr that's
		  currently being worked on equal to a's data[j] value plus
		  the next data value all divided by 2, then increases i. j
		  has 2 added to it each time to ensure proper mean
		  calculation (in practice it would look like (data[0] +
		  data[1]), then on the next loop (data[2] + data[3]), and
		  so on).*/
		for (int j = 0; j < a->size; j += 2) {
			newArr->data[i] = (a->data[j] + a->data[j+1])/2;
			i++;
		}
	}
	
	//Returns the newArr
	return newArr;

}
