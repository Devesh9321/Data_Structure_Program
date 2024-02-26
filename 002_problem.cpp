#include<iostream>
using namespace std;

/*
Write the Code for insertion sort as a recursive algorithm. In order to sort A[1:n], recursively sort the subarray A[i:n-1] and then insert A[n] in sorted subarray A[1:n-1]. write code for this recursive version of insertion sort. give a recurrence for its worst-case running time.
*/

void insertionSort_recurssion(int *A,int beg, int end){
    if(beg <= end){

        insertionSort_recurssion(A,beg+1,end);

        for(int i=end;i>beg;--i){
            if( A[beg]>A[i]){
                int tmp = A[i];
                A[i] = A[beg];
                A[beg] = tmp;
            }
        }
    }
}

main(){
    int A[10] = {32,65,87,26,76,98,34,51,43,45} ;
    cout<<"Original : ";
    for(int i=0;i<10;i++){
        cout<<A[i]<<" ";
    }

    insertionSort_recurssion(A,0,10);

    cout<<"\nSorted : ";
    for(int i=0;i<10;i++){
        cout<<A[i]<<" ";
    }


    return 0;
}