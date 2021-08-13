// maximum sum of k consecutive elements

#include<bits/stdc++.h>
using namespace std;
int maxSum(int arr[],int n,int k)
{
	if(n<k)
	{
		cout<<"Invalid!";
		return -1;
	}
	int sum=0;
	for(int i=0;i<k;i++)
		sum +=arr[i];
	int curr_sum=sum;
	for(int i=k;i<n;i++)
	{
		curr_sum +=arr[i]-arr[i-k];
		sum=max(sum,curr_sum);
	}
	return sum;
}
int main()
{
	int size,k;
	cout<<"Enter size of an array:";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element "<<i+1<<" :";
		cin>>arr[i];
	}
	cout<<"Enter the value of k:";
	cin>>k;
	int ans=maxSum(arr,size,k);
	cout<<"Maximum sum:"<<ans;
	return 0;
}
