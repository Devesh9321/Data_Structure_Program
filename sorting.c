#include <stdio.h>

void swap(int data[], int floc, int lloc)
{
    int temp;
    temp = data[floc];
    data[floc] = data[lloc];
    data[lloc] = temp;
}

void display(const char *String, const int *data, int size)
{
    printf(String);
    for (int k = 0; k < size; k++)
        printf("%d ", data[k]);
    printf("\t\t\tSize : %d ", size);
}

void Bubbol_Sort(int *data, int size)
{
    /*
        If there are N elements are present in the list then,
        by this process is repeated for N-1 times means the
        List will be sorted in N-1 passes
    */
    for (int j = 0; j < size - 1; j++)
        for (int i = 0; i < size - 1; i++)
            if (data[i] > data[i + 1])
                swap(data, i, i + 1);
}

void Insertion_Sort(int *data, int size)
{
    for (int i = 1; i < size; i++)
    {
        int ptr = i - 1, tmp = data[i];
        while (ptr >= 0 && tmp < data[ptr])
        {
            data[ptr + 1] = data[ptr];
            ptr--;
        }
        data[ptr + 1] = tmp;
    }
}

void Selection_Sort(int *data, int size)
{
    for (int i = 0; i < 10; i++)
    {
        int loc = i;
        for (int j = i + 1; j < 10; j++)
            if (data[loc] > data[j])
                loc = j;
        swap(data, i, loc);
    }
}

void reset_packet(int packet[10][10], int size)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < size; j++)
            packet[i][j] = 0;

    /*      // Print Packet
    printf("\n table : \n");
    for (int d = 0; d < 10; d++)
    {
        for (int g = 0; g < size; g++)
            printf(" %d", Packet[d][g]);

        printf("\n");
    }
    */
}

void Bucket_Sort(int *data, int size)
{
    int Packet[10][size], max = data[0], len = 0, k = 1, z = 0, place;

    for (int i = 1; i < size; i++)
        if (max < data[i])
            max = data[i];
    // printf("\n Maximum Number : %d ", max);

    while (max > 0)
    {
        max = max / 10;
        len++;
    }
    // printf("\n Length Number : %d ", len);


    for (int i = 0; i < len; i++)
    {
        reset_packet(Packet, size);

        for (int j = 0; j < size; j++)
        {
            place = (data[j] / k) % 10;
            Packet[place][j] = data[j];
        }

        z = 0;

        for (int x = 0; x < size; x++)
            for (int y = 0; y < size; y++)
                if (Packet[x][y] != 0)
                {
                    data[z] = Packet[x][y];
                    z++;
                }
        // printf("Values plased!");

        k = k * 10;
    }
}

void Quick_sort(int *data, int size)
{
    int pivot= data[0];
    while (true)
    {
        
    }
    
    

}

int main()
{
    // 12 13 14 15 23 62 86 89 98 432
    int data[10] = {98, 12, 13, 14, 89, 62, 86, 23, 15, 432};

    // Bubbol Sort
    // Bubbol_Sort(data,10);

    // insertion Sort
    // Insertion_Sort(data,10);

    // Selection Sort
    // Selection_Sort(data,10);

    // Bucket Sort / Radix Sort
    // Bucket_Sort(data, 10);

    // Quick Sort
    
 
    display("\nSorted : ", data, 10);
    return 0;
}