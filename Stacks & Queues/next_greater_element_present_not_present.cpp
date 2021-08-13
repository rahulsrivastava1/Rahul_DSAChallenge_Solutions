// next greater element present/not present in the stack

#include<bits/stdc++.h>
using namespace std;
void printNextGreater(int arr[],int n)
{
	stack<int> st;
	int res[n];
	for(int i=n-1;i>=0;i--)
	{
		if(!st.empty())
		{
			while(!st.empty() && st.top()<=arr[i])
				st.pop();
		}
		res[i]=st.empty()?-1:st.top();
		st.push(arr[i]);
	}
	for(int i=0;i<n;i++)
		cout<<"Next element of "<<arr[i]<<" is:"<<res[i]<<"\n";
}
int main()
{
	int arr[]={4,5,2,25,3};
	int len=sizeof(arr)/sizeof(arr[0]);
	printNextGreater(arr,len);
	return 0;
}
