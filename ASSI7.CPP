#include<iostream.h>
#include<stdlib.h>


void addProcess(int [], int *, int *, int);
int removeProcess(int [], int *, int *);

int main()
{
    int queue[10];
    int front = -1, rear = -1;

    int jobs[5] = {5, 7, 4, 8, 3};
    int index = 0;
    int remaining;
    int total = 5;

    for(index = 0; index < 5; index++)
    {
        addProcess(queue, &front, &rear, jobs[index]);
    }

    index = 0;

    while(total > 0)
    {
        remaining = removeProcess(queue, &front, &rear);

        if(remaining != -1)
        {
            cout << "\nProcess " << index + 1 << " : ";

            if(remaining > 2)
            {
                remaining = remaining - 2;

                cout << "\n2 Unit Executed";
            }
            else
            {
                cout << "\n" << remaining << " Unit Executed";

                remaining = 0;
                total--;
            }

            if(remaining > 0)
            {
                addProcess(queue, &front, &rear, remaining);
            }
        }

        index++;

        if(index >= 5)
        {
            index = 0;
        }
    }

    cout << "\nAll Process Executed";

    return 0;
}

void addProcess(int queue[], int *front, int *rear, int time)
{
    if((*rear + 1) % 10 == *front)
    {
        cout << "\nQueue Is Full";
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

    queue[*rear] = time;
}

int removeProcess(int queue[], int *front, int *rear)
{
    int time;

    if(*front == -1)
    {
        cout << "\nQueue Is Empty";
        return -1;
    }

    time = queue[*front];

    if(*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = (*front + 1) % 10;
    }

    return time;
}