
#include <iostream>
#include <cassert>
#include <time.h>
using namespace std;
#define maxsize 100000

/*
  //  Give Merge Sort is using Topdown Approach

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

*/

/* Merge Sort Algorithm */

void merge(int *A, int beg, int mid, int end)
{
    int lf = mid - beg + 1;
    int rf = end - mid;
    int left[lf], right[rf];

    for (int i = 0; i < lf; ++i)
        left[i] = A[beg + i];

    for (int i = 0; i < lf; ++i)
        right[i] = A[mid + i + 1];

    int i = 0, j = 0, k = beg;

    while (i < lf && j < rf)
    {
        if (left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    for (i; i < lf; i++)
    {
        A[k] = left[i];
        k++;
    }

    for (j; j < rf; j++)
    {
        A[k] = right[j];
        k++;
    }
}

void mergesort(int *A, int beg, int end)
{
    if (!(beg >= end))
    {
        int mid = (beg + end) / 2;
        mergesort(A, beg, mid);
        mergesort(A, mid + 1, end);
        merge(A, beg, mid, end);
    }
}


void Dispalay(char *Text, int *A, int n)
{
    cout << Text;
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
}

main()
{
    int arr[] = {40, 4, 18, 15, 7, 22, 41, 87};
    cout << "Original : ";
    for (int i = 0; i < 8; ++i)
    {
        cout << arr[i] << " ";
    }
    mergesort(arr, 0, 8);
    cout << "Sorted : ";
    for (int i = 0; i < 8; ++i)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\n* * * Merge Vs Insertion Sort Time complexcity * * *" << endl;
    cout << "\n| Algo Sort   \t| N \t| Size (Bytes) \t| Time ";
    // for (int n = 1; n < maxsize; n+=900)
    for (int n = 1; n < 10000; n += 450)
    {
        int A[n], AI[n];

        for (int i = 0; i < n; ++i)
        {
            A[i] = (rand() % maxsize) + 1;
            AI[i] = A[i];
        }

        // Merge sort
        clock_t start_m = clock();
        mergesort(A, 0, n);
        clock_t end_m = clock();
        long double time_required_m = (long double)(end_m - start_m);
        long double size_byte = sizeof(A);
        cout << "\n| Merge Sort  \t| " << n << " \t| " << size_byte << " \t| " << time_required_m;

        free(A);
        free(AI);
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