// check if an array is sorted or not?

#include<bits/stdc++.h>
using namespace std;
int isArraySorted(int arr[],int n)
{
	int a=1,d=1,i=0;
	while((a==1||d==1)&&i<n-1)
	{
		if(arr[i]<arr[i+1])
			d=0;
		else if(arr[i]>arr[i+1])
			a=0;
		i++;
	}
	if(a==1)
		return 1;
	else if(d==1)
		return 2;
	else
		return 0;
}
int main()
{
	int size;
	cout<<"Enter size of an array:";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element "<<i+1<<" :";
		cin>>arr[i];
	}
	int ans=isArraySorted(arr,size);
	if(ans==1||ans==2)
		cout<<"Sorted.";
	else 
		cout<<"Not Sorted!";
	return 0;
}
