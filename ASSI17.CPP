#include<iostream.h>
#include<conio.h>

void main()
{
    int a[10], n, ch;
    int i, low, high, mid, found;

    // Input array elements
    cout << "Enter 10 array elements:\n";

    for (i = 0; i < 10; i++)
    {
	cin >> a[i];
    }

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";

    cout << "\nEnter your choice: ";
    cin >> ch;

    cout << "Enter element to search: ";
    cin >> n;

    found = 0;

    switch (ch)
    {
	case 1:
	    // Linear Search
	    for (i = 0; i < 10; i++)
	    {
		if (a[i] == n)
		{
		    found = 1;
		    break;
		}
	    }

	    if (found == 1)
		cout << "Element found at position " << i + 1;
	    else
		cout << "Element not found";

	    break;

	case 2:
	    // Binary Search
	    low = 0;
	    high = 9;

	    while (low <= high)
	    {
		mid = (low + high) / 2;

		if (a[mid] == n)
		{
		    found = 1;
		    break;
		}
		else if (n < a[mid])
		{
		    high = mid - 1;
		}
		else
		{
		    low = mid + 1;
		}
	    }

	    if (found == 1)
		cout << "Element found at position " << mid + 1;
	    else
		cout << "Element not found";

	    break;

	default:
	    cout << "Invalid choice";
    }

    getch();
}