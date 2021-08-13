// previous greater element present/not present in the stack

#include<bits/stdc++.h>
using namespace std;
void printPreviousGreater(int arr[],int n)
{
	stack<int> s;
	s.push(arr[0]);
	cout<<"-1, ";
	for(int i=1;i<n;i++)
	{
		while(s.empty()==false && s.top()<arr[i])
			s.pop();
		s.empty()?cout<<"-1, ":cout<<s.top()<<" , ";
		s.push(arr[i]);
	}
}
int main()
{
	int arr[]={40,30,20,10};
	int len=sizeof(arr)/sizeof(arr[0]);
	printPreviousGreater(arr,len);
	return 0;
}
