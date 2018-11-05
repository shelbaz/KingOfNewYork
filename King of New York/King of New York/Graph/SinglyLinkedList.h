#pragma once

#include <iostream>
#include <cstddef>
#include "SinglyLinkedListNode.h"
#include <string>
#include "StringFunctions.h"

template <class T>
class SinglyLinkedList
{

private:
	node<T> *head; //the first node in the list
	node<T> *tail; //the tail of the linked list
	int count; //the count of items in the list

public:
	SinglyLinkedList(); //constructor
	~SinglyLinkedList(); //destructor
	void add(node<T>*); //add a node to the head of the list
	void addLast(node<T>*); //add a node to the end of the list
	void remove(node<T>*); //remove a node from the list and delete it
	node<T>* search(node<T>*); //search the list for a particular node
	node<T>* pull(node<T>*); //this method pulls out the passed node from the linked list
	bool contains(node<T>*); //determines if the passed node is in the list
	std::string toString(); //display the linked list's contents
	int getCount(); //return the number of elements in the list
	void clear(); //clears all the content of the linked list
	node<T>* getHead(); //returns the head of the list
	node<T>* getTail(); //returns the tail of the list

};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	head = NULL; //set the head of the list to point at nothing
	tail = NULL; //set the tail of the list to null
	count = 0; //initially there are no items in the list
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	//class destructor
	//when it is called, we should clear our list
	this->clear();
}

template <class T>
void SinglyLinkedList<T>::add(node<T>* newNode)
{
	//if there are no elements in the list, just point the head to our node
	if (count == 0)
	{
		head = newNode;
		tail = newNode;
	}

	else
	{
		//otherwise we need to point the new node to the current head
		newNode->setNext(head);
		head = newNode;
	}

	//increase the size of the list by one
	count++;
}

template <class T>
void SinglyLinkedList<T>::addLast(node<T>* newNode)
{
	//if there is nothing in the list, then the head and the tail are the same
	if (count == 0)
	{
		head = newNode;
		tail = newNode;
	}

	else
	{
		//the node after the tail becomes the new node
		tail->setNext(newNode);
		//then the tail becomes the new node
		tail = newNode;
	}

	//increase the node count by one
	count++;
}

template <class T>
void SinglyLinkedList<T>::remove(node<T>* toRemove)
{
	//first check if the passed node is contained in the list
	if (this->contains(toRemove))
	{
		//if the node is in the list we need to remove it
		//start at the head
		node<T>* currentNode = head;

		//if the node to remove is the head, then we just set the head to the next node after the head
		//and delete the pointer to remove

		if (head == toRemove)
		{
			//move the currentNode to the next node
			currentNode = currentNode->getNext();
			//set the head to the currentNode, which is the second node in the list
			head = currentNode;
			//decrease the count by one
			count--;
			//delete the pointer to the old head
			delete toRemove;
			toRemove = NULL;
			return;
		}

		//if our node is not the head
		int i = 0;
		for (i = 0; i < count; i++)
		{

			if (currentNode->getNext() == toRemove)
			{

				//if the next node is the one we want to remove, set the next of the node we are at to the next of the node to remove
				currentNode->setNext(toRemove->getNext());

				//delete the node to remove
				delete toRemove;
				toRemove = NULL;
				//decrease count by one and return
				count--;
				return;
			}

			//move down the list
			currentNode = currentNode->getNext();
		}
	}

	else
	{
		//otherwise we have nothing to do
		return;
	}
}

template <class T>
node<T>* SinglyLinkedList<T>::search(node<T>* toFind)
{
	//a method that will search for a passed node in the list and will return null if the node is not found
	if (count == 0)
	{
		return NULL;
	}

	else
	{
		//start at the head
		node<T>* currentNode = head;

		int i = 0;

		for (i = 0; i < count; i++)
		{
			//for each element in the list, check if the pointers are equal.
			if (currentNode == toFind)
			{
				//if they point to the same object, return true
				return currentNode;
			}

			else
			{
				//otherwise, move the currentNode to the next node
				currentNode = currentNode->getNext();
			}
		}

		//if we exit the loop it means it was not found
		return NULL;
	}

}

template <class T>
node<T>* SinglyLinkedList<T>::pull(node<T>* toRemove)
{
	//first check if the passed node is contained in the list
	if (this->contains(toRemove))
	{
		//if the node is in the list we need to remove it
		//start at the head
		node<T>* currentNode = head;

		//if the node to remove is the head, then we just set the head to the next node after the head
		//and delete the pointer to remove

		if (head == toRemove)
		{
			//move the currentNode to the next node
			currentNode = currentNode->getNext();
			//set the head to the currentNode, which is the second node in the list
			head = currentNode;
			//decrease the count by one
			count--;
			return toRemove; //return the node that was removed
		}

		//if our node is not the head
		int i = 0;
		for (i = 0; i < count; i++)
		{
			if (currentNode->getNext() == toRemove)
			{
				//if the next node is the one we want to remove, set the next of the node we are at to the next of the node to remove
				currentNode->setNext(toRemove->getNext());

				//decrease count by one and return the node
				count--;
				return toRemove;
			}

			//move down the list
			currentNode = currentNode->getNext();
		}
	}

	else
	{
		//otherwise we have nothing to do
		return NULL;
	}
}

template <class T>
bool SinglyLinkedList<T>::contains(node<T>* toFind)
{
	if (count == 0)
	{
		return false;
	}

	else
	{
		//start at the head
		node<T>* currentNode = head;

		int i = 0;

		for (i = 0; i < count; i++)
		{
			//for each element in the list, check if the pointers are equal.
			if (currentNode == toFind)
			{
				//if they point to the same object, return true
				return true;
			}

			else
			{
				//otherwise, move the currentNode to the next node
				currentNode = currentNode->getNext();
			}
		}

		//if we exit the loop it means it was not found
		return false;
	}

}

template <class T>
std::string SinglyLinkedList<T>::toString()
{
	std::string output = "";

	if (count == 0)
	{
		output += "[]\n";
	}


	else
	{
		//start at the head of the list.
		node<T> *currentNode = head;
		output += "[";

		int i = 0;

		for (i = 0; i < count; i++)
		{
			if (i == count - 1)
			{
				output += libString::to_string(currentNode->getData());
			}

			else
			{
				output += libString::to_string(currentNode->getData()) + ", ";
			}

			currentNode = currentNode->getNext();
		}

		output += "]";
	}

	return output;
}

template <class T>
int SinglyLinkedList<T>::getCount()
{
	return count;
}

template <class T>
void SinglyLinkedList<T>::clear()
{

  if(count == 0)
  {
    return;
  }

  else if(count == 1)
  {
    delete head;
    head = NULL;
  }

  else
  {
    node<T>* pointer = head;
    node<T>* temp;

    while (pointer != NULL)
    {
      temp = pointer -> getNext();
      delete pointer;
      pointer = temp;
    }

  }
}

template <class T>
node<T>* SinglyLinkedList<T>::getHead()
{
	return head;
}

template <class T>
node<T>* SinglyLinkedList<T>::getTail()
{
	return tail;
}
