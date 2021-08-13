// sum of even and odd digits separately

#include<bits/stdc++.h>
using namespace std;
int sumofEven(int num)
{
	int sumEven=0;
	string num1=to_string(num);
	for(int i=0;i<num1.length();i++)
	{
		if((num1[i]-'0')%2==0)
			sumEven=sumEven+(num1[i]-'0');
	}
	return sumEven;
}
int sumofOdd(int num)
{
	int sumOdd=0;
	string num2=to_string(num);
	for(int i=0;i<num2.length();i++)
	{
		if((num2[i]-'0')%2!=0)
			sumOdd=sumOdd+(num2[i]-'0');
	}
	return sumOdd;
}
int main()
{
	int num;
	cout<<"Enter a number :";
	cin>>num;
	int ans1=sumofEven(num);
	int ans2=sumofOdd(num);
	cout<<"Even digits sum of given number :"<<ans1<<"\n";
	cout<<"Odd digits sum of given number :"<<ans2<<"\n";
	return 0;
}
