#include<iostream.h>
#include<conio.h>

void inputArray(int arr[])
{
    int i;

    for(i = 0; i < 10; i++)
    {
        cout << "\nEnter value of Array[" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

void mergeArray(int arr[], int low, int mid, int high)
{
    int temp[10];
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        mergeArray(arr, low, mid, high);
    }
}

void showArray(int arr[])
{
    int i;

    cout << "\n\nSorted Array:";

    for(i = 0; i < 10; i++)
    {
        cout << "\nArray[" << i + 1 << "] : " << arr[i];
    }
}

void main()
{
    int arr[10];

    inputArray(arr);
    mergeSort(arr, 0, 9);
    showArray(arr);

    getch();
}