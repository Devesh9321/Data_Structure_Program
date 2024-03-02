#include<stdio.h>

/*   Hear all the DataStructure Componetns are assembled into a functions   */

// Seraching Algorithms
int liner_search(int data[], int *n, int val)
{
    for (int i = 0; i < *(n); i++)
        if (data[i] == val)
            return i;
    return -1;
}

int binary_serach(int data[],int size, int val) // This will work when list is sorted.
{
    int SL = 0, EL = size, END = EL, BGN = SL, MID = (BGN + END) / 2;
    while (BGN <= END && data[MID] != val) {
        printf("Mid : %d\t BGN : %d\t END : %d\n",MID,BGN,END); 
        if (val < data[MID])  END = MID-1;
        else    BGN = MID+1;

        MID = (BGN + END) / 2;
    }
    if (data[MID] == val)   return MID;

    return -1;
}


