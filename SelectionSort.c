#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d. %d \n",i, arr[i]);
    printf("\n");
}

int main() {


    int n=0;
    /*int n = 15;
    int arr[]={2, 14, 6, 13, 3, 3, 7, 0, 6, 19, 0, 16, 3, 2, 6};*/
    
    clock_t begin, end;
    double total_t;
    begin = clock();
    FILE * fp;
    fp = fopen("1-100.txt","r");
    fscanf(fp, "%d", &n);

    int *arr = malloc(n * sizeof(int));
	
    for (int i=0; i < n; i++)
    {
	fscanf(fp, "%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("Sorted array: \n");
	
    printArray(arr, n);
    end= clock();
    total_t = (double)(end - begin );
   	
    printf("Initial time taken by CPU: %ld \n", begin  );
    printf("End time taken by CPU: %ld \n", end  );
    printf("Total time taken by CPU: %f seconds\n", total_t  );
    free(arr);

    return 0;
}