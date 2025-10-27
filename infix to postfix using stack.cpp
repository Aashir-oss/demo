#include <iostream>
using namespace std;
int prec(char c) {
	if (c == '^')
	return 3;
	else if (c == '*' || c == '/')
	return 2;
	else if (c == '+' || c == '-')
	return 1;
	else
	return -1;
}
class Stack {
	char arr[100];	// Stack array

	int top; // Top index
	
	public:
	Stack() {
	top = -1;  // Initialize top to -1, meaning stack is empty
	}
	void push(char c) {
	if (top < 99) {  // Check if the stack is not full
	
	arr[++top] = c;  // Increment top and push the character

	}
	}

	void pop() {
	if (top >= 0) {   // Check if the stack is not empty
	
	top--;	// Decrement top

	} }
	char peek() {
	if (top >= 0) {
	// Return the top element
	return arr[top];
	           
	}
    // Return null character if stack is empty
	return NULL;
	}
	bool isEmpty() {
	return top == -1;    // Check if the stack is empty
	
	}
	
};

	string infixToPostfix(string str) {
	Stack s;
	string result;
	for (int i = 0; i < str.length(); i++) {
	char c = str[i];
	// If the character is an operand, add it to result
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
	result += c;
	}
	// If the character is '(', push it to stack
	else if (c == '(') {
	s.push(c);
	}
	// If the character is ')', pop and add to result until '(' is found
	else if (c == ')') {
	while (!s.isEmpty() && s.peek() != '(') {
	result += s.peek();
	s.pop();
	}
	s.pop();
	// Remove '(' from the stack
	}
	// If an operator is found
	else {
	while (!s.isEmpty() && prec(s.peek()) >= prec(c)) {
	result += s.peek();
	s.pop();
	}
	s.push(c); 	// Push the current operator to the stack

	} }
	// Pop all the remaining operators from the stack
	while (!s.isEmpty()) {
	result += s.peek();
	s.pop();
	}
	return result;
	}
	int main() {
	string expression = "K+L-M*N+(O^P)*W/U/V*T+Q";
	cout << "Infix: " << expression << endl;
	cout << "Postfix: " << infixToPostfix(expression) << endl;
	return 0;
	}
