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

void sortArray(int arr[])
{
    int i, j, key;

    for(i = 1; i < 10; i++)
    {
	key = arr[i];
	j = i - 1;

	while(j >= 0 && arr[j] > key)
	{
	    arr[j + 1] = arr[j];
	    j--;
	}

	arr[j + 1] = key;
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
    sortArray(arr);
    showArray(arr);

    getch();
}