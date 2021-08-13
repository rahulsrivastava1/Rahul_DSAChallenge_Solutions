// given pattern is available in the given string or not

#include<bits/stdc++.h>
using namespace std;
void isPattern(string s,string p)
{
	int found=s.find(p);
	while(found!=string::npos)
	{
		cout<<"Found at index"<<found <<"\n";
		found=s.find(p,found+1);
	}
}
int main()
{
	string str,pattern;
	cout<<"Enter a string:";
	cin>>str;
	cout<<"Enter pattern:";
	cin>>pattern;
	isPattern(str,pattern);
}
