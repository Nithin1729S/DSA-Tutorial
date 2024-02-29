#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hash(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int idx = hash(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != 0)
    {
        i++;
    }
    return (idx + i) % SIZE;
}

void insert(int H[], int key)
{
    int idx = hash(key);
    if (H[idx] != 0)
    {
        idx = probe(H, key);
    }
    H[idx] = key;
}

int search(int H[], int key)
{
    int idx = hash(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != key)
    {
        i++;
    }
    return (idx + i) % SIZE;
}

int main()
{
    int HT[SIZE] = {0}; // Initialize the hash table with 0s
    insert(HT, 12);
    insert(HT, 25);
    insert(HT, 35);
    insert(HT, 26);

    int searchResult = search(HT, 35);
    if (HT[searchResult] == 35)
    {
        printf("\nKey found at index %d\n", searchResult);
    }
    else
    {
        printf("\nKey not found\n");
    }

    return 0;
}
