//
//  single_l.h
//  linked_list_xcode
//
//  Created by Jakob Balkovec on 13/06/2023.
//

#ifndef single_l_h
#define single_l_h

#include <iostream>


namespace single {
  template <class T>
  class single_l final {
  private:
    struct node {
      T data_;
      node* next_;
    };
    struct node* head;
    
  public:
    single_l();
    single_l(std::initializer_list<T>_init_);
    ~single_l();
    single_l(const single_l&);
    single_l(single_l&&);
    single_l& operator=(const single_l&);
    single_l& operator=(single_l&&);
    void push_back(const T&);
    void push_front(const T&);
    void pop_back();
    void pop_front();
    void print_reverse();
    void print_reverse_helper(single_l<T>::node* current);
    void clear();
    void swap(single_l&);
    bool empty();
    size_t size();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
    T& operator[](size_t);
    const T& operator[](size_t) const;
    T& at(size_t index); //inserts at index
    void delete_at(size_t index);
    void delete_value(const T &data);
    size_t search(const T &data);
    void at_position(const T& data, size_t position); //inserts at specific spot
    void reverse();
    void sort();
    void remove_duplicates();
    void resize(size_t n);

    friend std::ostream& operator<<(std::ostream& os, const single_l& list) noexcept {
      typename single_l<T>::node* current = list.head;
      while (current != nullptr) {
          os << "[" << current->data_ << "]->";
          current = current->next_;
      }

      os << "[NULL]";
      return os;
    }
  };
} //namespace single

#endif /* single_l_h */
