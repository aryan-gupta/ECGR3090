
#include <iostream>
#include <functional>
#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree() : root{} { /* No Code */ }

void BinarySearchTree::insert(string element) {
	// get a pointer to root so we can modify it
	Node* current = root;
	
	// if tree is empty then we want to store the new node at root
	// else traverse the tree to find a leaf
	Node** place = (root == nullptr)? &root : &current;
	
	// taverse tree to find right leaf to create the node
	while (current != nullptr) { // never will be false unless root is nullptr
		if (current->data <= element) // insert to the right
			if (current->right == nullptr) { // leaf
				place = &current->right;
				break;
			} else {
				current = current->right;
				continue;
			}
		else // insert to the left
			if (current->left == nullptr) { // leaf
				place = &current->left;
				break;
			} else {
				current = current->left;
				continue;
			}
		
	}
	
	// *place = new Node{std::move(element), nullptr, nullptr}; // node should be a struct?
	*place = current = new Node;
	current->data    = std::move(element); // element should be a reference?
	current->left    = nullptr;
	current->right   = nullptr;
}

int BinarySearchTree::count(string element) const {
	Node* current = root;
	
	while (current != nullptr) {
		if (current->data == element)
			return 1;
		
		if (current->data <= element)
			current = current->right;
		else
			current = current->left;
	}
	
	return 0;
}

void BinarySearchTree::erase(string element) {
	auto remove_node = [&element](Node* rm) {
		Node* lrParent = rm, * leastR = lrParent->right;
		while (leastR->left != nullptr) {
			lrParent = leastR;
			leastR = leastR->left;
		}
		// leastR now contains the least value in the right side
		// and lrParent is its parent
		
		if (leastR->right != nullptr)
			lrParent->left = leastR->right; // we still have leastR so we dont lose the node
		
		rm->data = std::move(leastR->data);
		delete leastR;
		lrParent->left = nullptr;
	};
	
	std::function<void(Node*&)> erase_local = [&](Node*& rt) {
		if (rt == nullptr) return;
		
		if (rt->data == element) {
			if (rt->left == nullptr and rt->right == nullptr) {
				delete rt;
				rt = nullptr;
			} else if (rt->left == nullptr) {
				Node* tmp = rt->right;
				delete rt;
				rt = tmp;
			} else if (rt->right == nullptr) {
				Node* tmp = rt->left;
				delete rt;
				rt = tmp;
			} else {
				remove_node(rt);
			}
			return;
		}
		
		if (rt->data < element)
			erase_local(rt->right);
		else
			erase_local(rt->left);
	};
	
	// std::cout << element << std::endl;
	erase_local(root);
}


void BinarySearchTree::print() const {
	print(root);
	std::cout << endl;
}


void BinarySearchTree::print(Node* parent) const {
	if (parent == nullptr) return;
	
	print(parent->left);
	std::cout << parent->data << " ";
	print(parent->right);
}


void BinarySearchTree::add_node(Node* parent, Node* new_node) const {
	
}