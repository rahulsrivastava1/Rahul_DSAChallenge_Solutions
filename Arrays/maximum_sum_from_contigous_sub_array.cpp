// maximum sum from contiguous sub-array

#include<bits/stdc++.h>
using namespace std;
int maxSum(int arr[],int n)
{
	int max1=INT_MIN;
	int max2=0;
	for(int i=0;i<n;i++)
	{
		max2=max2+arr[i];
		if(max1<max2)
			max1=max2;
		if(max2<0)
			max2=0;
	}
	return max1;
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
	int ans=maxSum(arr,size);
	cout<<"Maximum sum:"<<ans;
	return 0;
}
