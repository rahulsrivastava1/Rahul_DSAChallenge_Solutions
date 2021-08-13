// reverse an array

#include<bits/stdc++.h>
using namespace std;
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
	cout<<"Original array is :"<<"\n";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	cout<<"Reversed array is :"<<"\n";
	for(int i=size-1;i>=0;i--)
		cout<<arr[i]<<" ";
	return 0;
}
