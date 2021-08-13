// remove duplicate elemnts from sorted and unsorted array

#include<bits/stdc++.h>
using namespace std;
int removeDuplicatesfromSorted(int arr[],int n)
{
	if(n==0 || n==1)
		return n;
	int temp[n],j=0;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]!=arr[i+1])
		{
			temp[j++]=arr[i];
			temp[j++]=arr[n-1];
		}
	}
	for(int i=0;i<j;i++)
		arr[i]=temp[i];
	return j;
}
void removeDuplicatesfromunSorted(int arr[],int n)
{
	unordered_map<int,bool> mp;
	for(int i=0;i<n;i++)
	{
		if(mp.find(arr[i])==mp.end())
			cout<<arr[i]<<" ";
		mp[arr[i]]=true;
	}
}
int main()
{
	int size;
	cout<<"Enter the first array size :";
	cin>>size;
	int arr[size];
	cout<<"Enter elements in unsorted manner"<<"\n";
	for(int i=0;i<size;i++)
	{
		cout<<"Enter array element"<<i+1<<" :";
		cin>>arr[i];
	}
	removeDuplicatesfromunSorted(arr,size);
	int size2;
	cout<<"\nEnter the second array size :";
	cin>>size2;
	int ar[size2];
	cout<<"Enter elements in sorted form"<<"\n";
	for(int i=0;i<size;i++)
	{
		cout<<"Enter array element"<<i+1<<" :";
		cin>>ar[i];
	}
	size2=removeDuplicatesfromSorted(ar,size);
	for(int i=0;i<size2;i++)
		cout<<arr[i]<<" ";
	return 0;
}
