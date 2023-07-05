//
//  main.cpp
//  linked_list_xcode
//
//  Created by Jakob Balkovec on 13/06/2023.
//

#include <iostream>
#include "single_l.h"
#include "test.h"

// {
// Un-comment test macro to run all tests
// }
// #define TEST

// {
// Un-comment example macro to run example
// }
#define EXAMPLE


// {
//  {
//  Simple LL problem implemented in the example function
//  }
// Problem Name: Merge Two Sorted Lists

// You are given two sorted linked lists, list1 and list2, where each list is sorted 
// in non-decreasing order. Your task is to merge these two lists into a single 
// sorted linked list and return the head of the merged list.

// Example:
// Input:
// list1: 1 -> 2 -> 3
// list2: 4 -> 5 -> 6
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6

// Write a function mergeSortedLists that takes two sorted linked lists list1 and list2 
// as parameters and returns the new merged list.

// You can assume the following:

// The linked lists are non-empty.
// The nodes of each list contain data of type T.
// The lists are already sorted in non-decreasing order.
// Note: You should not modify the original lists; instead, 
// you should create a new list with the merged elements.
// }

/** {
 * Displays information about the last compilation of the file.
 * @return void
    } **/
static inline void show_last_compiled() {
  std::cout << "\n[file]: " << __FILE__ << '\n'
    << "[compiled on]: " << __DATE__ << " at " << __TIME__ << '\n'
    << "[compiler]: " << __VERSION__ << '\n'
    << "[timestamp]: " << __TIMESTAMP__ << '\n';
}

/**
 * The main function of the C++ program. It runs either the tests or the example
 * depending on the macros defined. If no macros are defined, it prints a message
 * to the console. 
 *
 * @param argc the number of command line arguments
 * @param argv an array of the command line argument strings
 *
 * @return integer value EXIT_SUCCESS (0) upon successful execution
 *
 * @throws None
 */
int main(int argc, const char * argv[]) {
    show_last_compiled();
    #ifdef TEST
    volatile bool all_passed = run_tests();
    if(all_passed) 
        std::cout << "\n\n[all tests passed]\n\n";
    else
        std::cout << "\n\n[some tests failed, check and see which]\n\n";
    
    #endif
    
    #ifdef EXAMPLE
    run_example();
    #endif
        
    #ifndef TEST
    #ifndef EXAMPLE
        std::cout << "\n[Un-comment a macro to run]\n\n";
    #endif
    #endif
    return EXIT_SUCCESS;
}
