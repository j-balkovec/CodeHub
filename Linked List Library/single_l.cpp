//
//  single_l.cpp
//  linked_list_xcode
//
//  Created by Jakob Balkovec on 13/06/2023.
//

#include <iostream>
#include <unordered_set>
#include <stdexcept>
#include "single_l.h"

namespace single {
  /**
   * Creates a new single linked list
   * @throws None
   */
  template <class T>
  single_l<T>::single_l() : head(nullptr) {}

  /**
   * Creates a new single linked list with the elements from the
   * specified initializer list.
   * @param initList  the initializer list containing the elements to add
   * @throws None
   */
  template <class T>
  single_l<T>::single_l(std::initializer_list<T> initList)
    : head(nullptr) {
    for (const T& value : initList) {
      push_back(value);
    }
  }
  /**
   * Destructor for the single_l class.
   * @param None
   * @return None
   * @throws None
   */
  template <class T>
  single_l<T>::~single_l() {
    clear();
  }

  /**
   * Constructs a new single linked list by copying all elements of another
   * linked list.
   * @param other The linked list to copy from.
   * @throws None
   */
  template <class T>
  single_l<T>::single_l(const single_l& other) : head(nullptr) {
    const single_l<T>::node* current = other.head;
    while (current != nullptr) {
      push_back(current->data_);
      current = current->next_;
    }
  }


  /**
   * ostream operator for the single_l class.
   * @param list The list to be printed.
   * @return Reference to the modified list.
   * @throws nones
  */
  // template <class T>
  // std::ostream& operator<<(std::ostream& os, const single_l<T>& list) noexcept {
  //     os << "List:\n";

  //     typename single_l<T>::node* current = list.head;
  //     while (current != nullptr) {
  //         os << "[" << current->data_ << "] -> ";
  //         current = current->next_;
  //     }

  //     os << "[NULL]";
  //     return os;
  // }

  /**
   * Constructs a single linked list by moving the contents of another single
   * linked list, setting its head pointer to null afterwards.
   * @param other the single linked list to move from
   * @return none
   * @throws none
   */
  template <class T>
  single_l<T>::single_l(single_l&& other) : head(nullptr) {
    head = other.head;
    other.head = nullptr;
  }

  /**
   * @brief Assignment operator for the single_l class.
   * @tparam T The type of elements in the list.
   * @param other The list to be assigned.
   * @return Reference to the modified list.
   */
  template <class T>
  single_l<T>& single_l<T>::operator=(const single_l& other) {
    if (this != &other) {
      clear();

      const single_l<T>::node* current = other.head;
      while (current != nullptr) {
        push_back(current->data_);
        current = current->next_;
      }
    }
    return *this;
  }
  /**
   * @brief Move assignment operator for the single_l class.
   * @tparam T The type of elements in the list.
   * @param other The list to be moved.
   * @return Reference to the modified list.
   */
  template <class T>
  single_l<T>& single_l<T>::operator=(single_l&& other) {
    if (this != &other) {
      clear();

      head = other.head;
      other.head = nullptr;
    }
    return *this;
  }

  /**
   * Adds a new node with the given data to the end of the linked list.
   * @param data the data to be added to the linked list
   * @return void
   * @throws none
   */
  template <class T>
  void single_l<T>::push_back(const T& data) {
    single_l<T>::node* new_node = new single_l<T>::node{ data, nullptr };

    if (head == nullptr) {
      head = new_node;
    }
    else {
      single_l<T>::node* current = head;
      while (current->next_ != nullptr) {
        current = current->next_;
      }
      current->next_ = new_node;
    }
    return;
  }

  /**
   * Adds a new node to the front of the linked list.
   * @param data The data to be stored in the new node.
   * @return void.
   * @throws None.
   */
  template <class T>
  void single_l<T>::push_front(const T& data) {
    single_l<T>::node* new_node = new single_l<T>::node{ data, head };
    head = new_node;
    return;
  }

