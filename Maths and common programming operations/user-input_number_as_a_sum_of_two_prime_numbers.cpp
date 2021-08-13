//  express a user-input number as a sum of two prime numbers

#include<bits/stdc++.h>
using namespace std;
int sumofTwoPrimes(int num)
{
	int i,isPrime=1;
	for(i=2;i<=num/2;i++)
	{
		if(num%i==0)
		{
			isPrime=0;
			break;
		}
	}
	return isPrime;
}
int main()
{
	int num;
	cout<<"Enter a number:";
	cin>>num;
	int flag=0;
	for(int i=2;i<=num/2;i++)
	{
		if(sumofTwoPrimes(i)==1)
		{
			if(sumofTwoPrimes(num-i)==1)
			{
				printf("\n%d can be expressed as the sum of %d and %d.",num,i,num-i);
				flag=1;
			}
		}
	}
	if(flag==0)
		cout<<"Can't be expressed!";
	return 0;
}
