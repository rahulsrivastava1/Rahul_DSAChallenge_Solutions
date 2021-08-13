// all subsequences of a string

#include<bits/stdc++.h>
using namespace std;
void allSubsequences(string s,string p)
{
	if(s.empty())
	{
		cout<<p<<" ";
		return;
	}
	allSubsequences(s.substr(1),p+s[0]);
	allSubsequences(s.substr(1),p);
}
int main()
{
	string str2="";
	string str1;
	cout<<"Enter a string:";
	cin>>str1;
	allSubsequences(str1,str2);
	return 0;
}
