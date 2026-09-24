#include <iostream.h>
#include <stdlib.h>

void insertCircular(int[], int *, int *, int);
int deleteCircular(int[], int *, int *);
void displayCircular(int[], int, int);

int main()
{
    int queue[10];
    int front = -1, rear = -1;
    int choice, value, deleted;

    while(1)
    {
	cout << "\n\n1. Insert";
	cout << "\n2. Delete";
	cout << "\n3. Display";
	cout << "\n4. Exit";

	cout << "\n\nEnter Your Choice : ";
	cin >> choice;

	switch(choice)
	{
	    case 1:
		cout << "\nEnter Value : ";
		cin >> value;

		insertCircular(queue, &front, &rear, value);
		break;

            case 2:
                deleted = deleteCircular(queue, &front, &rear);

                if(deleted != -1)
                {
                    cout << "\nDeleted Value : " << deleted;
                }
                break;

            case 3:
                displayCircular(queue, front, rear);
                break;

            case 4:
                exit(0);

            default:
                cout << "\nInvalid Choice";
        }
    }

    return 0;
}

void insertCircular(int queue[10], int *front, int *rear, int value)
{
    if((*rear + 1) % 10 == *front)
    {
        cout << "\nCircular Queue Is Full";
        return;
    }

    if(*front == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        *rear = (*rear + 1) % 10;
    }

    queue[*rear] = value;

    cout << "\nValue Inserted Successfully";
}

int deleteCircular(int queue[10], int *front, int *rear)
{
    int value;

    if(*front == -1)
    {
        cout << "\nCircular Queue Is Empty";
        return -1;
    }

    value = queue[*front];

    if(*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = (*front + 1) % 10;
    }

    return value;
}

void displayCircular(int queue[10], int front, int rear)
{
    int index;

    if(front == -1)
    {
        cout << "\nCircular Queue Is Empty";
        return;
    }

    index = front;

    cout << "\nCircular Queue Elements : ";

    while(1)
    {
        cout << "\n" << queue[index];

        if(index == rear)
        {
            break;
        }

        index = (index + 1) % 10;
    }
}