// numbers of times digits occurs

#include<bits/stdc++.h>
using namespace std;
int countDigits(int num,int x)
{
	int count=0;
	while(num)
	{
		int rem=num%10;
		num=num/10;
		if(rem==x)
			count++;
	}
	return count;
}
int main()
{
	int num,x;
	cout<<"Enter a number :";
	cin>>num;
	cout<<"Enter digit:";
	cin>>x;
	int ans=countDigits(num,x);
	cout<<"Number of times "<<x<<" occurs:"<<ans;
	return 0;
}
