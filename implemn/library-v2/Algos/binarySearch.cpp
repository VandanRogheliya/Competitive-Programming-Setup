// C++ program to variants of Binary Search
#include <bits/stdc++.h>

using namespace std;

// Global array of type long long TODO:
int n = 8; // array size
long long a[] = { 2, 3, 3, 5, 5, 5, 6, 6 }; // Sorted array

/* Find if key is in array
* Returns: True if key belongs to array,
*		 False if key doesn't belong to array */
bool contains(int low, int high, long long key) {
	bool ans = false;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		long long midVal = a[mid];

		if (midVal < key) {
			low = mid + 1;
		}
		else if (midVal > key) {
			high = mid - 1;
		}
		else if (midVal == key) {
			ans = true;
			break;
		}
	}

	return ans;
}

/* Find first occurrence index of key in array
* Returns: an index in range [0, n-1] if key belongs 
*		 to array, -1 if key doesn't belong to array
*/
int first(int low, int high, long long key) {
	int ans = -1;

	while (low <= high) {
		int mid = low + (high - low + 1) / 2;
		long long midVal = a[mid];

		if (midVal < key) {
			low = mid + 1;
		}
		else if (midVal > key) {
			high = mid - 1;
		}
		else if (midVal == key) {
			ans = mid;
			high = mid - 1;
		}
	}

	return ans;
}

/* Find last occurrence index of key in array
* Returns: an index in range [0, n-1] if key 
			belongs to array,
*		 -1 if key doesn't belong to array
*/
int last(int low, int high, long long key) {
	int ans = -1;

	while (low <= high) {
		int mid = low + (high - low + 1) / 2;
		long long midVal = a[mid];

		if (midVal < key) {
			low = mid + 1;
		}
		else if (midVal > key) {
			high = mid - 1;
		}
		else if (midVal == key) {
			ans = mid;
			low = mid + 1;
		}
	}

	return ans;
}

/* Find index of first occurrence of least element 
greater than key in array
* Returns: an index in range [0, n-1] if key is not
			the greatest element in array,
*		 -1 if key is the greatest element in array */
int leastgreater(int low, int high, long long key) {
	int ans = -1;

	while (low <= high) {
		int mid = low + (high - low + 1) / 2;
		long long midVal = a[mid];

		if (midVal < key) {
			low = mid + 1;
		}
		else if (midVal > key) {
			ans = mid;
			high = mid - 1;
		}
		else if (midVal == key) {
			low = mid + 1;
		}
	}

	return ans;
}

/* Find index of last occurrence of greatest element
less than key in array
* Returns: an index in range [0, n-1] if key is not 
			the least element in array,
*		 -1 if key is the least element in array */
int greatestlesser(int low, int high, long long key) {
	int ans = -1;

	while (low <= high) {
		int mid = low + (high - low + 1) / 2;
		long long midVal = a[mid];

		if (midVal < key) {
			ans = mid;
			low = mid + 1;
		}
		else if (midVal > key) {
			high = mid - 1;
		}
		else if (midVal == key) {
			high = mid - 1;
		}
	}

	return ans;
}

// TESTING
int main() {
	printf("Contains\n");
	for (int i = 0; i < 10; i++)
		printf("%d %d\n", i, contains(0, n - 1, i));

	printf("First occurrence of key\n");
	for (int i = 0; i < 10; i++)
		printf("%d %d\n", i, first(0, n - 1, i));

	printf("Last occurrence of key\n");
	for (int i = 0; i < 10; i++)
		printf("%d %d\n", i, last(0, n - 1, i));

	printf("Least integer greater than key\n");
	for (int i = 0; i < 10; i++)
		printf("%d %d\n", i, leastgreater(0, n - 1, i));

	printf("Greatest integer lesser than key\n");
	for (int i = 0; i < 10; i++)
		printf("%d %d\n", i, greatestlesser(0, n - 1, i));

	return 0;
}
