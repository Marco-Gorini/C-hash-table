//
//  main.c
//  HashTableImplementation
//
//  Created by Marco Gorini on 10/11/2022.
//  Copyright © 2022 Marco Gorini. All rights reserved.
//


//EXPLANATION


// A has table is a particular data structure that can do a search in a small amount of time (if it is well implemented and without collisions).Here an example of how we can imagine it in our mind : we can associate a number with a list of numbers, and this list of numbers could be composed by numbers that only begins with the number to which are associated, like this:

//  1 -> 12 13 167 16534 15264 1984736
//  2 -> 234 2 26 288
//  3 -> 33 3 3879 37 3456
//  4 -> 4 44 412345
//  5 -> 55 546 5678 54325
//  6 -> 666 67587 65 6123 614
//  7 -> 7 75
//  8 -> 865 87 89765 8143 87
//  9 -> 9 976 987

//  Now, if the structure in which we have to search is small, like the one on top, we can simply put our numbers into an array and make a linear search. But what happens if we have 1 billion numbers in which we have to search? With the linear search, we could have to do 1 billion operations, while if we implement a Has Table, we could reduce the computational time. The best way to implement a hash table is with an array of struct, but we could do it also with a linked list in this case. Let'see the array case, making both a linear search and a search in the Hash Table of the 1999999 number, then let's print the execution time with two special libraries.

//  I am doing the algorithm with an array of 2000000 size just cause I have not space in other case, but in the execution time we can notice the difference the same. Imagine that you have to do not only a basic operation like a search, but something else with your algorthm: making it faster could be very useful, so let's appreciate it now!

#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>

#define DIM_ARRAY 2000000
#define DIM_HASH 9
#define NUMBER_TO_SEARCH 1999999


//STRUCT DEFINITION

typedef struct nodeNumber {
    int number;
    struct nodeNumber* pointerToNextNode;
} nodeNumber_t;
typedef nodeNumber_t* HeadOfLinkedList;

typedef struct hashNode {
    int key;
    HeadOfLinkedList linkedListAssociated;
    struct hashNode* pointerToNextNode;
} hashNode_t;

//FUNCTIONS

void initializateStructures(hashNode_t hashTable[], int array[]);
int hashFunction(int number);
void addNumberToHashTable(hashNode_t hashTable[], int numberToAdd);
void linearSearch(int array[], int numberToSearch);
void hashTableSearch(hashNode_t hashTable[], int numberToSearch);

//MAIN

int main() {
    
    hashNode_t hashTable [DIM_HASH];
    int numbers[DIM_ARRAY];
    
    initializateStructures(hashTable,numbers);
    linearSearch(numbers, NUMBER_TO_SEARCH);
    hashTableSearch(hashTable, NUMBER_TO_SEARCH);
    
}

//Initializate the hash and the array with numbers from 1 to 1 billion

void initializateStructures(hashNode_t hashTable[], int array[]){
    
    for(int i = 0; i < DIM_HASH; ++i) {
        hashTable[i].key = i + 1;
        hashTable[i].linkedListAssociated = NULL;
    }
    
    for(int i = 0; i < DIM_ARRAY; ++i) {
        array[i] = i;
        addNumberToHashTable(hashTable,i);
    }
    
}

//Add the number to the hash Table

void addNumberToHashTable(hashNode_t hashTable[], int numberToAdd) {
    
    HeadOfLinkedList newNode = malloc(sizeof(nodeNumber_t));
    
    if(newNode) {
        newNode -> number = numberToAdd;
        newNode -> pointerToNextNode = hashTable[hashFunction(numberToAdd)].linkedListAssociated;
        hashTable[hashFunction(numberToAdd)].linkedListAssociated = newNode;
    }
    
}

//Hash function to set the index of the number in the array

int hashFunction(int number) {
    while(number >= 10) {
        number /= 10;
    }
    return number - 1;
}

//Linear search into the array, then prints the execution time

void linearSearch(int array[], int numberToSearch) {
    
    int boolPresent = 0;
    double timeSpent;
    clock_t begin = clock();
    
    for(int i = 0; i < DIM_ARRAY; ++i) {
        if(numberToSearch == array[i]) {
            boolPresent = 1;
            break;
        }
    }
    
    clock_t end = clock();
    timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
    
    if(boolPresent == 1) {
        printf("The number was found.");
        printf("        Execution time: %f \n", timeSpent);
        return;
    }
    printf("The number was not found.");
    printf("        Execution time: %f \n", timeSpent);
}

//Hash table search, then prints the execution time

void hashTableSearch(hashNode_t hashTable[], int numberToSearch) {
    
    int boolPresent = 0;
    double timeSpent;
    clock_t begin = clock();
    
    for(HeadOfLinkedList pointer = hashTable[hashFunction(numberToSearch)].linkedListAssociated; pointer; pointer = pointer -> pointerToNextNode) {
        if(pointer -> number == numberToSearch) {
            boolPresent = 1;
            break;
        }
    }
    
    clock_t end = clock();
    timeSpent = (double) (end - begin) / CLOCKS_PER_SEC;
    
    if(boolPresent == 1) {
        printf("The number was found.");
        printf("        Execution time: %f \n", timeSpent);
        return;
    }
    printf("The number was not found.");
    printf("        Execution time: %f \n", timeSpent);
}




