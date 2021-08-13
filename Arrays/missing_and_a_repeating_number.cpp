// missing and a repeating number

#include<bits/stdc++.h>
using namespace std;
void missingAndRepeating(int arr[],int n)
{
	cout<<"The repeating element is:";
	for(int i=0;i<n;i++)
	{
		if(arr[abs(arr[i])-1]>0)
			arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
		else
			cout<<abs(arr[i])<<"\n";
	}
	cout<<"and the missing element is:";
	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
			cout<<i+1;
	}
}
using namespace std;
int main()
{
	int size;
	cout<<"Enter the size of an unordered array:";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element"<<i+1<<" :";
		cin>>arr[i];
	}
	missingAndRepeating(arr,size);
	return 0;
}
