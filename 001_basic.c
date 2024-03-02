#include <stdio.h>
#define MAXLEN 100
int data[MAXLEN], n = 0, opt, loc, indx, item;

void display_item()
{
    printf("Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void insert_item()
{
    printf("Enter Number to insert and Index : ");
    scanf("%d %d", &item, &indx);
    if (indx >= 0 && indx < n)
    {
        for (int i = indx; i <= n; i++)
        {
            int tmp = data[i];
            data[i] = item;
            item = tmp;
        }
    }
    else
    {
        data[n] = item;
    }
    n++;
}

void delete_item()
{
    printf("Enter the Item to delete : ");
    scanf("%d", &item);
    for (int i = 0; i < n; i++)
    {
        if ( data[i] == item )
        {
            data[i] = data[i + 1];
            item = data[i + 2];
        }
    }
    n--;
}

void search_item()
{
    printf("Enter the Item to Search : ");
    scanf("%d", &item);
    for (int i = 0; i < n; i++)
    {
        if ( data[i] == item )
        {
            printf("Item : %d\t\t Location : %d \n", data[i], i);
            break;
        }
    }
    n--;
}


// Implement C program for performing following operation on Array : Creation, Insertion,Deletion, Search, Display
int main()
{
    for (int j = 0; j < 10; j++)
    {

        printf("1 : Insertion\n");
        printf("2 : Deletion\n");
        printf("3 : Search\n");
        printf("4 : Display\n");
        printf("5 : Exit\n");

        printf("Enter the Option : ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            /* insert */
            insert_item();
            break;

        case 2:
            /* delete */
            delete_item();
            break;

        case 3:
            /* search */
            search_item();
            break;

        case 4:
            /* display */
            display_item();
            break;

        default:
            printf("Invalid Option !");
            break;
        }
    }
    return 0;
}