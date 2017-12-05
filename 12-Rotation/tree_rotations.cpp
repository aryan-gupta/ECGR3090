
#include <iostream>
#include <functional>
#include <deque>
#include <vector>

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
	int width = maxHeight(root);
	std::vector<std::deque<Node*>> tree(width);
	cout << width << endl;
	tree[0].push_back(root);
	for (int i = 1; i < width - 1; ++i) {
		cout << tree[i - 1].size() << endl;
		for (int j = 0; j < tree[i - 1].size(); ++j) {
			cout << i << ' ' << j << '\t' << tree[i - 1][j]->key << endl;
			if (tree[i - 1][j] == nullptr) {
				tree[i].push_back(nullptr);
				tree[i].push_back(nullptr);
			} else {
				tree[i].push_back(tree[i - 1][j]->left);
				tree[i].push_back(tree[i - 1][j]->right);
			}
		}
	}
	
	for (auto e1 : tree) {
		for (auto e2 : e1) {
			if (e2 == nullptr)
				cout << ' ';
			else 
				cout << e2->key;
		}
		cout << endl;
	}
}


Node* BinarySearchTree::findNode(int key) const {
	Node* current = root;
	
	while (current != nullptr) {
		if (current->key == key)
			return current;
		
		if (current->key <= key)
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
		
		if (current->key <= node->key)
			current = current->right;
		else
			current = current->left;
	}
	
	return nullptr;
}


pivotFamily BinarySearchTree::findFamily(Node *pivot) {
	Node* parent = findParentNode(pivot);
	return {pivot, pivot->left, pivot->right, parent, parent->left, parent->right};
}


void BinarySearchTree::rotateRight(Node *pivot) {
	auto fam  = findFamily(pivot);
	auto root = findParentNode(fam.pivot_parent);
	if (root->left == fam.pivot_parent) // we are under the left root
		root->left = fam.pivot;
	else // we are under the right root
		root->right = fam.pivot;
		
	fam.pivot_parent->right = fam.pivot->left;
	fam.pivot->left = fam.pivot_parent;
}


void BinarySearchTree::rotateLeft(Node *pivot) {
	auto fam  = findFamily(pivot);
	auto root = findParentNode(fam.pivot_parent); // oops, this shadows a member data, oh well
	if (root->left == fam.pivot_parent) // we are under the left root
		root->left = fam.pivot;
	else // we are under the right root
		root->right = fam.pivot;
		
	fam.pivot_parent->left = fam.pivot->right;
	fam.pivot->right = fam.pivot_parent;
}


void BinarySearchTree::add_node(Node* parent, Node* new_node) const {
	
}


int BinarySearchTree::maxHeight(Node *p) const {
	if (p == nullptr) return 0;
	int lHeight = maxHeight(p->left), rHeight = maxHeight(p->right);
	return (lHeight > rHeight)? lHeight + 1 : rHeight + 1;
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