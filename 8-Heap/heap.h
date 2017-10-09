#ifndef HEAP_H
#define HEAP_H

#include <vector>

using namespace std;

/**
   This class implements a heap.
*/
template<typename T>
class Heap
{
public:
   /**
      Constructs an empty heap.
   */
   Heap();

   /**
      Adds a new element to this heap.
      @param element the element to add
   */
   void push(T element);

   /**
      Gets the maximum element stored in this heap.
      @return the maximum element
   */
   T top() const;

   /**
      Removes the maximum element from this heap.
   */
   void pop();

   /**
      Gets the size of this heap.
      @return the size
   */
   int size() const;
private:
   /**
      Turns the tree back into a heap, provided only the root 
      node violates the heap condition.
   */
   void fix_heap();

   /**
      Returns the index of the left child.
      @param index the index of a node in this heap
      @return the index of the left child of the given node
   */
   int get_left_child_index(int index) const;

   /**
      Returns the index of the right child.
      @param index the index of a node in this heap
      @return the index of the right child of the given node
   */
   int get_right_child_index(int index) const;

   /**
      Returns the index of the parent.
      @param index the index of a node in this heap
      @return the index of the parent of the given node
   */
   int get_parent_index(int index) const;

   /**
      Returns the value of the left child.
      @param index the index of a node in this heap
      @return the value of the left child of the given node
   */
   T get_left_child(int index) const;

   /**
      Returns the value of the right child.
      @param index the index of a node in this heap
      @return the value of the right child of the given node
   */
   T get_right_child(int index) const;

   /**
      Returns the value of the parent.
      @param index the index of a node in this heap
      @return the value of the parent of the given node
   */
   T get_parent(int index) const;
   
   vector<T> elements;   
};

#endif
