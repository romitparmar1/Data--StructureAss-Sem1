#include<iostream.h>
#include<conio.h>


void inputArray(int arr[]);
void quickSort(int arr[], int start, int end);
int getPivot(int arr[], int start, int end);
void displayArray(int arr[]);

void main()
{
    int arr[10];

    inputArray(arr);
    quickSort(arr, 0, 9);
    displayArray(arr);

    getch();
}

void inputArray(int arr[])
{
    int i;

    for(i = 0; i < 10; i++)
    {
        cout << "\nEnter value of Array[" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

void quickSort(int arr[], int start, int end)
{
    int position;

    if(start < end)
    {
        position = getPivot(arr, start, end);

        quickSort(arr, start, position - 1);
        quickSort(arr, position + 1, end);
    }
}

int getPivot(int arr[], int start, int end)
{
    int pivot;
    int left, right;
    int temp;

    pivot = arr[start];
    left = start + 1;
    right = end;

    while(left <= right)
    {
        while(left <= end && arr[left] < pivot)
        {
            left++;
        }

        while(right >= start && arr[right] > pivot)
        {
            right--;
        }

        if(left < right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }

    temp = arr[start];
    arr[start] = arr[right];
    arr[right] = temp;

    return right;
}

void displayArray(int arr[])
{
    int i;

    cout << "\n\nSorted Array:";

    for(i = 0; i < 10; i++)
    {
        cout << "\nArray[" << i + 1 << "] : " << arr[i];
    }
}