
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
	printPretty(root, 1, 0, cout);
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
	auto root = findParentNode(fam.pivot_parent); // oops, this shadows a member data, oh well
	
	if (root->left == fam.pivot_parent) // we are under the left root
		root->left = fam.pivot;
	else // we are under the right root
		root->right = fam.pivot;
		
	fam.pivot_parent->left = fam.pivot->right;
	fam.pivot->right = fam.pivot_parent;
}


void BinarySearchTree::rotateLeft(Node *pivot) {	
	auto fam  = findFamily(pivot);
	auto root = findParentNode(fam.pivot_parent);
	
	if (root->left == fam.pivot_parent) // we are under the left root
		root->left = fam.pivot;
	else // we are under the right root
		root->right = fam.pivot;
	
	fam.pivot_parent->right = fam.pivot->left;
	fam.pivot->left = fam.pivot_parent;
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

/// EVERY THING BELOW THIS I COPIED FROM HERE
// imma get the above code working then worry about this
// https://articles.leetcode.com/how-to-pretty-print-binary-tree/
void BinarySearchTree::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
	  deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {  
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}


void BinarySearchTree::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
	  deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->key) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}


void BinarySearchTree::printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<Node*>& nodesQueue, ostream& out) {
	  deque<Node*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->key) : "");
  }
  out << endl;
}


void BinarySearchTree::printPretty(Node *root, int level, int indentSpace, ostream& out) {
	int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)
    
  deque<Node*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      Node *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->left);
	      nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}