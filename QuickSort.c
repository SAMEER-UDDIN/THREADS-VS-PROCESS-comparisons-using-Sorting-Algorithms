#include <time.h>
#include <stdio.h>
#include <stdlib.h>
 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
	    swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
//quicksort recursive
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//Print array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d. %d \n", i,arr[i]);
    printf("\n");
}
 
//main program
int main()
{
	clock_t begin, end;
        double total_t;
        begin = clock();	 
	
	int n = 15;
	int num = 15;
    	int arr[]={2, 14, 6, 13, 3, 3, 7, 0, 6, 19, 0, 16, 3, 2, 6};	
	/*
	int num=0;
	FILE * fp;
	fp = fopen("1-100.txt","r");
	fscanf(fp, "%d", &num);

	int *arr = malloc(num * sizeof(int));
	
	for (int i=0; i < num; i++){
		fscanf(fp, "%d", &arr[i]);
	}
	int n=num;
	*/

	n=num; 
	quickSort(arr, 0, n-1);
	printf("Sorted array: \n");
	printf("\n");
	printArray(arr,num);

	end= clock();
        total_t = (double)(end - begin );

	printf("Initial time taken by CPU: %ld \n", begin  );
	printf("End time taken by CPU: %ld \n", end  );
	printf("Total time taken by CPU: %f seconds\n", total_t  );	

	//free(arr);
	return 0;
}
