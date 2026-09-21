#include<iostream.h>
#include<stdlib.h>

void push(int stack[10], int *top, int value)
{
    if(*top >= 9)
    {
	cout << "\nStack Overflow";
    }
    else
    {
	(*top)++;
	stack[*top] = value;
    }
}

void pop(int stack[10], int *top)
{
    if(*top < 0)
    {
	cout << "\nStack is Empty";
    }
    else
    {
	cout << "\nPopped Value : " << stack[*top];
	(*top)--;
    }
}

void peep(int stack[10], int top)
{
    if(top < 0)
    {
	cout << "\nStack is Empty";
    }
    else
    {
	cout << "\nPeep Value : " << stack[top];
    }
}

void modify(int stack[10], int *top, int position, int value)
{
    if(*top < 0)
    {
	cout << "\nStack is Empty";
    }
    else if(position < 0 || position > *top)
    {
	cout << "\nInvalid Position";
    }
    else
    {
	stack[position] = value;
	cout << "\nValue Modified Successfully";
    }
}

void display(int stack[10], int top)
{
    if(top < 0)
    {
	cout << "\nStack is Empty";
	return;
    }

    while(top >= 0)
    {
	cout << "\nStack : " << stack[top];
	top--;
    }
}

void main()
{
    int stack[10], top = -1;
    int choice, value, position;

    do
    {
	cout << "\n1. Push";
	cout << "\n2. Pop";
	cout << "\n3. Peep";
	cout << "\n4. Modify";
	cout << "\n5. Display";
	cout << "\n6. Exit";

	cout << "\nEnter Your Choice : ";
	cin >> choice;

	switch(choice)
	{
	    case 1:
		cout << "\nEnter The Value : ";
		cin >> value;
		push(stack, &top, value);
		break;

	    case 2:
		pop(stack, &top);
		break;

	    case 3:
		peep(stack, top);
		break;

	    case 4:
		cout << "\nEnter The Position : ";
		cin >> position;
		cout << "\nEnter The Value : ";
		cin >> value;
		modify(stack, &top, position, value);
		break;

	    case 5:
		display(stack, top);
		break;

	    case 6:
		exit(0);
		break;

	    default: cout << "\nWrong Choice";
	}

    }while(1);
}
