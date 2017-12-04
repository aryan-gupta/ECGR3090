
#include <iostream>
#include <functional>
#include "tree_rotations.h"

BinarySearchTree::BinarySearchTree() : root{} { /* No Code */ }

void BinarySearchTree::insert(int element) {
	// get a pointer to root so we can modify it
	Node* current = root;
	
	// if tree is empty then we want to store the new node at root
	// else traverse the tree to find a leaf
	Node** place = (root == nullptr)? &root : &current;
	
	// taverse tree to find right leaf to create the node
	while (current != nullptr) { // never will be false unless root is nullptr
		if (current->key <= element) // insert to the right
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
	current->key     = std::move(element); // element should be a reference?
	current->left    = nullptr;
	current->right   = nullptr;
}


void BinarySearchTree::pretty_display() {
	
}


Node* BinarySearchTree::findNode(int key) const {
	Node* current = root;
	
	while (current != nullptr) {
		if (current->data == key)
			return current;
		
		if (current->data <= key)
			current = current->right;
		else
			current = current->left;
	}
	
	return nullptr;
}


Node* BinarySearchTree::findParentNode(Node *node) const {
	Node* current = root;
	
	while (current != nullptr) {
		if (current->left == node or current->right == node)
			return current;
		
		if (current->data <= key)
			current = current->right;
		else
			current = current->left;
	}
	
	return nullptr;
}


pivotFamily BinarySearchTree::findFamily(Node *pivot) {
	
}


void BinarySearchTree::rotateRight(Node *pivot) {
	
}


void BinarySearchTree::rotateLeft(Node *pivot) {
	
}


void BinarySearchTree::add_node(Node* parent, Node* new_node) const {
	
}


int BinarySearchTree::maxHeight(Node *p) const {
	
}


string BinarySearchTree::intToString(int val) {
	return std::to_string(val);
}


void BinarySearchTree::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
	
}


void BinarySearchTree::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
	
}


void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
	
}


void printPretty(Node *root, int level, int indentSpace, ostream& out) {
	
}