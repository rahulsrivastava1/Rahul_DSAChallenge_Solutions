// largest prime factor of a number

#include<bits/stdc++.h>
using namespace std;
int primefactor(int num)
{
	int maxPrime=-1;
	while(num%2==0)
	{
		maxPrime=2;
		num>>=1;
	}
	while(num%3==0)
	{
		maxPrime=3;
		num=num/3;
	}
	for(int i=5;i<=sqrt(num);i+=6)
	{
		while(num%i==0)
		{
			maxPrime=i;
			num=num/(i+2);
		}
	}
	if(num>4)
		maxPrime=num;
	return maxPrime;
}
int main()
{
	int num;
	cout<<"Enter a number:";
	cin>>num;
	int ans=primefactor(num);
	cout<<"Largest prime factor of "<<num<<" is :"<<ans;
	return 0;
}
