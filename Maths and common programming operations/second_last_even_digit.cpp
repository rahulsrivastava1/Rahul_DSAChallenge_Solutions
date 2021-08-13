// second last even digit

#include<bits/stdc++.h>
using namespace std;
int secondLastEven(int num)
{
	int count=0;
	while(num)
	{
		int rem=num%10;
		num=num/10;
		if(rem%2==0)
			count++;
		if(count==2)
		{
			return rem;
			break;
		}
	}
}
int main()
{
	int num;
	cout<<"Enter a number:";
	cin>>num;
	int ans=secondLastEven(num);
	cout<<"Second last even digit is :"<<ans;
	return 0;
}
