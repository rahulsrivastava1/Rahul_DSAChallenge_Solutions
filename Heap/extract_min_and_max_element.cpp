// min-heapify and max-heapify in above qstn
// extract min and max element

#include <bits/stdc++.h>
using namespace std;
int findMinimumElement(int heap[], int n)
{
	int minimumElement = heap[0];

	for (int i = 1; i < n; ++i)
		minimumElement = min(minimumElement, heap[i]);

	return minimumElement;
}
int findMaximumElement(int heap[], int n)
{
    int maximumElement = heap[n / 2];
 
    for (int i = 1 + n / 2; i < n; ++i)
        maximumElement = max(maximumElement, heap[i]);
 
    return maximumElement;
}
// Driver code
int main()
{
	// Number of nodes
	int n = 10;
	int heap[] = { 20, 18, 10, 12, 9, 9, 3, 5, 6, 8 };
	cout << findMinimumElement(heap, n);
	cout << findMaximumElement(heap, n);
	return 0;
}

