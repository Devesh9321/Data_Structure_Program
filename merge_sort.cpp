#include <iostream>
#include <cassert>
#include <time.h>
#include "insertion_sort.h"
using namespace std;
#define maxsize 100000

void mergeCopy(int *A, int ibeg, int iend, int *B)
{
    for (int i = ibeg; i < iend; ++i)
    {
        B[i] = A[i];
    }
}

void mergeCombine(int *B, int ibeg, int imid, int iend, int *A)
{
    int i = ibeg, j = imid;
    for (int k = ibeg; k < iend; ++k)
    {
        if (i < imid && (j >= iend || A[i] <= A[j]))
        {
            B[k] = A[i];
            i = i + 1;
        }
        else
        {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

void mergeDivide(int *B, int ibeg, int iend, int *A)
{
    if (!((iend - ibeg) <= 1))
    {
        int imid = (ibeg + iend) / 2;

        mergeDivide(A, ibeg, imid, B);
        mergeDivide(A, imid, iend, B);
        mergeCombine(B, ibeg, imid, iend, A);
    }
};

void mergesort(int *A, int *B, int n)
{
    mergeCopy(A, 0, n, B);
    mergeDivide(A, 0, n, B);
};

void Dispalay(char *Text, int *A, int n)
{
    cout << Text;
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
}

main()
{
    cout<<"* * * Merge Sort Time complexcity * * *"<<endl;
    cout << "\n| Sorting Algo \t| N \t| Size (Bytes) \t| Size (MB) \t| Time \t\t|";
    for (int n = 99995; n < maxsize; ++n)
    {
        int A[n];
        int A1[n];
        int B[n];

        for (int i = 0; i < n; ++i)
        {
            A[i] = (rand() % maxsize) + 1;
            A1[i] = A[i];
        }

        //Merge sort
        clock_t start_m = clock();
        mergesort(A, B, n);
        clock_t end_m = clock();
        
        //insertion sort
        clock_t start_i = clock();
        INSERTIONSort(A1, n);
        clock_t end_i = clock();
        // Dispalay("\nSorted : ",A1,n);


        long double time_required_m = (long double)(end_m - start_m) / CLOCKS_PER_SEC;
        long double time_required_i = (long double)(end_i - start_i) / CLOCKS_PER_SEC;
        long double size_byte = sizeof(A);
        long double size_mb = size_byte / 1048576;
        cout << "\n| Merge Sort \t| " << n << " \t| " << size_byte << " \t| " << size_mb << " \t| " << time_required_m;
        cout << "\n| insert Sort \t| " << n << " \t| " << size_byte << " \t| " << size_mb << " \t| " << time_required_i;
        free(A);
        free(B);
    }

    return 0;
}

// Output 
// | Sorting Algo  | N     | Size (Bytes)  | Size (MB)     | Time          |
// | Merge Sort    | 99995         | 399980        | 0.381451      | 0.013
// | insert Sort   | 99995         | 399980        | 0.381451      | 5.814
// | Merge Sort    | 99996         | 399984        | 0.381454      | 0.012
// | insert Sort   | 99996         | 399984        | 0.381454      | 5.692
// | Merge Sort    | 99997         | 399988        | 0.381458      | 0.013
// | insert Sort   | 99997         | 399988        | 0.381458      | 5.728
// | Merge Sort    | 99998         | 399992        | 0.381462      | 0
// | insert Sort   | 99998         | 399992        | 0.381462      | 5.924
// | Merge Sort    | 99999         | 399996        | 0.381466      | 0.014
// | insert Sort   | 99999         | 399996        | 0.381466      | 5.932