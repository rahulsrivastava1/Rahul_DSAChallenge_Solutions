// Second largest element in an array

#include<bits/stdc++.h>
using namespace std;
int secondLargest(int arr[],int n)
{
	int largest=0,second=0;
	if(arr[0]<arr[1])
	{
		largest=arr[1];
		second=arr[0];	
	}
	else
	{
		largest=arr[0];
		second=arr[1];
	}
	for(int i=2;i<n;i++)
	{
		if(arr[i]>largest)
		{
			second=largest;
			largest=arr[i];
		}
		else if(arr[i]>second && arr[i]!=largest)
			second=arr[i];
	}
	return second;
}
int main()
{
	int size;
	cout<<"Enter the size of an array:";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter array element"<<i+1<<" :";
		cin>>arr[i];
	}
	int ans=secondLargest(arr,size);
	cout<<"Second largest element from array is :"<<ans;
	return 0;
}
