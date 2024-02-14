#include <iostream>
#include <cassert>
#include <time.h>
using namespace std;
#define maxsize 10000

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
    cout << "\n| N \t| Size (Bytes) \t| Size (MB) \t| Time \t\t|";
    for (int n = 9998; n < maxsize; ++n)
    {
        int A[n];
        int B[n];

        clock_t start = clock();
        for (int i = 0; i < n; ++i)
        {
            A[i] = (rand() % maxsize) + 1;
        }

        mergesort(A, B, n);
        // Dispalay("\nSorted",A,n);

        clock_t end = clock();
        long double time_required = (long double)(end - start) / CLOCKS_PER_SEC;
        long double size_byte = sizeof(A);
        long double size_mb = size_byte / 1048576;
        cout << "\n| " << n << " \t| " << size_byte << " \t| " << size_mb << " \t| " << time_required;
        free(A);
        free(B);
    }

    return 0;
}