// maximum and minimum difference,repeating and non-repeating elements

#include<bits/stdc++.h>
using namespace std;
void maxDiff(int arr[],int n)
{
	int diff=arr[1]-arr[0];
	int min_elem=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]-min_elem>diff)
			diff=arr[i]-min_elem;
		if(arr[i]<min_elem)
			min_elem=arr[i];
	}
	cout<<"Maximum difference:"<<diff<<"\n";
}
void minDiff(int arr[],int n)
{
	sort(arr,arr+n);
	int diff=INT_MAX;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i+1]-arr[i]<diff)
			diff=arr[i+1]-arr[i];
	}
	cout<<"Minimum difference:"<<diff<<"\n";
}
void repeating(int arr[],int n)
{
	int min=-1;
	set<int> st;
	for(int i=n-1;i>=0;i--)
	{
		if (st.find(arr[i])!=st.end())
            min=i;
        else
 			st.insert(arr[i]);
	}
	if(min!=-1)
		cout<<"First repeating elements :"<<arr[min]<<"\n";
}
void nonRepeating(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j==n)
			{
				cout<<"First Non-repeating element:"<<arr[i];
				break;
			}
		}
		break;
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
	maxDiff(arr,size);
	minDiff(arr,size);
	int ar[]={10,5,3,4,3,5,6};
	int length=sizeof(arr)/sizeof(arr[0]);
	repeating(ar,length);
	nonRepeating(ar,length);
	return 0;
}
