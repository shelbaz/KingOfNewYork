#pragma once
//the header file for a generic singly linked list node
#include <cstddef>
#include <iostream>

template <class T>
class node
{
  private:
    T data;
    node *next;
  public:
    node(); //constructor
    ~node(); //destructor
    T getData();
    void setData(T);
    node<T>* getNext();
    void setNext(node<T>*);
    void display();
};

template <class T>
node<T>::node()
{
  //constructor
  next = NULL;
}

template <class T>
node<T>::~node()
{
  //the destructor for the node class
  
}

template <class T>
T node<T>::getData()
{
  return data;
}

template <class T>
void node<T>::setData(T newData)
{
  data = newData;
}

template <class T>
node<T>* node<T>::getNext()
{
  return next;
}

template <class T>
void node<T>::setNext(node<T>* newNode)
{
  next = newNode;
}

template <class T>
void node<T>::display()
{
  std::cout << data;
}

