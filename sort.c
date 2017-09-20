#include <time.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINT_RESULTS true

void sort(int *arr, int n);

int main(void)
{
    // Set up array to store inputs.
    int capacity = 16;
    int *arr = calloc(capacity, sizeof(int));
    int n = 0;
    if (!arr)
    {
        fprintf(stderr, "Could not allocate memory.\n");
        return 1;
    }

    // Loop until EOF, collecting numbers one per line.
    while (true)
    {
        string s = get_string();
        if (!s)
        {
            break;
        }
        int x = atoi(s);

        // Resize the array if necessary.
        if (n == capacity)
        {
            if (capacity / sizeof(int) / 2 > SIZE_MAX)
            {
                fprintf(stderr, "Too many numbers.\n");
                return 2;
            }
            capacity *= 2;
            int *temp = realloc(arr, sizeof(int) * capacity);
            if (!temp)
            {
                free(arr);
                fprintf(stderr, "Could not allocate more memory.\n");
                return 3;
            }
            arr = temp;
        }
        arr[n] = x;
        n++;
    }
    
    // Sort the array and time the sort.
    printf("Sorting...\n");
    clock_t t = clock();
    sort(arr, n);
    t = clock() - t;
    printf("Sorted!\n");
    printf("Time taken to sort: %.6f\n", ((double) t) / CLOCKS_PER_SEC);

    // Print results if desired.
    if (PRINT_RESULTS)
    {
        for (int i = 0; i < n; i++)
        {
            printf("arr[%i] = %i\n", i, arr[i]);
        }
    }

}

void sort(int *arr, int n)
{
    // TODO: sort the numbers
}
