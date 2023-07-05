# Single Linked List (single_l)

## Introduction

`single_l` is a C++ template class that implements a single linked list. It provides various operations to manipulate and access the elements of the list.
It allows for deep and shallow copying, move semantics and much more. The lsit is not iterable but it is on the TODO list.

## Table of Contents
- [Constructor](#constructor)
- [Destructor](#destructor)
- [Copy Constructor](#copy-constructor)
- [Move Constructor](#move-constructor)
- [Assignment Operator](#assignment-operator)
- [Push Back](#push-back)
- [Push Front](#push-front)
- [Pop Back](#pop-back)
- [Pop Front](#pop-front)
- [Print Reverse](#print-reverse)
- [Clear](#clear)
- [Swap](#swap)
- [Empty](#empty)
- [Size](#size)

## Constructor

- `single_l()`: Creates a new single linked list.
- `single_l(std::initializer_list<T>_init_);`: Allows for initializing an object using an initializer list

## Destructor

- `~single_l()`: Destructor for the single linked list class. Clears the list by deleting all nodes.

## Copy Constructor

- `single_l(const single_l& other)`: Constructs a new single linked list by copying all elements of another linked list.

## Move Constructor

- `single_l(single_l&& other)`: Constructs a single linked list by moving the contents of another single linked list, setting its head pointer to null afterwards.

## Assignment Operator

- `single_l& operator=(const single_l& other)`: Assignment operator for the single linked list class. Assigns the elements of another list to this list.

## Move Assignment Operator

- `single_l& operator=(single_l&&)`: Move the Assignment operator for the single linked list class. Moves the elements of another list to this list.

## Push Back

- `void push_back(const T& data)`: Adds a new node with the given data to the end of the linked list.

## Push Front

- `void push_front(const T& data)`: Adds a new node to the front of the linked list.

## Pop Back

- `void pop_back()`: Removes the last element of the single linked list.

## Pop Front

- `void pop_front()`: Removes the first element from the list.

## Print Reverse

- `void print_reverse()`: Prints the contents of the list in reverse order.

## Front
- `T& front()`: Returns the front element
- `const T& front() const`: Returns a const front element

## Back
- `T& back()`: Returns the back element
- `const T& back() const`: Returns a const back element

## [] Operator
- `T& operator[](size_t);`: Allows for access of an element at a specific index
- `const T& operator[](size_t) const;`: Allows for const access of an element at a specific index

## At
- `T& at(size_t index);`: Returns an element at a specific index
- `void delete_at(size_t index);`: Delets an element at a specific index
- `void at_position(const T& data, size_t position);`: Allows for insertion at a specific index

## Delete Value
- `void delete_value(const T &data);`: Deletes a specific value

## Search
- `size_t search(const T &data);`: Allows for searching of a specific value

## Resize
- `void resize(size_t n)`: Resizez the linked list to a `size_t` type parameter
## Utility
- `void clear()`: Clears the linked list by deleting all nodes.
- `void swap(single_l& other)`: Swaps the head of this list with another list's head.
- `bool empty()`: Determines whether the single linked list object is empty.
- `size_t size()`: Returns the number of nodes in the linked list.
- `void reverse();`: Reverses the Linked List
- `void sort();`: Sorts the Linked List
- `void remove_duplicates();`: Removes duplicates in the Linked list

    
## Usage

To use the `single_l` class, follow these steps:

1. Include the `single_l.h` header file in your C++ program.
   ```cpp
   #include "single_l.h"
   ```
2. reate a new instance of the `single_l` class.
   ```
   single::single_l<int> list;
   ```
3. Perform various operations on the linked list using the available member functions.
   ```cpp
   list.push_back(10);
   list.push_back(20);
   list.push_front(5);
   list.pop_back();
   list.print_reverse();
   std::cout << list << std::endl;
   //...
   ```
   Make sure to replace int with the appropriate data type you want to use in the linked list.

## Example
An exampleusage is defined in the `main.cpp` file. Uncomment the `#define EXAMPLE` macro to run the `run_example()` function.
It demonstrates the basic usage of the single_l class by creating a linked list, adding elements, checking the size and emptiness of the list, printing the list in reverse order, and clearing the list.
Feel free to modify the example and explore other member functions and operations provided by the single_l class.

## Contributing

Contributions to this repository are welcome! If you find any issues or have improvements to suggest, feel free to submit a pull request. Please follow the contribution guidelines and code of conduct outlined in the repository.

# License

This project is NOT licensed under the [MIT License](#LICENSE). You are free to use, modify, and distribute the code and projects within this directory.

