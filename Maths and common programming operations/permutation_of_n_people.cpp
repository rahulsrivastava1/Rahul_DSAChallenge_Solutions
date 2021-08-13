// permutation of n people occupy x seats

#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
	int fact=1;
	for(int i=1;i<=n;i++)
		fact*=i;
	return fact;
}
int main()
{
	int n,x;
	cout<<"Enter the number of people:";
	cin>>n;
	cout<<"Enter no. of seats:";
	cin>>x;
	if(n<x)
	{
		int temp=n;
		n=x;
		x=temp;
	}
	int num=factorial(n);
	int den=factorial(n-x);
	int p=num/den;
	cout<<"The permutation of n people who can occupy x seats in an empty room :"<<p;
	return 0;
}
