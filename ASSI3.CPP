#include<iostream.h>
#include<conio.h>
#include<string.h>

char getNext(char exp[])
{
    static int pos = -1;
    pos++;
    return exp[pos];
}

void push(char st[50], int *top, char data)
{
    if(*top >= 49)
    {
        cout << "\nStack Overflow";
        return;
    }

    *top = *top + 1;
    st[*top] = data;
}

char pop(char st[50], int *top)
{
    char data;

    data = st[*top];
    *top = *top - 1;

    return data;
}

int rankValue(char ch)
{
    switch(ch)
    {
        case '#':
            return 0;

        case '+':
        case '-':
        case '*':
        case '/':
            return -1;

        case '(':
        case ')':
            return 0;

        default:
            return 1;
    }
}

int precedence(char ch)
{
    switch(ch)
    {
        case '#':
        case '(':
            return 0;

        case ')':
            return -1;

        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        default:
            return 3;
    }
}

void main()
{
    char infix[50];
    char suffix[50] = "";
    char st[50];

    char current;
    char item;
    char str[2];

    int top = -1;
    int rank = 0;

    cout << "\nEnter Infix Expression : ";
    cin >> infix;

    strcat(infix, "#");

    top++;
    st[top] = '#';

    current = getNext(infix);

    while(current != '#')
    {
        if(current == '(')
        {
            push(st, &top, current);
        }

        else if(current == ')')
        {
            while(st[top] != '(')
            {
                item = pop(st, &top);

                str[0] = item;
                str[1] = '\0';

                strcat(suffix, str);

                rank = rank + rankValue(item);
            }

            pop(st, &top);
        }

        else if(precedence(current) == 3)
        {
            str[0] = current;
            str[1] = '\0';

            strcat(suffix, str);

            rank = rank + rankValue(current);
        }

        else
        {
            while(precedence(current) <= precedence(st[top]))
            {
                item = pop(st, &top);

                str[0] = item;
                str[1] = '\0';

                strcat(suffix, str);

                rank = rank + rankValue(item);
            }

            push(st, &top, current);
        }

        current = getNext(infix);
    }

    while(st[top] != '#')
    {
        if(st[top] == '(')
        {
            cout << "\nInvalid Infix Expression";
            return;
        }

        item = pop(st, &top);

        str[0] = item;
        str[1] = '\0';

        strcat(suffix, str);

        rank = rank + rankValue(item);
    }

    if(rank == 1)
    {
        cout << "\nSuffix Expression : " << suffix;
    }
    else
    {
        cout << "\nInvalid Infix Expression";
    }

    getch();
}