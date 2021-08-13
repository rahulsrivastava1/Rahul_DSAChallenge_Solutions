// prefix sum array

#include<bits/stdc++.h>
using namespace std;
void prefixSum(int arr[],int n)
{
	int temp[n],sum=arr[0];
	temp[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		sum+=arr[i];
		temp[i]=sum;
	}
	for(int i=0;i<n;i++)
		cout<<temp[i]<<" ";
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
	prefixSum(arr,size);
	return 0;
}
