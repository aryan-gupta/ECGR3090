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
string expr1 = "(()()()())";
string expr2 = "{[(])}";
string expr3 = "(()){}()";
string expr4 = "{[(])}";
string expr5 = "{[()]}";
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
bool parenMatch(string expression) 
{

 // Your code here...

}