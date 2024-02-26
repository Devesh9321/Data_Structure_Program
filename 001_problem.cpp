#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
Consider the problem of adding two n-bit binary integers a and b, stored in two n-elements arrays A[0:n-1] and B[0:n-1], where each element is either 0 or 1, a = summation i=0 to n-1 (A[i] * 2^i) and summation i=0 to n-1 (B[i] * 2^i). The sum c = a+b of the two integers should be stored in binary form in an (n+1) element array C[0:n], where c = summation i=0 to n (C[i] * 2^i). write a prodecure ADD-BINARY-INTEGERS that takes as input arrays A and B, along with the length n, and return array C holding the sum.

*/
vector<int> addBinaryInteger(int *A, int *B, int n){
    vector<int> C;
    int carry=0,sum=0;

    for(int i=n-1; i>=0;--i){
        // S = X'y'Z + X'yz' + xy'Z' + xyz  
        sum = (!A[i] && !B[i] && carry) || (!A[i] && B[i] && !carry) || (A[i] && !B[i] && !carry) || (!A[i] && !B[i] && carry)?1:0;
        // C = xy + xz + yz
        carry = (A[i] && B[i]) || (A[i] && carry) || (carry && B[i]);         
        C.push_back(sum);

    }
    C[n] = carry;
    
    return C;
}

main(){
    int A[] = {0,1,0,1,1};    
    int B[] = {0,1,1,0,1};
    int n = 5;
    vector<int> C = addBinaryInteger(A,B,n);
    int val = 0;
    for(int i=n;i>=0;--i){
        cout<<C[i]<<" ";
        val+=pow(2,i)*C[i];
    }
    cout<<val<<"\n";

    return 0;
}