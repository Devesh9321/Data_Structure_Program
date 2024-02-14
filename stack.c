#include <stdio.h>
#define MAXSIZE 100

// Stack with Array

// defining the functions
void display(int data[], int n)
{
    printf("\nStack : ");
    for (int k = 0; k < n; k++)
        printf("%d ", data[k]);
    printf("\tTop : %d ", n);
}

int main()
{
    int stack[MAXSIZE], top = 0, n, running = 1, opt = 0, val;
    printf("Enter the Size of Array : ");
    scanf("%d", &n);

    printf("\nEnter the %d Elements of Array : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stack[i]);
        top++;
    }

    while (running)
    {
        printf("\n\n1.\tInsert Value\n2.\tDelete Value\n3.\tDisplay\n4.\tExit\n");
        printf("#-[ Enter the Option ] : ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the Value to insert : ");
            scanf("%d", &val);
            if (top < MAXSIZE)
            {
                stack[top] = val;
                top++;
                printf("Value inserted !");
            }
            else { printf("stack is FULL !"); }
            break;
        case 2:
            if (top > 0){ top--; printf("Value Removed !"); }
            else { printf("stack is empty !"); }
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            running--;
            break;

        default:
            printf("Invalid Input !");
            break;
        }
    }
    return 0;
}