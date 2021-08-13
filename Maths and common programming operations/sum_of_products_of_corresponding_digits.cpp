//  sum of products of corresponding digits

#include<bits/stdc++.h>
using namespace std;
int sumCorrespondingDigits(int num1,int num2)
{
	string numA=to_string(num1);
	string numB=to_string(num2);
	int sum=0;
	for(int i=0;i<numA.length();i++)
	{
		sum=sum+((numA[i]-'0')*(numB[i]-'0'));
	}
	return sum;
}
int main()
{
	int num1,num2;
	cout<<"Enter the first number :";
	cin>>num1;
	cout<<"Enter the second number :";
	cin>>num2;
	int ans=sumCorrespondingDigits(num1,num2);
	cout<<"The sum of products of corresponding digits is :"<<ans;
	return 0;
}
