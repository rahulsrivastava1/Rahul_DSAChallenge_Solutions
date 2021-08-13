// left rotate an array

#include<bits/stdc++.h>
using namespace std;
void printLeftRotateByOne(int arr[],int n)
{
	int temp[n];
	for(int i=0;i<n;i++)
		temp[i]=arr[i];
	reverse(temp+1,temp+n);
	reverse(temp,temp+n);
	cout<<"Printing array after left rotate by one space.";
	for(int i=0;i<n;i++)
		cout<<temp[i]<<" ";
}
void printLeftRotateByK(int arr[],int n,int k)
{
	reverse(arr,arr+k);
	reverse(arr+k,arr+n);
	reverse(arr,arr+n);
	cout<<"Printing array after left rotate by "<<k<<"spaces. "<<" ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
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
	printLeftRotateByOne(arr,size);
	int k;
	cout<<"\nEnter size which you want to rotate:";
	cin>>k;
	printLeftRotateByK(arr,size,k);
	return 0;
}
