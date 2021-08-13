// reverse a user input number

#include<bits/stdc++.h>
using namespace std;
int reverseNum(int num)
{
	int rev=0;
	while(num>0)
	{
		rev=rev*10+num%10;
		num=num/10;
	}
	return rev;
}
int main()
{
	int num;
	cout<<"Enter a number :";
	cin>>num;
	int ans=reverseNum(num);
	cout<<"Reversed number is :"<<ans;
	return 0;
}
