#include <stdio.h>
#define MAXSIZE 100

// Stack with Array

// defining the functions
void display(int data[], int r)
{
    printf("\nQueue : ");
    for (int k = 0; k < r; k++)
        printf("%d ", data[k]);
    printf("\tRare : %d ", r);
}

int main()
{
    int queue[MAXSIZE], rare = 0, n, running = 1, opt = 0, val;
    printf("Enter the Size of Array : ");
    scanf("%d", &n);

    printf("\nEnter the %d Elements of Queue : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
        rare++;
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
            if (rare < MAXSIZE)
            {
                queue[rare] = val;
                rare++;
                printf("Value inserted !");
            }
            else
            {
                printf("Queue is FULL !");
            }
            break;
        case 2:
            if (rare > 0)
            {
                for (int k = 0; k < rare; k++)
                    queue[k] = queue[k + 1];
                rare--;
                printf("Value Removed !");
            }
            else
            {
                printf("Queue is empty !");
            }
            break;
        case 3:
            display(queue, rare);
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