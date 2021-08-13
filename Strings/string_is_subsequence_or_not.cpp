// check if a string is a subsequence of another or not?

#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s,string p,int m,int n)
{
	if(n==0)
		return true;
	if(m==0)
		return false;
	if(s[m-1]==p[n-1])
		return isSubsequence(s,p,m-1,n-1);
	return isSubsequence(s,p,m-1,n);
}
int main()
{
	string str1,str2;
	cout<<"Enter first string:";
	cin>>str1;
	cout<<"Enter second string:";
	cin>>str2;
	int size1=str1.length();
	int size2=str2.length();
	isSubsequence(str1,str2,size1,size2)?cout<<"True":cout<<"False";
	return 0;
}
