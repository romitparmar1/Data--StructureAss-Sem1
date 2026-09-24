#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

void addElement(int[], int *, int *, int *, int *, int);
int removeElement(int[], int *, int *, int *, int *);
void showFront(int[], int, int);
void updateElement(int[], int *, int *, int *, int *);
void showElements(int[], int *, int *, int *, int *);

void main()
{
    int data[10];
    int frontA = -1, rearA = -1;
    int frontB = 10, rearB = 10;
    int choice, value, deleted;

    do
    {
        cout << "\n\n===== DEQUEUE MENU =====";
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

        addElement(data, &frontA, &rearA,
                   &frontB, &rearB, value);
        break;

    case 2:
        deleted = removeElement(data, &frontA, &rearA,
                                &frontB, &rearB);

        if(deleted != -1)
        {
            cout << "\nDeleted Value : " << deleted;
        }
        break;

    case 3:
        showFront(data, frontA, frontB);
        break;

    case 4:
        updateElement(data, &frontA, &rearA,
                      &frontB, &rearB);
        break;

    case 5:
        showElements(data, &frontA, &rearA,
                     &frontB, &rearB);
        break;

    case 6:
        exit(0);

    default:
        cout << "\nInvalid Choice";
    }

    } while(1);
}

void addElement(int data[10], int *frontA, int *rearA,
                int *frontB, int *rearB, int value)
{
    int side;

    if(*rearA == *rearB - 1)
    {
        cout << "\nDequeue Is Full";
        return;
    }

    cout << "\n1. Insert In First Queue";
    cout << "\n2. Insert In Second Queue";

    cout << "\nEnter Side Choice : ";
    cin >> side;

    if(side == 1)
    {
        *rearA = *rearA + 1;
        data[*rearA] = value;

        if(*frontA == -1)
        {
            *frontA = 0;
        }

        cout << "\nValue Inserted In First Queue";
    }
    else if(side == 2)
    {
        *rearB = *rearB - 1;
        data[*rearB] = value;

        if(*frontB == 10)
        {
            *frontB = 9;
        }

        cout << "\nValue Inserted In Second Queue";
    }
    else
    {
        cout << "\nPlease Select Only 1 Or 2";
    }
}

int removeElement(int data[10], int *frontA, int *rearA,
                  int *frontB, int *rearB)
{
    int side;
    int deletedValue;

    cout << "\n1. Delete From First Queue";
    cout << "\n2. Delete From Second Queue";

    cout << "\nEnter Delete Choice : ";
    cin >> side;

    if(side == 1)
    {
        if(*frontA == -1)
        {
            cout << "\nFirst Queue Is Empty";
            return -1;
        }

        deletedValue = data[*frontA];

        if(*frontA == *rearA)
        {
            *frontA = -1;
            *rearA = -1;
        }
        else
        {
            *frontA = *frontA + 1;
        }

        return deletedValue;
    }

    else if(side == 2)
    {
        if(*frontB == 10)
        {
            cout << "\nSecond Queue Is Empty";
            return -1;
        }

        deletedValue = data[*frontB];

        if(*frontB == *rearB)
        {
            *frontB = 10;
            *rearB = 10;
        }
        else
        {
            *frontB = *frontB - 1;
        }

        return deletedValue;
    }

    cout << "\nInvalid Choice";
    return -1;
}

void showFront(int data[10], int frontA, int frontB)
{
    int side;

    cout << "\n1. Peep First Queue";
    cout << "\n2. Peep Second Queue";

    cout << "\nEnter Peep Choice : ";
    cin >> side;

    if(side == 1)
    {
        if(frontA == -1)
        {
            cout << "\nFirst Queue Is Empty";
            return;
        }

        cout << "\nFirst Queue Front Value : "
             << data[frontA];
    }

    else if(side == 2)
    {
        if(frontB == 10)
        {
            cout << "\nSecond Queue Is Empty";
            return;
        }

        cout << "\nSecond Queue Front Value : "
             << data[frontB];
    }

    else
    {
        cout << "\nInvalid Choice";
    }
}

void updateElement(int data[10], int *frontA, int *rearA,
                   int *frontB, int *rearB)
{
    int side, position, value;

    cout << "\n1. Modify First Queue";
    cout << "\n2. Modify Second Queue";

    cout << "\nEnter Modify Choice : ";
    cin >> side;

    cout << "\nEnter Position : ";
    cin >> position;

    cout << "\nEnter New Value : ";
    cin >> value;

    if(side == 1)
    {
        if(*frontA == -1)
        {
            cout << "\nFirst Queue Is Empty";
            return;
        }

        if(position < *frontA || position > *rearA)
        {
            cout << "\nInvalid Position";
            return;
        }

        data[position] = value;

        cout << "\nFirst Queue Updated Successfully";
    }

    else if(side == 2)
    {
        if(*frontB == 10)
        {
            cout << "\nSecond Queue Is Empty";
            return;
        }

        if(position > *frontB || position < *rearB)
        {
            cout << "\nInvalid Position";
            return;
        }

        data[position] = value;

        cout << "\nSecond Queue Updated Successfully";
    }

    else
    {
        cout << "\nInvalid Modify Choice";
    }
}

void showElements(int data[10], int *frontA, int *rearA,
                  int *frontB, int *rearB)
{
    int side;
    int index;

    cout << "\n1. Display First Queue";
    cout << "\n2. Display Second Queue";

    cout << "\nEnter Display Choice : ";
    cin >> side;

    if(side == 1)
    {
        if(*frontA == -1)
        {
            cout << "\nFirst Queue Is Empty";
            return;
        }

        index = *frontA;

        while(index <= *rearA)
        {
            cout << "\nFirst Queue : " << data[index];
            index++;
        }
    }

    else if(side == 2)
    {
        if(*frontB == 10)
        {
            cout << "\nSecond Queue Is Empty";
            return;
        }

        index = *frontB;

        while(index >= *rearB)
        {
            cout << "\nSecond Queue : " << data[index];
            index--;
        }
    }

    else
    {
        cout << "\nInvalid Display Choice";
    }
}