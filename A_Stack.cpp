#include <iostream>
using namespace std;

/* defining the max_size of array*/
#define MAX_SIZE 50

class A_Stack {
	int top; //contains the top element of stack in array based implementation

public:
	char stack_array[MAX_SIZE];
	/* CONSTRUCTOR IMPLEMENTATION*/
	A_Stack() {
		top = -1;
	}

	/*FUNCTIONS definations  FOR ARRAY BASED STACK*/
	bool isEmpty();
	bool isFull();
	bool push(int x);
	char pop();
	char peek();
	bool areParanthesisBalanced(string exp);
	
};
/*implementation of functions defined for array_based stack*/
bool A_Stack::isEmpty() {
	if (top == -1)
	{
		cout << "list is empty!!!!!!!!!!!1\n";
		return true;
	}
	else {
		cout << "list is not empty!!!!!!!!!!1\n";
		return false;
	}
}

bool A_Stack::isFull() {
	if (top == MAX_SIZE)
	{
		cout << "list is full!!!!!!!!!1\n";
		return true;
	}
	else {
		cout << "list is not full\n";
		return false;
	}
}

char A_Stack::pop() {
	if (top > 0)
	{	/*decrementing the top and assigning that value to some variable a*/
		char a = stack_array[top--];
		return a;
	}
	else
	{
		/* if stack is empty nothing can be poped so return 0*/
		cout << "stack is empty!!!!!!!!!!! STACK UNDERFLOW OCCURED...... so no element can be popped\n";
		return 0;
	}
}

bool A_Stack::push(int value) {
	if (top < MAX_SIZE )
	{
		//inserting the value at top
		stack_array[++top] = value;
		//cout << "the value : \" " << value << " \" is pushed into stack\n";
		return true;
	}
	else
	{
		//else return false
		cout << "stack_array is full !!!!!!STACK OVERFLOW HAS OCCURED.... so value cannot be pushed\n";
		return false;
	}
}

char A_Stack::peek() {
	/*if stack is not empty so return top value*/
	if (!isEmpty())
	{
		char a = stack_array[top];
		return a;
	}
	else
	{
		cout << "stack is empty!!!!!!!!!!! STACK UNDERFLOW OCCURED...... \n";
		return '0';
	}
}

bool A_Stack::areParanthesisBalanced(string exp)
{
	char ch;

	for (int i = 0; i < exp.length(); i++)  // loop till the length of the expression
	{
		// WRITE CODE TO CHECK IF THE exp(i) IS AN OPENING BRACE
	   // THEN PUSH IT ON THE STACK AND CONTINUE		
		if (exp[i] == '(' || exp[i] == '['
			|| exp[i] == '{')
		{
			// Push the element in the stack 
			push(exp[i]);
			continue;
		}
		if (isEmpty())
			return false;

		switch (exp[i])
		{
		case ')':
			ch = stack_array[top];  // store the top in a variable 

			pop();   // pop the top
			if (ch == '{' || ch == '[') // check whether we have a similar opening brace or not, if not return false and break 
				return false;
			break;

		case '}':

			// WRITE CODE TO CHECK FOR CLOSING CURLING BRACE
			ch = stack_array[top];  // store the top in a variable 

			pop();   // pop the top
			if (ch == '(' || ch == '[') // check whether we have a similar opening brace or not, if not return false and break 
				return false;
			break;
		case ']':
			ch = stack_array[top];  // store the top in a variable 

			pop();   // pop the top
			if (ch == '{' || ch == '(') // check whether we have a similar opening brace or not, if not return false and break 
				return false;
			break;
			//WRITE CODE TO CHECK FOR CLOSING SQUARE BRACE
		}
	}

	return (isEmpty());
}


/***************************************************************************************************
            "HERE GOES OUR MAIN CODE FOR TESTING THE ARRAY BASED STACK FUNCTIONS"
****************************************************************************************************/

int main() {
	//creating object for accessing functions of A_Stack
	A_Stack obj;
	string exp="{([])}";

	//cout << "Enter the expression without pressing enter : ";
	//cin >> exp;

	if (obj.areParanthesisBalanced(exp))
		cout << "Expression is Balanced" << endl;
	else
		cout << "Expression is not Balanced" << endl;
	return 0;
	//pushing  2,4,6,8 into array based stack
	/*cout << "\n-----------------------------------------------------------------------------\n";
	cout << "(1)pushing 2,4,6,8 into the stack .........\n";
	obj->push(2);
	obj->push(4);
	obj->push(6);
	obj->push(8);

	cout << "\n-----------------------------------------------------------------------------\n";
	//poping fromthe stack
	cout <<endl<< "(2)poping the top from stack ......\n" << obj->pop()<<endl;
	cout << "\n-----------------------------------------------------------------------------\n";
	//getting the peek element
	cout <<endl<<"(3)peek element in stack is : " << obj->peek() << endl;*/
}