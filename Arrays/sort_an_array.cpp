// sort an array

#include<bits/stdc++.h>
using namespace std;
void printSort(int arr[],int n)
{
	vector<int> zeros;
	vector<int> ones;
	vector<int> twos;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
			zeros.push_back(arr[i]);
		if(arr[i]==1)
			ones.push_back(arr[i]);
		if(arr[i]==2)
			twos.push_back(arr[i]);
	}
	cout<<"In sorted form->";
	for(auto it:zeros)
		cout<<it<<" ";
	for(auto it:ones)
		cout<<it<<" ";
	for(auto it:twos)
		cout<<it<<" ";
}
int main()
{
	int size;
	cout<<"Enter size of an array:";
	cin>>size;
	int arr[size];
	cout<<"Enter elements only 0,1 and 2.\n";
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element "<<i+1<<" :";
		cin>>arr[i];
	}
	printSort(arr,size);
	return 0;
}
