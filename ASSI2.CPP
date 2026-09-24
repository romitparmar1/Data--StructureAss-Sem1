#include <iostream.h>
#include <stdlib.h>

void push(int arr[10], int *leftTop, int *rightTop, int value)
{
    int choice;

    if (*leftTop + 1 == *rightTop)
    {
        cout << "\nStack Overflow";
        return;
    }

    cout << "\n1. Pre-Stack";
    cout << "\n2. De-Stack";
    cout << "\nEnter Stack Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        *leftTop = *leftTop + 1;
        arr[*leftTop] = value;
        cout << "\nValue inserted in Pre-Stack";
        break;

    case 2:
        *rightTop = *rightTop - 1;
        arr[*rightTop] = value;
        cout << "\nValue inserted in De-Stack";
        break;

    default:
        cout << "\nInvalid Stack Choice";
    }
}

void pop(int arr[10], int *leftTop, int *rightTop)
{
    int choice;

    cout << "\n1. Pop From Pre-Stack";
    cout << "\n2. Pop From De-Stack";
    cout << "\nEnter Pop Choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        if (*leftTop < 0)
        {
            cout << "\nPre-Stack is Empty";
        }
        else
        {
            cout << "\nDeleted Value : " << arr[*leftTop];
            *leftTop = *leftTop - 1;
        }
        break;

    case 2:
        if (*rightTop >= 10)
        {
            cout << "\nDe-Stack is Empty";
        }
        else
        {
            cout << "\nDeleted Value : " << arr[*rightTop];
            *rightTop = *rightTop + 1;
        }
        break;

    default:
        cout << "\nInvalid Pop Choice";
    }
}

void peep(int arr[10], int *leftTop, int *rightTop)
{
    int choice;

    cout << "\n1. Peep Pre-Stack";
    cout << "\n2. Peep De-Stack";
    cout << "\nEnter Peep Choice : ";
    cin >> choice;

    if (choice == 1)
    {
        if (*leftTop < 0)
        {
            cout << "\nPre-Stack is Empty";
        }
        else
        {
            cout << "\nTop Value of Pre-Stack : "
                 << arr[*leftTop];
        }
    }
    else if (choice == 2)
    {
        if (*rightTop >= 10)
        {
            cout << "\nDe-Stack is Empty";
        }
        else
        {
            cout << "\nTop Value of De-Stack : "
                 << arr[*rightTop];
        }
    }
    else
    {
        cout << "\nInvalid Peep Choice";
    }
}

void modify(int arr[10], int *leftTop, int *rightTop)
{
    int choice, position, newValue;

    cout << "\n1. Modify Pre-Stack";
    cout << "\n2. Modify De-Stack";
    cout << "\nEnter Modify Choice : ";
    cin >> choice;

    cout << "\nEnter Position : ";
    cin >> position;

    cout << "\nEnter New Value : ";
    cin >> newValue;

    if (choice == 1)
    {
        if (*leftTop == -1)
        {
            cout << "\nPre-Stack is Empty";
            return;
        }

        if (position < 0 || position > *leftTop)
        {
            cout << "\nInvalid Position";
            return;
        }

        arr[position] = newValue;
        cout << "\nPre-Stack Modified Successfully";
    }
    else if (choice == 2)
    {
        if (*rightTop == 10)
        {
            cout << "\nDe-Stack is Empty";
            return;
        }

        if (position < *rightTop || position >= 10)
        {
            cout << "\nInvalid Position";
            return;
        }

        arr[position] = newValue;
        cout << "\nDe-Stack Modified Successfully";
    }
    else
    {
        cout << "\nInvalid Modify Choice";
    }
}

void display(int arr[10], int leftTop, int rightTop)
{
    int choice, k;

    cout << "\n1. Display Pre-Stack";
    cout << "\n2. Display De-Stack";
    cout << "\nEnter Display Choice : ";
    cin >> choice;

    if (choice == 1)
    {
        if (leftTop == -1)
        {
            cout << "\nPre-Stack is Empty";
        }
        else
        {
            for (k = leftTop; k >= 0; k--)
            {
                cout << "\nPre-Stack : " << arr[k];
            }
        }
    }
    else if (choice == 2)
    {
        if (rightTop == 10)
        {
            cout << "\nDe-Stack is Empty";
        }
        else
        {
            for (k = rightTop; k < 10; k++)
            {
                cout << "\nDe-Stack : " << arr[k];
            }
        }
    }
    else
    {
        cout << "\nInvalid Display Choice";
    }
}

void main()
{
    int arr[10];
    int leftTop = -1, rightTop = 10;
    int choice, value;

    while (1)
    {
        cout << "\n\n===== TWO STACK MENU =====";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peep";
        cout << "\n4. Modify";
        cout << "\n5. Display";
        cout << "\n6. Exit";

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Value : ";
            cin >> value;
            push(arr, &leftTop, &rightTop, value);
            break;

        case 2:
            pop(arr, &leftTop, &rightTop);
            break;

        case 3:
            peep(arr, &leftTop, &rightTop);
            break;

        case 4:
            modify(arr, &leftTop, &rightTop);
            break;

        case 5:
            display(arr, leftTop, rightTop);
            break;

        case 6:
            exit(0);

        default:
            cout << "\nInvalid Main Menu Choice";
        }
    }
}