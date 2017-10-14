#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <functional>

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

template <typename T>
Heap<T>::Heap()
: elements{} { }


template <typename T>
void Heap<T>::push(T element) {
	std::function<void (size_t)> heapifyup = [&](size_t idx){
		size_t sz = elements.size();
		size_t pt = get_parent_index(idx);
		
		if (idx != 0 and elements[idx] < elements[pt]) {
			std::swap(elements[pt], elements[idx]);
			heapifyup(pt);
		}
	};
	
	elements.push_back(std::move(element));
	heapifyup(elements.size() - 1);
}


template <typename T>
T Heap<T>::top() const {
	// let vector handle empty heap
	return elements.at(0);
}


template <typename T>
void Heap<T>::pop() {
	elements[0] = elements.back(); // swap the last and first
	elements.pop_back(); // remove the last 
	fix_heap(); // fix heap (heapify down)
}


template <typename T>
int Heap<T>::size() const {
	return elements.size(); // size_t?
}


template <typename T>
void Heap<T>::fix_heap() {
	std::function<void (size_t)> heapifydown = [&](size_t idx) {
		size_t sz = elements.size();
		size_t lc = get_left_child_index(idx);
		size_t rc = get_right_child_index(idx);
		size_t max = idx;
		
		if (lc < sz and elements[lc] < elements[max])
			max = lc;
		
		if (rc < sz and elements[rc] < elements[max])
			max = rc;
		
		if (idx != max) {
			std::swap(elements[idx], elements[max]);
			heapifydown(max);
		}
	};
	
	heapifydown(0);
}


template <typename T>
int Heap<T>::get_left_child_index(int index) const {
	// im going to let bounds checking be handled
	// upframe (downframe?) as this is a private
	// member
	return index * 2 + 1;
}


template <typename T>
int Heap<T>::get_right_child_index(int index) const {
	// im going to let bounds checking be handled
	// upframe (downframe?) as this is a private
	// member
	return index * 2 + 2;
}


template <typename T>
int Heap<T>::get_parent_index(int index) const {
	// for an index of 6, the parent is
	// 5/2 (integer division) or 2 and
	// for an index of 5 the parent is
	// 4/2 or 2
	return (index - 1) / 2;
}


template <typename T>
T Heap<T>::get_left_child(int index) const {
	// going to relly on the vector's bound checking
	return elements.at(get_left_child_index(index));
}


template <typename T>
T Heap<T>::get_right_child(int index) const {
	// going to relly on the vector's bound checking
	return elements.at(get_right_child_index(index));
}


template <typename T>
T Heap<T>::get_parent(int index) const {
	// going to relly on the vector's bound checking
	return elements.at(get_parent_index(index));
}

#endif
