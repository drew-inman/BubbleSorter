/* NAME: Drew Inman DATE: 03/27/2019 PROJECT: Individual Assignment 2
 * 
 * DESCRIPTION: This project accepts a sequence of numbers and a sorting order
 * 				and bubble sorts the numbers, based on the sorting order input.
 *				The sorting order is chosen after the sequence of numbers is
 *				built. Then after being bubble sorted, the main function prints
 *				the bubble sorted array.
 */
#include <stdio.h>
#include <stdlib.h>

//These are the function prototypes. There are three of them.
int sequenceBuilder(int array[]);
void bubbleSort(int array[], int sequenceSize, int sortingOrder);
void swap(int *a, int *b);

/* The array, the size and sort order are all decided in the main method and
 * used as parameters in sequenceBuilder and bubbleSort (and swap function, 
 * via bubbleSort function.
 */
int main(int argc, char *argv[]) {
	
	int data[100];
	int size = sequenceBuilder(data);
	int j;
	int sortOrder = 0;
	
	printf("Please enter a sorting order. '0' for Increasing, '1' for Decreasing\n");
	scanf("%i",&sortOrder);
	
	bubbleSort(data,size,sortOrder);
	
	for(j = 0 ;j<size;j++)
	{
		printf("%i ",data[j]);
	}
	
	return 0;
}
/* The sequenceBuilder function accepts any amount of numbers (up to 100 total)
 * and stores them in an array and returns the length of the array
 */
int sequenceBuilder(int array[])
{
	int input = 0;
	int sequenceSize = 0;
	int j;
	
	printf("Please enter a sequence of up to 100 numbers. Enter 0 to quit.\n");
	do{
		scanf("%i", &input);
		if(input >= 1){
			array[sequenceSize] = input;
			sequenceSize++;
		}
	} while((sequenceSize<=100) && (input != 0));
	
	return sequenceSize;
	
	
}
/* The bubbleSort method accepts an array of numbers and sorts them (either 
 * increasing or decreasing) by checking the array index and the array index+1
 * and swapping them according to if they're greater or less than each other.
 */
void bubbleSort(int array[], int sequenceSize, int sortingOrder)
{
	int i;
	int j;

	for(i = 0;i<sequenceSize-1;i++)
	{
		for(j = 0;j<sequenceSize-1;j++)
		{
			if(sortingOrder == 0)
			{
				if(array[j] > array[j+1])
				{
					swap(&array[j],&array[j+1]);
				}
			}
			if(sortingOrder == 1)
			{
				if(array[j] < array[j+1])
				{
					swap(&array[j],&array[j+1]);
				}
			}
		}
	}
}
/* The swap function accepts two pointers and creates a temp variable to swap
 * pointer a and pointer b.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
