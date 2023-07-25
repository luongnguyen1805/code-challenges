
#include <stdio.h>

int binarySearch(int x, int(&arr)[], int size) {
    
    int partitionSize = size;
    int pointer = partitionSize/2;
    int base = 0;
    
    while (partitionSize > 0) {

        int value = arr[base+pointer];
        if (partitionSize == 1)
        {
            if (x == value) return base + pointer;
            else return -1;
        }
        if (x >= value) {
            partitionSize = partitionSize - pointer;
            base = base + pointer;
        }
        else {
            partitionSize = partitionSize/2;
        }

        pointer = partitionSize/2;
    }
    
    return -1;
};

int main()
{
    int x = 23;
    int arr[] = {1, 5, 8, 12, 14, 18, 22, 24, 25, 30, 33, 37, 41, 43, 50, 52, 55, 59, 62, 64, 66, 68, 70, 73, 77, 79, 81, 84, 88, 90, 95, 97, 101, 106, 108, 110, 112, 115, 120, 123, 125, 129, 134, 136, 139, 142, 146, 149, 152, 155, 160, 163, 166, 169, 172, 176, 180, 183, 187, 191, 193, 196, 198, 201, 204, 208, 211, 215, 218, 223, 227, 229, 232, 235, 239, 241, 245, 249, 253, 256};
    
    int size = sizeof(arr)/sizeof(*arr);
    
    int pos = binarySearch(x,arr,size);
    
    printf("POSITION: %d",pos);

    return 0;
}
