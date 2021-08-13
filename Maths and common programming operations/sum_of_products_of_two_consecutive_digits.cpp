// sum of products of two consecutive digits

#include<bits/stdc++.h>
using namespace std;
int sumConsecutiveDigits(int num)
{
	string num1=to_string(num);
	int sum=0;
	for(int i=0;i<num1.length()-1;i++)
	{
		sum =sum+((num1[i]-'0')*(num1[i+1]-'0'));
	}
	return sum;
}
int main()
{
	int num;
	cout<<"Enter the number :";
	cin>>num;
	int ans=sumConsecutiveDigits(num);
	cout<<"Sum of products of two consecutive digits :"<<ans;
	return 0;
}


