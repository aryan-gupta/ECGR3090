/*A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])}is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:

It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given  strings of brackets, determine whether each sequence of brackets is balanced.

 

Use the following test file - 
*/


#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
This program uses a stack to check whether an expression has balanced 
parentheses.
*/
bool parenMatch(string expression);

int main()
{
	string expr1 = "(()()()())"; // bal
	string expr2 = "{[(])}"; // unbal
	string expr3 = "(()){}()"; // bal
	string expr4 = "{[(])}"; // unbal
	string expr5 = "{[()]}"; // bal
	if (parenMatch(expr1))
		cout << "Parantheses balanced in expr1" << endl;
	else
		cout << "Parentheses unbalanced in expr1" << endl;
	
	if (parenMatch(expr2))
		cout << "Parantheses balanced in expr2" << endl;
	else
		cout << "Parentheses unbalanced in expr2" << endl;
	
	if (parenMatch(expr3))
		cout << "Parantheses balanced in expr3" << endl;
	else
		cout << "Parentheses unbalanced in expr3" << endl;
	
	if (parenMatch(expr4))
		cout << "Parantheses balanced in expr4" << endl;
	else
		cout << "Parentheses unbalanced in expr4" << endl;
	
	if (parenMatch(expr5))
		cout << "Parantheses balanced in expr5" << endl;
	else
		cout << "Parentheses unbalanced in expr5" << endl;
	return 0;
}


char getComplement(const char p) {
	switch (p) {
		case '(': return ')';
		case '{': return '}';
		case '[': return ']';
		case ')': return '(';
		case '}': return '{';
		case ']': return '[';
	}
}

bool parenMatch(string expression) {
	std::stack<char> paren;
	for (char ch : expression) {
		switch (ch) { // chars are bassically integer types so we can do this
			case '(':
			case '{':
			case '[':
				paren.push(ch);
			break;
			
			case ')':
			case '}':
			case ']': {
				if (paren.top() != getComplement(ch)) {
					return false;
				} else {
					paren.pop();
				}
			} break;
			
			default:
				std::cerr << "ERROR::PARENMATCH::INVALID_CHARACTER" << std::endl;
			break;
		}
	}
	
	if (paren.empty()) return true;
	else return false;
}