  /**
   * Removes the last element of the single linked list. Throws a runtime error
   * if the list is empty.
   * @throws std::runtime_error [pop_back()]  [list is empty]
   */
  template <class T>
  void single_l<T>::pop_back() {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[pop_back()]  [list is empty]\n");
      }
      else if (head->next_ == nullptr) {
        delete head;
        head = nullptr;
      }
      else {
        single_l<T>::node* current = head;
        while (current->next_->next_ != nullptr) {
          current = current->next_;
        }
        delete current->next_;
        current->next_ = nullptr;
      }
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
    return;
  }

  /**
   * Pops the first element from the list.
   * @param None
   * @return None
   * @throws std::runtime_error if the list is empty
   */
  template <class T>
  void single_l<T>::pop_front() {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[pop_front()]  [list is empty]\n");
      }
      single_l<T>::node* temp = head;
      head = head->next_;
      delete temp;
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
    return;
  }

  /**
   * Recursively prints the linked list in reverse order, starting from the given node.
   * @param current pointer to the current node being processed
   * @return void
   * @throws none
   */
  template <class T>
  void single_l<T>::print_reverse_helper(single_l<T>::node* current) {
    if (current == nullptr) {
      return;
    }
    print_reverse_helper(current->next_);
    std::cout << current->data_ << " ";
  }

  /**
   * Prints the contents of the list in reverse order.
   * @throws std::runtime_error if the list is empty
   */
  template <class T>
  void single_l<T>::print_reverse() {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[print_reverse()]  [list is empty]");
      }
      std::cout << "{ ";
      print_reverse_helper(head);
      std::cout << "}";
      std::cout << std::endl;
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
  }

  /**
   * Clears the linked list by deleting all nodes. Starts from the head of the
   * linked list and deletes each node until the list is empty.
   * @param None
   * @return None
   * @throws None
   */
  template <class T>
  void single_l<T>::clear() {
    while (head != nullptr) {
      single_l<T>::node* temp = head;
      head = head->next_;
      delete temp;
    }
  }

  /**
   * Swaps the head of this list with another list's head.
   * @param other The other list to swap heads with.
   * @throws None
   */
  template <class T>
  void single_l<T>::swap(single_l& other) {
    std::swap(head, other.head);
  }

  /**
   * Determines whether the single_l<T> object is empty.
   * @return true if the object is empty, false otherwise
   */
  template <class T>
  bool single_l<T>::empty() {
    return (head == nullptr) ? true : false;
  }

  /**
   * Returns the number of nodes in the linked list.
   * @param None
   * @return size_t The number of nodes in the linked list.
   * @throws None
   */
  template <class T>
  size_t single_l<T>::size() {
    size_t count = 0;
    single_l<T>::node* current = head;
    while (current != nullptr) {
      count++;
      current = current->next_;
    }
    return count;
  }

  /**
   * @brief Returns a reference to the first element in the list.
   * @tparam T The type of elements in the list.
   * @return Reference to the first element.
   * @throw std::runtime_error If the list is empty.
   */
  template <class T>
  T& single_l<T>::front() {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[front()]  [list is empty]");
      }
      return head->data_;
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
    static T default_value;
    return default_value;
  }

  /**
   * @brief Returns a reference to the last element in the list.
   * @tparam T The type of elements in the list.
   * @return Reference to the last element.
   * @throw std::runtime_error If the list is empty.
   */
  template <class T>
  T& single_l<T>::back() {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[back()]  [list is empty]");
      }
      single_l<T>::node* current = head;
      while (current->next_ != nullptr) {
        current = current->next_;
      }
      return current->data_;
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
    static T default_value;
    return default_value;
  }

  /**
   * @brief Returns a const reference to the first element in the list.
   * @tparam T The type of elements in the list.
   * @return Const reference to the first element.
   * @throw std::runtime_error If the list is empty.
   */
  template <class T>
  const T& single_l<T>::front() const {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[front() cosnt]  [list is empty]");
      }
      return head->data_;
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
    static T default_value;
    return default_value;
  }

  /**
   * @brief Returns a const reference to the last element in the list.
   * @tparam T The type of elements in the list.
   * @return Const reference to the last element.
   * @throw std::runtime_error If the list is empty.
   */
  template <class T>
  const T& single_l<T>::back() const {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[back() cosnt]  [list is empty]");
      }
      single_l<T>::node* current = head;
      while (current->next_ != nullptr) {
        current = current->next_;
      }
      return current->data_;
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
    static T default_value;
    return default_value;
  }

  /**
   * @brief Accesses the element at the specified index in the list.
   * @tparam T The type of elements in the list.
   * @param index The index of the element to access.
   * @return Reference to the element at the specified index.
   * @throw std::runtime_error If the list is empty.
   * @throw std::out_of_range If the index is out of range.
   */
  template <class T>
  T& single_l<T>::operator[](size_t index) {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[operator[]]  [list is empty]");
      }

      single_l<T>::node* current = head;
      size_t count = 0;
      while (current != nullptr) {
        if (count == index) {
          return current->data_;
        }
        current = current->next_;
        count++;
      }

      throw std::out_of_range("[operator[]]  [index out of range]");
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
    static T default_value;
    return default_value;
  }

  /**
   * @brief Accesses the element at the specified index in the list (const version).
   * @tparam T The type of elements in the list.
   * @param index The index of the element to access.
   * @return Const reference to the element at the specified index.
   * @throw std::runtime_error If the list is empty.
   * @throw std::out_of_range If the index is out of range.
   */
  template <class T>
  const T& single_l<T>::operator[](size_t index) const {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[operator[] const]  [list is empty]");
      }

      single_l<T>::node* current = head;
      size_t count = 0;
      while (current != nullptr) {
        if (count == index) {
          return current->data_;
        }
        current = current->next_;
        count++;
      }

      throw std::out_of_range("[operator[] const]  [index out of range]");
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
  }

  /**
   * @brief Accesses the element at the specified index in the list.
   * @tparam T The type of elements in the list.
   * @param index The index of the element to access.
   * @return Reference to the element at the specified index.
   * @throw std::runtime_error If the list is empty.
   * @throw std::out_of_range If the index is out of range.
   */
  template <class T>
  T& single_l<T>::at(size_t index) {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[at()]  [list is empty]");
      }

      single_l<T>::node* current = head;
      size_t count = 0;
      while (current != nullptr) {
        if (count == index) {
          return current->data_;
        }
        current = current->next_;
        count++;
      }

      throw std::out_of_range("[at()]  [index out of range]");
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
    }
    static T default_value;
    return default_value;
  }

  /**
   * @brief Deletes the element at the specified index in the list.
   * @tparam T The type of elements in the list.
   * @param index The index of the element to delete.
   * @throw std::runtime_error If the list is empty.
   * @throw std::out_of_range If the index is out of range.
   */
  template <class T>
  void single_l<T>::delete_at(size_t index) {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[delete_at()]  [list is empty]");
      }

      if (index == 0) {
        pop_front();
        return;
      }

      single_l<T>::node* current = head;
      single_l<T>::node* previous = nullptr;
      size_t count = 0;
      while (current != nullptr) {
        if (count == index) {
          if (previous != nullptr) {
            previous->next_ = current->next_;
          }
          else {
            head = current->next_;
          }
          delete current;
          return;
        }
        previous = current;
        current = current->next_;
        count++;
      }

      throw std::out_of_range("[delete_at()]  [index out of range]");
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
      throw; // rethrow the exception to propagate it
    }
  }

  /**
   * @brief Deletes the first occurrence of the specified value in the list.
   * @tparam T The type of elements in the list.
   * @param data The value to delete.
   * @throw std::runtime_error If the list is empty or the value is not found.
   */
  template <class T>
  void single_l<T>::delete_value(const T& data) {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[delete_value()]  [list is empty]");
      }

      single_l<T>::node* current = head;
      single_l<T>::node* previous = nullptr;

      while (current != nullptr) {
        if (current->data_ == data) {
          if (previous == nullptr) {
            head = current->next_;
          }
          else {
            previous->next_ = current->next_;
          }
          delete current;
          return;
        }

        previous = current;
        current = current->next_;
      }

      throw std::runtime_error("[delete_value()]  [value not found]");
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
      throw; // rethrow the exception to propagate it
    }
  }

  /**
   * Searches for the given data element in the single linked list and returns
   * the index of the first occurrence. If the element is not found, it returns
   * -1.
   * @param data  The element to search in the linked list.
   *
   * @return The index of the first occurrence of the element in the linked list.
   *         If the element is not found, it returns -1.
   * @throws None
   */
  template <class T>
  size_t single_l<T>::search(const T& data) {
    size_t index = 0;
    single_l<T>::node* current = head;
    while (current != nullptr) {
      if (current->data_ == data) {
        return index;
      }
      current = current->next_;
      index++;
    }
    return static_cast<size_t>(-1); // return -1 if value not found for clarity
  }

  /**
   * Inserts a new node with given data at the specified position in the linked list.
   * @param position_data the data to be inserted at the specified position
   * @param position the position at which the new node is to be inserted
   * @throws std::runtime_error if the list is empty
   * @throws std::out_of_range if the position is out of range
   */
  template <class T>
  void single_l<T>::at_position(const T& position_data, size_t position) {
    try {
      if (head == nullptr) {
        throw std::runtime_error("[at_position()]  [list is empty]");
      }

      single_l<T>::node* current = head;
      single_l<T>::node* previous = nullptr;
      size_t count = 0;

      while (current != nullptr) {
        if (count == position) {
          single_l<T>::node* new_node = new single_l<T>::node;
          new_node->data_ = position_data;
          new_node->next_ = current;

          if (previous == nullptr) {
            head = new_node;
          }
          else {
            previous->next_ = new_node;
          }

          return;
        }

        previous = current;
        current = current->next_;
        count++;
      }

      throw std::out_of_range("[at_position()]  [position out of range]");
    }
    catch (const std::exception& e) {
      std::cerr << "{error}: " << e.what() << std::endl;
      throw; // rethrow the exception to propagate it
    }
  }

  /**
   * Reverses the order of the nodes in a singly linked list.
   * @param none
   * @return void
   * @throws none
   */
  template <class T>
  void single_l<T>::reverse() {
    if (head == nullptr || head->next_ == nullptr) {
      return;
    }

    single_l<T>::node* current = head;
    single_l<T>::node* previous = nullptr;
    single_l<T>::node* next = nullptr;

    while (current != nullptr) {
      next = current->next_;
      current->next_ = previous;
      previous = current;
      current = next;
    }

    head = previous;
  }

  /**
   * Sorts the linked list in ascending order using bubble sort algorithm.
   * @param None.
   * @return None.
   * @throws None.
   */
  template <class T>
  void single::single_l<T>::sort() {
    if (head == nullptr || head->next_ == nullptr) {
      return;
    }

    bool swapped;
    single_l<T>::node* current;
    single_l<T>::node* last = nullptr;

    do {
      swapped = false;
      current = head;

      while (current->next_ != last) {
        if (current->data_ > current->next_->data_) {
          std::swap(current->data_, current->next_->data_);
          swapped = true;
        }
        current = current->next_;
      }

      last = current;
    } while (swapped);
  }

  /**
   * Removes duplicates from a singly linked list.
   * @param None
   * @return None
   * @throws None
   */
  template <class T>
  void single_l<T>::remove_duplicates() {
    if (head == nullptr || head->next_ == nullptr) {
      return;
    }

    std::unordered_set<T> unique_value;
    single_l<T>::node* current = head;
    single_l<T>::node* previous = nullptr;

    while (current != nullptr) {
      if (unique_value.count(current->data_) > 0) {
        previous->next_ = current->next_;
        delete current;
        current = previous->next_;
      }
      else {
        unique_value.insert(current->data_);
        previous = current;
        current = current->next_;
      }
    }
  }

  /**
   * Resizes the list to contain n elements.
   * @param n the new size of the list
   * @return void
   * @throws None
   */
  template <class T>
  void single::single_l<T>::resize(size_t n) {
    if (n == 0) {
      clear();
    }
    else if (n > size()) {
      size_t additional_nodes = n - size();

      if (head == nullptr) {
        head = new node;
        head->next_ = nullptr;
        additional_nodes--;
      }

      node* current = head;
      while (current->next_ != nullptr) {
        current = current->next_;
      }

      for (size_t i = 0; i < additional_nodes; i++) {
        node* new_node = new node;
        new_node->next_ = nullptr;
        current->next_ = new_node;
        current = new_node;
      }
    }
    else if (n < size()) {
      node* current = head;
      node* previous = nullptr;

      for (size_t i = 0; i < n; i++) {
        previous = current;
        current = current->next_;
      }

      while (current != nullptr) {
        node* next_node = current->next_;
        delete current;
        current = next_node;
      }

      previous->next_ = nullptr;
    }
  }
} //namespace single