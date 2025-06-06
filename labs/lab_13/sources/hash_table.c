

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../headers/hash_table.h"

#include "../headers/constants.h"

int hashCode(int key) {

    return key%CAPACITY;
}

HashItem createHashItem(int key, int data)
{
    HashItem item={key, data};
    return item;
}
void createHashArray(HashTable *pHashTable) {
    pHashTable->items=(HashItem*)calloc(CAPACITY,sizeof(HashItem));
    if (!pHashTable->items) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < CAPACITY; ++i) {
        pHashTable->items[i] = NULL;
    }
}

void insert(HashTable *hashTable, int key, int data) {
    if (hashTable->size==CAPACITY) {
        printf("Hashtable is full");
    }
    int index = hashCode(key);
    printf("%10i\t%10i\t hashcode: %i\n", key, data, index);
    insertFirst(&hashTable->items[index], createHashItem(key, data));
}
void display(HashTable hashTable) {
    if (hashTable.size==0) {
        printf("The hashtable is empty");
    }
    for (int i = 0; i < CAPACITY; ++i) {
        if(hashTable.items[i] != NULL)
        {
            printf("Items at position (%i) are: \n", i);
            printList(hashTable.items[i]);
        }
    }
}


void delete(HashTable *hashTable, int key) {
    int index = hashCode(key);
    if (hashTable->items[index] == NULL)
    {
        printf("\n This key does not exist \n");
        return;
    }
    if(deleteNode(&hashTable->items[index], key))
        printf("\n Key (%i) has been removed \n", key);
    else
        printf("\n This key does not exist \n");
}

bool search(HashTable hashTable, int key) {
    int index = hashCode(key);
    if (hashTable.items[index] == NULL)
    {
        return false;
    }
    return searchNode(hashTable.items[index], key);
}

void destroyHashArray(HashTable *pHashTable) {
    pHashTable->size=0;
    for (int i = 0; i < CAPACITY; ++i) {
        freeList(&pHashTable->items[i]);
    }
    pHashTable = NULL;
}