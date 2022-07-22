#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define C 4
#define N 4

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int bsFirst(int arr[], int n, int key)
{
	if (arr[0] == key)
		return 0;
	int first = 1, last = n - 1, mid;
	while (first <= last)
	{
		mid = (last - first) / 2 + first;
		if (arr[mid] == key && arr[mid - 1] != key)
			return mid;
		else if (arr[mid] == key && arr[mid - 1] == key)
			last = mid - 1;
		else if (arr[mid] > key)
		{
			last = mid - 1;
		}
		else
			first = mid + 1;
	}
	return -1;
}
int bsLast(int arr[], int n, int key)
{
	if (arr[n - 1] == key)
		return n - 1;
	int first = 0, last = n - 2, mid;
	while (first <= last)
	{
		mid = (last - first) / 2 + first;
		if (arr[mid] == key && arr[mid + 1] != key)
			return mid;
		else if (arr[mid] == key && arr[mid + 1] == key)
			first = mid + 1;
		else if (arr[mid] > key)
		{
			last = mid - 1;
		}
		else
			first = mid + 1;
	}
	return -1;
}
int howMany(int arr[], int n, int key)
{
	int start = bsFirst(arr, n, key);
	int end = bsLast(arr, n, key);
	if (start< 0 || end < 0)
		return 0;
	return end - start + 1;
}

int* merge_arrays(int arr[], int brr[], int n, int m)
{
	int size = n + m, first1 = 0, first2 = 0, k = 0;
	int* t = (int*)malloc(size * sizeof(int));
	assert(t);
	while (first1 < n && first2 < m)
	{
		if (arr[first1] < brr[first2])
		{
			t[k++] = arr[first1++];
		}
		else
		{
			t[k++] = brr[first2++];
		}
	}
	while (first1 < n)
	{
		t[k++] = arr[first1++];
	}

	while (first2 < m)
	{

		t[k++] = brr[first2++];
	}
	return t;
}
int partiton(int arr[], int first, int last)
{
	int start = first;
	int pivot = arr[first];
	while (first < last)
	{
		while (arr[last] > pivot && first < last)
			last--;

		while (arr[first] <= pivot && first < last)
			first++;
		if (first < last)
			swap(arr + first, arr + last);
	}
	swap(arr + start, arr + first);
	return first;
}
void quick_sort(int arr[], int first, int last)
{
	int pos;
	if (first < last)
	{
		pos = partiton(arr, first, last);
		quick_sort(arr, first, pos - 1);
		quick_sort(arr, pos + 1, last);
	}
}
void merge(int arr[], int first, int mid, int last)
{
	int start1 = first, start2 = mid + 1, k = 0;
	int* t = (int*)malloc((last - first + 1) * sizeof(int));
	assert(t);
	while (start1 <= mid && start2 <= last)
	{
		if (arr[start1] < arr[start2])
			t[k++] = arr[start1++];
		else
			t[k++] = arr[start2++];
	}
	while (start1 <= mid)
		t[k++] = arr[start1++];
	while (start2 <= last)
		t[k++] = arr[start2++];
	for (start1 = first, k = 0; start1 <= last; start1++)
		arr[start1] = t[k++];
	free(t);
}
void merge_sort(int arr[], int first, int last)
{
	int mid;
	if (first < last)
	{
		mid = (last - first) / 2 + first;
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}
int binarySearch(int arr[], int n, int key)
{
	int first = 0, last = n - 1, mid;
	while (first <= last)
	{
		mid = (last - first) / 2 + first;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			first = mid + 1;
		else last = mid - 1;
	}
	return -1;
}
void swapChar(char* x, char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}


char* intersection(char str1[], char str2[])
{
	int w;
	int t1[26] = { 0 };
	int t2[26] = { 0 };
	int n = strlen(str1);
	int m = strlen(str2);
	w = n < m ? n : m;
	char* s = (char*)malloc((w + 1) * sizeof(char));
	assert(s);
	while (*str1)
	{
		t1[*str1 - 'a']++;
		str1++;
	}
	while (*str2)
	{
		t2[*str2 - 'a']++;
		str2++;
	}
	int i = 0, k = 0;
	for (i = 0; i < 26; i++)
	{
		while (t1[i] > 0 && t2[i] > 0)
		{
			s[k++] = i + 'a';
			t1[i]--;
			t2[i]--;
		}
	}
	s[k] = '\0';
	char* s1;
	s1 = (char*)realloc(s, (k + 1) * sizeof(char));
	return s1;
}


void splitString(char* str)
{
	int i = 0;
	int last = -1;
	while (str[i])
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			swapChar(str + i, str + (++last));
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			swapChar(str + i, str + (++last));
		i++;
	}
	str[++last] = '\0';
}


void splitInt(int arr[], int n)
{
	int i = 0, last = -1;
	while (i < n)
	{
		if (arr[i] % 3 == 0)
			swap(arr + i, arr + (++last));
		i++;
	}
	i = last;
	while (i < n)
	{
		if (arr[i] % 3 == 1)
			swap(arr + i, arr + (++last));
		i++;
	}

}
int BinarySearchInMatrix(int mat[][C], int ROWS, int COLS, int* row, int* col, int key)
{
	int first = 0, last = ROWS * COLS - 1, mid;
	while (first <= last)
	{
		mid = (last - first) / 2 + first;
		if (mat[mid / COLS][mid % (COLS)] == key)
		{
			*col = mid % (COLS);
			*row = mid / COLS;
			return 1;
		}
		else if (mat[mid / COLS][mid % (COLS)] > key)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return -1;
}
int ifNeihbors(int mat[][N])
{
	int i, j;
	for (i = 1; i < N; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			if (mat[i][j] == mat[i - 1][j] || mat[i][j] == mat[i - 1][j + 1] || mat[i][j] == mat[i][j + 1])
				return 0;
			if (mat[i - 1][j] == mat[i - 1][j + 1] || mat[i - 1][j] == mat[i][j + 1])
				return 0;
			if (mat[i][j + 1] == mat[i - 1][j + 1])
				return 0;
		}
	}
	return 1;
}

void splitEvens(int arr[], int n)

{
	int i = 0, last = -1;
	while (i < n)
	{
		if (arr[i] > 0 && (!(arr[i] % 2)))
		{
			swap(arr + i, arr + (++last));
			i++;
		}
		else i++;
	}
	i = last + 1;
	while (i < n)
	{
		if (arr[i] > 0 && arr[i] % 2)
		{
			swap(arr + i, arr + (++last));
			i++;
		}
		else i++;
	}
	i = last + 1;
	while (i < n)
	{
		if (arr[i] < 0 && (!(arr[i] % 2)))
		{
			swap(arr + i, arr + (++last));
			i++;
		}
		else i++;
	}
}

void printArray(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}



int gcd(int x, int y)
{
	if (!y)
		return x;
	return gcd(y, x % y);
}







int main()
{
	int arr[] = { 1,5,62,12,2,1,23,5,3,7,5,1,2,10,2,1,2,1 };
	int n = sizeof(arr) / sizeof(int);
	int key = 2;
	printf("UnSorted Array: "); printArray(arr, n);
	quick_sort(arr, 0, n - 1);
	printf("Sorted Array: "); printArray(arr, n);
	int how_many = howMany(arr, n,key);
	printf("Theres is %d of %d in Array", how_many,key);
	return 0;
}
