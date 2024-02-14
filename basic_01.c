#include <stdio.h>
#include"datasturch.h"
#define MAXSIZE 100
int i = 0;
// Array Operation for data structure

// defining the functions
void display(int data[], int n){
    printf("\nArray : ");
    for (int k = 0; k < n; k++) printf("%d ", data[k]);
    printf("\tSize : %d ", n);
}

void insert(int data[], int *n, int loc, int val){
    for (i = *(n) + 1; i >= loc; i--) data[i] = data[i - 1]; // printf("%d ",data[i]);
    if (loc < MAXSIZE) data[loc] = val;
    else printf("Cannot insert !");
    *(n) = *(n) + 1;
}

void delete(int data[], int *n, int value){
    int loc = liner_search(data, n, value);
    if (loc != -1){
        for (i = loc; i < *(n); i++) data[i] = data[i + 1]; // printf("%d ",data[i]);
        *(n) = *(n)-1;
    }
    else printf("Cannot Find Element !");
}


int main()
{
    int data[MAXSIZE], n, index = 2, opt = 4, value = 0,running = 1;
    printf("Enter the Size of Array : ");scanf("%d", &n);

    printf("\nEnter the %d Elements of Array : ", n);
    for (int i = 0; i < n; i++) scanf("%d", &data[i]);

    while (running)    {
        printf("\n\n1.\tInsert Value\n2.\tDelete Value\n3.\tSearch Value\n4.\tDisplay\n5.\tExit\n");
        printf("#-[ Enter the Option ] : "); scanf("%d", &opt);
        switch (opt){
        case 1:
            printf("Enter the Value and index to insert : ");   scanf("%d %d", &value, &index);
            insert(data, &n, index, value);
            break;
        case 2:
            printf("Enter the Value to Delete : "); scanf("%d", &value);
            delete (data, &n, value);
            break;
        case 3:
            printf("Enter the Value to Serach : "); scanf("%d", &value);
            printf("\nFind At : %d loc", binary_serach(data,n, value));
            break;
        case 4:
            display(data, n);
            break;
        case 5:
            running = 0;
            break;
        default:
            printf("Invalid option!");
            break;
        }
    }
    return 0;
}