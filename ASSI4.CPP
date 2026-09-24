#include <iostream.h>
#include <conio.h>

void insertQueue(int[], int *, int *, int);
int deleteQueue(int[], int *, int *);
void peekQueue(int[], int *);
void changeValue(int[], int *, int *, int, int);
void showQueue(int[], int *, int *);

void main()
{
    int queue[10];
    int front = -1, rear = -1;
    int choice, value, deleted, position;

    do
    {
        cout << "\n\n===== QUEUE MENU =====";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Peep";
        cout << "\n4. Modify";
        cout << "\n5. Display";
        cout << "\n6. Exit";

        cout << "\n\nEnter Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter Value : ";
                cin >> value;

                insertQueue(queue, &front, &rear, value);
                break;

            case 2:
                deleted = deleteQueue(queue, &front, &rear);

                if(deleted != -1)
                {
                    cout << "\nDeleted Element : " << deleted;
                }
                break;

            case 3:
                peekQueue(queue, &front);
                break;

            case 4:
                cout << "\nEnter Position : ";
                cin >> position;

                cout << "\nEnter New Value : ";
                cin >> value;

                changeValue(queue, &front, &rear, position, value);
                break;

            case 5:
                showQueue(queue, &front, &rear);
                break;

            case 6:
                cout << "\nProgram Ended";
                break;

            default:
                cout << "\nInvalid Choice";
        }

    } while(choice != 6);

    getch();
}

void insertQueue(int queue[10], int *front, int *rear, int value)
{
    if(*rear >= 9)
    {
        cout << "\nQueue Overflow";
        return;
    }

    *rear = *rear + 1;
    queue[*rear] = value;

    if(*front == -1)
    {
        *front = 0;
    }

    cout << "\nValue Inserted Successfully";
}

int deleteQueue(int queue[10], int *front, int *rear)
{
    int element;

    if(*front == -1)
    {
        cout << "\nQueue Is Empty";
        return -1;
    }

    element = queue[*front];

    if(*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = *front + 1;
    }

    return element;
}

void peekQueue(int queue[10], int *front)
{
    if(*front == -1)
    {
        cout << "\nQueue Is Empty";
        return;
    }

    cout << "\nFront Element : " << queue[*front];
}

void changeValue(int queue[10], int *front, int *rear,
                 int position, int value)
{
    if(*front == -1)
    {
        cout << "\nQueue Is Empty";
        return;
    }

    if(position < *front || position > *rear)
    {
        cout << "\nInvalid Position";
        return;
    }

    queue[position] = value;

    cout << "\nValue Modified Successfully";
}

void showQueue(int queue[10], int *front, int *rear)
{
    int index;

    if(*front == -1)
    {
        cout << "\nQueue Is Empty";
        return;
    }

    cout << "\nQueue Elements : ";

    index = *front;

    while(index <= *rear)
    {
        cout << " " << queue[index];
        index++;
    }
}