#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


int main() 
{
    /*int n = 15;
    int arr[]={2, 14, 6, 13, 3, 3, 7, 0, 6, 19, 0, 16, 3, 2, 6};*/
    
    clock_t begin, end;
    double total_t;
    begin = clock();
    int n;
    FILE * fp;
      fp = fopen("1-100.txt","r");
      fscanf(fp, "%d", &n);
      int *arr = malloc(n * sizeof(int));
	
      #pragma omp parallel num_threads(2)
{
#pragma omp for
	for (int i=0; i < n; i++)
	{
		fscanf(fp, "%d", &arr[i]);
	}
}

    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
#pragma omp parallel for shared(arr, n, min_idx) private(j)
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
#pragma omp critical
                {
                    if (arr[j] < arr[min_idx])
                        {min_idx = j;}
                }
            }
        }

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    
    printf("Sorted array: \n");
    #pragma omp parrallel num_threads(2)
{
    #pragma omp for
    for (int i=0; i < n; i++)
    {
        printf("%d. %d \n", i,arr[i]);
    }
}

    printf("\n");
    end= clock();
    total_t = (double)(end - begin );	
    printf("Initial time taken by CPU: %ld \n", begin  );
    printf("End time taken by CPU: %ld \n", end  );
    printf("Total time taken by CPU: %f seconds\n", total_t  );
    free(arr);
    return 0;
}