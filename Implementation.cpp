//Hanna Mostafa 
//900222857
//Hidden Lab 7
//Quicksort

#include <iostream>
using namespace std;

int MedianofThree(int arr[], int left, int right) //function that recieves an array and two numbers that represent the left and right endpoints
{
	int mid = (left + right) / 2; 
	if (arr[left] > arr[right])
		swap(arr[left], arr[right]);
	if (arr[left] > arr[mid])
		swap(arr[left], arr[mid]);
	if (arr[mid] > arr[right])
		swap(arr[mid], arr[right]);
	return mid; //returns the median of the three numbers
};
int Partition(int arr[], int left, int right) //function that recieves an array and two numbers that represent the left and right endpoints
{
	int pivotnum = MedianofThree(arr, left, right); //selects a pivot using the MedianofThree function
	int pivot = arr[pivotnum]; //partitions an array around the pivot
	int i = left - 1;
	int j = right + 1;
	do
	{
		i++;
	} while (arr[i] < pivot);
	do
	{
		j--;
	} while (arr[j] > pivot);
	if (i >= j)
		return j;
	swap(arr[i], arr[j]);
	return j;
};
void quicksort(int arr[], int left, int right) //function that recieves an array and two numbers that represent the left and right endpoints
{
	if (left >= right)
		return;
	int pivotnum = Partition(arr, left, right);
	quicksort(arr, left, pivotnum); //recursively calls itself on the left partition of the array
	quicksort(arr, pivotnum + 1, right); //recursively calls itself on the right partition of the array
};
int main()
{
	int arr[] = { 8,3,1,6,4,0,5,2 }; //unsorted array 
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Before sorting: "; //outputs the array before any changes
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	quicksort(arr, 0, size - 1); //calls the function quicksort with a left value (0) and a right value (size-1)

	cout << "After sorting: "; //outputs the array after calling the quicksort function and sorting it out
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	return 0;
}