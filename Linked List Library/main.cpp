//
//  main.cpp
//  linked_list_xcode
//
//  Created by Jakob Balkovec on 13/06/2023.
//

#include <iostream>
#include "single_l.cpp"

// {
// Un-comment example macro to run example
// }
#define EXAMPLE


// {
//  {
//  Simple LL problem implemented in the example function
//  }
// Problem Name: Merge Two Sorted Lists

// You are given two non-sorted linked lists, list1 and list2. Your task is to merge these two lists into a single 
// sorted linked list and print it.

// Example:
// Input:
// list1: 1 -> 3 -> 5
// list2: 2 -> 4 -> 6
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

// Write a function mergeSortedLists that takes two non-sorted linked lists list1 and list2 
// as parameters and returns the new merged list.

// You can assume the following:

// The linked lists are non-empty.
// The nodes of each list contain data of type T.
// Note: You should not modify the original lists; instead, 
// you should create a new list with the merged elements.
// }

inline void run_example(single::single_l<int> &list1, single::single_l<int> &list2) {
    std::cout << "\n__[EXMPLE RESULT]__ \n\n";
    single::single_l<int> merged;
    for(size_t i =0; i < list2.size(); i++) {
        list1.push_back(list2.at(i));
    }

    list1.sort();
    std::cout << list1 << "\n\n";
}

/** {
 * Displays information about the last compilation of the file.
 * @return void
    } **/
static inline void show_last_compiled() {
  std::cout << "\n[file]: " << __FILE__ << '\n'
    << "[compiled on]: " << __DATE__ << " at " << __TIME__ << '\n'
    << "[compiler]: " << __VERSION__ << '\n'
    << "[timestamp]: " << __TIMESTAMP__ << "\n\n";
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
    #ifdef EXAMPLE
    single::single_l<int> list1 = {1, 3, 5};
    single::single_l<int> list2 = {2, 4, 6};
    run_example(list1, list2);
    #endif
        
    return EXIT_SUCCESS;
}
