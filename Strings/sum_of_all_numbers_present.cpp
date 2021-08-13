// sum of all numbers present in alpha-numeric

#include<bits/stdc++.h>
using namespace std;
void sumofallDigits(string s)
{
	string temp ="";
	int sum = 0;
	for (char ch: s)
	{
		if (isdigit(ch))
			temp += ch;
		else
		{
			sum += atoi(temp.c_str());
			temp = "";
		}
	}
	cout<<sum + atoi(temp.c_str());
}
int main()
{
	string str;
	cout<<"Enter a string:";
	cin>>str;
	int count=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>=1 && str[i]<=9)
			count++;
	}
	if(str.length()==count)
		cout<<0;
	else
		sumofallDigits(str);
	return 0;
}
