# C-hash-table
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
