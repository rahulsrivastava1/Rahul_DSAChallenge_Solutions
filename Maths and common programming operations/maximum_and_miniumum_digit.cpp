// maximum and minimum digit

#include<bits/stdc++.h>
using namespace std;
int maximum(int num)
{
	int max=INT_MIN;
	while(num)
	{
		int rem=num%10;
		num=num/10;
		if(rem>max)
			max=rem;
	}
	return max;
}
int minimum(int num)
{
	int min=INT_MAX;
	while(num)
	{
		int rem=num%10;
		num=num/10;
		if(rem<min)
			min=rem;
	}
	return min;
}
int main()
{
	int num;
	cout<<"Enter a number :";
	cin>>num;
	int max=maximum(num);
	int min=minimum(num);
	cout<<"Maximum digit is :"<<max<<"\n";
	cout<<"Minimum digit is :"<<min<<"\n";
	return 0;
}
