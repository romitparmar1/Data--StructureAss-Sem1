#include<iostream.h>
#include<conio.h>

void inputArray(int arr[], int n);
void insertHeap(int heap[], int &size, int value);
int deleteHeap(int heap[], int *size);
void heapSort(int arr[], int n);
void displayArray(int arr[], int n);

void main()
{
    int arr[11], n;

    cout << "\nEnter The N : ";
    cin >> n;

    inputArray(arr, n);
    heapSort(arr, n);
    displayArray(arr, n);

    getch();
}

void inputArray(int arr[], int n)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        cout << "\nArray[" << i << "] : ";
        cin >> arr[i];
    }
}

void insertHeap(int heap[], int &size, int value)
{
    int position, parent;

    size++;
    position = size;

    while(position > 1)
    {
        parent = position / 2;

        if(value >= heap[parent])
        {
            break;
        }

        heap[position] = heap[parent];
        position = parent;
    }

    heap[position] = value;
}

int deleteHeap(int heap[], int *size)
{
    int item, last;
    int position, left, right, child;

    item = heap[1];
    last = heap[*size];

    *size = *size - 1;

    position = 1;
    left = 2;
    right = 3;

    while(left <= *size)
    {
        if(right <= *size)
        {
            if(heap[right] < heap[left])
            {
                child = right;
            }
            else
            {
                child = left;
            }
        }
        else
        {
            child = left;
        }

        if(last <= heap[child])
        {
            break;
        }

        heap[position] = heap[child];

        position = child;
        left = position * 2;
        right = position * 2 + 1;
    }

    heap[position] = last;

    return item;
}

void heapSort(int arr[], int n)
{
    int heap[11];
    int size = 0;
    int i;

    for(i = 1; i <= n; i++)
    {
        insertHeap(heap, size, arr[i]);
    }

    for(i = 1; i <= n; i++)
    {
        arr[i] = deleteHeap(heap, &size);
    }
}

void displayArray(int arr[], int n)
{
    int i;

    cout << "\n\nSorted Array:";

    for(i = 1; i <= n; i++)
    {
        cout << "\nArray[" << i << "] : " << arr[i];
    }
}