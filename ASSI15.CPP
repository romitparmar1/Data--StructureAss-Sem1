#include<iostream.h>
#include<conio.h>

void inputArray(int arr[], int size);
void radixSort(int arr[], int size);
void displayArray(int arr[], int size);

void main()
{
    int arr[10], size;

    cout << "\nEnter the N : ";
    cin >> size;

    inputArray(arr, size);
    radixSort(arr, size);
    displayArray(arr, size);

    getch();
}

void inputArray(int arr[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
	cout << "\nArray[" << i + 1 << "] : ";
	cin >> arr[i];
    }
}

void radixSort(int arr[], int size)
{
    int largest;
    int i, j, digit, position, index;

    largest = arr[0];

    // Find largest number
    for(i = 1; i < size; i++)
    {
	if(arr[i] > largest)
	{
	    largest = arr[i];
	}
    }

    // Sort according to each digit
    for(position = 1; largest / position > 0; position = position * 10)
    {
	int bucket[10][20] = {0};
	int count[10] = {0};

	for(i = 0; i < size; i++)
	{
	    digit = (arr[i] / position) % 10;

	    bucket[digit][count[digit]] = arr[i];
	    count[digit]++;
	}

	index = 0;

	for(i = 0; i < 10; i++)
	{
	    for(j = 0; j < count[i]; j++)
	    {
		arr[index] = bucket[i][j];
		index++;
	    }
	}
    }
}

void displayArray(int arr[], int size)
{
    int i;

    cout << "\n\nSorted Array:";

    for(i = 0; i < size; i++)
    {
	cout << "\nArray[" << i + 1 << "] : " << arr[i];
    }
}