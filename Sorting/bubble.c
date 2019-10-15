#include <stdio.h>

// Function Prototypes
void swap(int *, int *);
void bubbleSort(int [], int);
void printArray(int [], int);

int main(){
	int arr[100], n;

	printf("\nBubble Sort\n-----------\n");
	printf("Enter Number of Elements in Array : ");
	scanf("%d", &n);

	printf("Enter Elements of the Array : ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	bubbleSort(arr, n);
	printf("\nSorted array: \n");
	printArray(arr, n);

	return 0;
}

// Function of swapping (Call by reference)
void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n){
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
	for (int i=0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}
