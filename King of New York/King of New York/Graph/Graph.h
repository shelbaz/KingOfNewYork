#pragma once

#include "SinglyLinkedList.h"
#include <vector>
#include "GraphVertex.h"
#include "SinglyLinkedListNode.h"
#include <iostream>
#include <cstddef>
#include <string>

//a graph implementation using an adjacency list

template <class T>
class Graph
{
  private:
    int vertexCount; //the number of vertices the graph has
    SinglyLinkedList<T>* adjacencyList; //an array of linked lists that will have a position for each vertex and hold a linked list
                                          //containing all the vertices it is adjacent to
    GraphVertex<T>* vertexList; //array of vertices

  public:
    Graph(int); //constructor in which we pass the number of vertices
    ~Graph(); //destructor
    GraphVertex<T>* getVertex(int); //get the vertex at the specified index in the array of vertices
    void setVertexData(T,int); //set the data T for the vertex at index (int)
    void setVertexName(std::string, int); //set the name of the vertex at index (int)
    SinglyLinkedList<T>* getNeighbors(int); //get the neighbors of the vertex at the index passed to the function
    std::string toString(); //method to display the graph's contents to the console
    int getVertexCount(); //method to get the count of vertices in the graph
    void addNeighbor(T,int); //method to add a neighbor to a given vertex by passing it's index
};

template <class T>
Graph<T>::Graph(int vertices)
{
  vertexCount = vertices;
  //we need to allocate the memory for the two arrays
  adjacencyList = new SinglyLinkedList<T>[vertices];
  vertexList = new GraphVertex<T>[vertices];

  for(int i = 0; i<vertexCount; i++)
  {
    //set the index of each vertex in the list to i
    vertexList[i].setIndex(i);
  }
}

template <class T>
Graph<T>::~Graph()
{
  //destructor
  //when destroying the graph we need to delete the vertex list and the adjacency lists
  delete[] adjacencyList;
  delete[] vertexList;
}

template <class T>
SinglyLinkedList<T>* Graph<T>::getNeighbors(int i)
{
  SinglyLinkedList<T> * listPtr = &adjacencyList[i];
  return listPtr;
}

template <class T>
GraphVertex<T>* Graph<T>::getVertex(int i)
{
    //a method to get the vertex at the specified index in the vertex list array
    GraphVertex<T> * vertexPtr = &vertexList[i];
    return vertexPtr;
}

template <class T>
std::string Graph<T>::toString()
{
  std::string output = "";
  if(vertexCount == 0)
  {
    output += "[]\n";
  }

  else
  {
    for(int i = 0; i < vertexCount; i++)
    {
      output += vertexList[i].toString() +" -> "; // Region/ Zone

      output += adjacencyList[i].toString() + "\n"; // Connected regions and zones
    }
  }

  return output;
}

template <class T>
void Graph<T>::setVertexData(T data, int index)
{
  //sets the data for the vertex at the passed index
  //we only set the data if the index passed is valid
  if(index >= 0 && index < vertexCount)
  {
    vertexList[index].setData(data);
  }

}

template <class T>
void Graph<T>::setVertexName(std::string newName, int index)
{
  //set the name for the vertex at the passed index if the index is valid
  if(index >= 0 && index < vertexCount)
  {
    vertexList[index].setName(newName);
  }
}

template <class T>
int Graph<T>::getVertexCount()
{
  return vertexCount;
}

template <class T>
void Graph<T>::addNeighbor(T data, int index)
{
  node<T>* newNode = new node<T>();
  newNode -> setData(data);
  adjacencyList[index].add(newNode);
}
