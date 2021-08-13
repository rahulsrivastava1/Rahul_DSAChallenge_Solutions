// sum of numbers formed by exchanging consecutive digits

#include<bits/stdc++.h>
using namespace std;
int sumOfDigits(int num)
{
	int num1=0,num2=0,sum=0;
	while(num>9)
	{
		num1=num%10;
   		num=num/10;
   		num2=num%10;
   		num1=num1*10;
   sum=sum+num1+num2;
	}
	return sum;
}
int main()
{
	int num;
	cout<<"Enter the number :";
	cin>>num;
	int ans=sumOfDigits(num);
	cout<<"sum of numbers formed by exchange of consecutive digits :"<<ans;
	return 0;
}
