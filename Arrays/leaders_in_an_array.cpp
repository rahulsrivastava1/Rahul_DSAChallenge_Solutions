// Leaders in an array

#include<bits/stdc++.h>
using namespace std;
void printLeaders(int arr[],int n)
{
	int max=arr[n-1];
	cout<<max<<" ";
	for(int i=n-2;i>=0;i--)
	{
		if(max<arr[i])
		{
			max=arr[i];
			cout<<max<<" ";
		}
	}
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
	printLeaders(arr,size);
	return 0;
}
