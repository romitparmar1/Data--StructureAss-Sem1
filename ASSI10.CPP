#include<iostream.h>
#include<stdlib.h>

struct Node
{
    int data;
    Node *next;
};

Node *last = NULL;

void insertNode()
{
    int value;
    Node *newNode;

    cout << "\nEnter value: ";
    cin >> value;

    newNode = new Node;
    newNode->data = value;

    if(last == NULL)
    {
	last = newNode;
	newNode->next = last;
    }
    else
    {
	newNode->next = last->next;
	last->next = newNode;
	last = newNode;
    }

    cout << "\nNode inserted successfully";
}

void deleteNode()
{
    int value;
    Node *temp, *prev;

    if(last == NULL)
    {
	cout << "\nList is empty";
	return;
    }

    cout << "\nEnter value to delete: ";
    cin >> value;

    temp = last->next;
    prev = last;

    do
    {
	if(temp->data == value)
	{
	    if(temp == last && temp->next == last)
	    {
		last = NULL;
	    }
	    else
	    {
		prev->next = temp->next;

		if(temp == last)
		{
		    last = prev;
		}
	    }

	    delete temp;
	    cout << "\nNode deleted successfully";
	    return;
	}

	prev = temp;
	temp = temp->next;

    } while(temp != last->next);

    cout << "\nValue not found";
}

void modifyNode()
{
    int oldValue, newValue;
    Node *temp;

    if(last == NULL)
    {
	cout << "\nList is empty";
	return;
    }

    cout << "\nEnter value to modify: ";
    cin >> oldValue;

    temp = last->next;

    do
    {
	if(temp->data == oldValue)
	{
	    cout << "Enter new value: ";
	    cin >> newValue;

	    temp->data = newValue;

	    cout << "\nNode modified successfully";
	    return;
	}

	temp = temp->next;

    } while(temp != last->next);

    cout << "\nValue not found";
}

void display()
{
    Node *temp;

    if(last == NULL)
    {
	cout << "\nList is empty";
	return;
    }

    temp = last->next;

    cout << "\nCircular Linked List: ";

    do
    {
	cout << temp->data << " ";
	temp = temp->next;

    } while(temp != last->next);
}

int main()
{
    int choice;

    while(1)
    {
	cout << "\n\n--- SINGLY CIRCULAR LINKED LIST ---";
	cout << "\n1. Insert";
	cout << "\n2. Delete";
	cout << "\n3. Modify";
	cout << "\n4. Display";
	cout << "\n5. Exit";

	cout << "\n\nEnter your choice: ";
	cin >> choice;

	switch(choice)
	{
	    case 1:
		insertNode();
		break;

	    case 2:
		deleteNode();
		break;

	    case 3:
		modifyNode();
		break;

	    case 4:
		display();
		break;

	    case 5:
		exit(0);

	    default:
		cout << "\nInvalid choice";
	}
    }

    return 0;
}