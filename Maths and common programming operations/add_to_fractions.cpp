// add to fractions

#include<bits/stdc++.h>
using namespace std;
int sum(int num1,int num2,int den1,int den2)
{
	int x,y,gcd;
	x=(num1*den2)+(num2*den1);
	y=den1*den2;
	for(int i=1;i<=x && i<=y;i++)
	{
		if(x%i==0 && y%i==0)
			gcd=i;	
	}	
	cout <<"\nThe added fraction is: "<<x/gcd <<"/"<<y/gcd;
	cout <<"\n";
}
int main()
{
	int num1,num2,den1,den2;
	cout<<"Enter numerator of first fraction:";
	cin>>num1;
	cout<<"Enter denominator of first fraction:";
	cin>>den1;
	cout<<"Enter numerator of second fraction:";
	cin>>num2;
	cout<<"Enter denominator of first fraction:";
	cin>>den2;
	sum(num1,num2,den1,den2);
	return 0;
}
