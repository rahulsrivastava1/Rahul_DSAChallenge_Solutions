// positional values of digits

#include<bits/stdc++.h>
using namespace std;
int positionalValues(int num)
{
	int m=0,n=1;
	while(num)
	{
		m=num%10;
		m=m*n;
		cout<<m<<" ";
		n=n*10;
		num=num/10;
	}
}
int main()
{
	int num;
	cout<<"Enter the number :";
	cin>>num;
	positionalValues(num);
	return 0;
}
