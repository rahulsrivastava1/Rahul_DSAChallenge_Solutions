// kth digit from last and begin

#include<bits/stdc++.h>
using namespace std;
int kthDigitfromlast(int num,int k)
{
	string num1=to_string(num);
	cout<<"kth digit from last is :"<<num1[num1.length() - k] - '0'<<"\n";
}
int kthDigitfrombegin(int num,int k)
{
	string num2=to_string(num);
	for(int i=1;i<=num2.length();i++)
	{
		if(i==k)
			cout<<"kth digit from begin is :"<<num2[i-1]<<"\n";		
	}
}
int main()
{
	int num,k;
	cout<<"Enter the number :";
	cin>>num;
	cout<<"Enter the value of k :";
	cin>>k;
	kthDigitfromlast(num,k);
	kthDigitfrombegin(num,k);
	return 0;
}
