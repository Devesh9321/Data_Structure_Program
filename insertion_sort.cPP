#include <iostream>
using namespace std;

// write the INSERTION-SORT procedure to sort into monotonically decreasing
void INSERTIONSort(int *A, int size){
    for (int i = 2; i < 10; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

// write the INSERTION-SORT procedure to sort into monotonically decreasing instead of monotonically increasing order.
void INSERTIONSort_rev(int *A, int size)
{
    for (int i = 1; i < 10; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && key > A[j])
        {
            A[j + 1] = A[j];
            A[j] = key;
            j = j - 1;
        }
    }
}

void display(int *A, int size){
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
}

main()
{
    int A[10] = {23, 56, 78, 24, 3, 64, 75, 22, 64, 67};
    
    INSERTIONSort(A, 10);
    display(A,10);

    INSERTIONSort_rev(A, 10);
    display(A,10);
    
    return 0;
}
