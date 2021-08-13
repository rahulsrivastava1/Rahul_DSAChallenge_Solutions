// frequency of all distinct elements

#include<bits/stdc++.h>
using namespace std;
void printFrequenciesSorted(int arr[],int n)
{
	map<int,int> mp;
	for(int i=0;i<n;i++)
		mp[arr[i]]++;
	for(auto it:mp)
	{
		cout<<it.first<<": "<<it.second<<"\n";
	}
}
int main()
{
	int size;
	cout<<"Enter size of an array:";
	cin>>size;
	int arr[size];
	cout<<"Enter elements in sorted form.\n";
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element "<<i+1<<" :";
		cin>>arr[i];
	}
	printFrequenciesSorted(arr,size);
	int size2;
	cout<<"Enter size of an array:";
	cin>>size2;
	int ar[size2];
	cout<<"Enter elements in unsorted form.\n";
	for(int i=0;i<size2;i++)
	{
		cout<<"Enter element "<<i+1<<" :";
		cin>>ar[i];
	}
	printFrequenciesSorted(ar,size);
	return 0;
}
