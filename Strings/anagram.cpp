// anagram or not?

#include<bits/stdc++.h>
using namespace std;
void isAnagram(string s,string p)
{
	sort(s.begin(),s.end());
	sort(p.begin(),p.end());
	bool flag=true;
	if(s.length()!=p.length())
		flag=false;
	else
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]!=p[i])
				flag=false;
		}
	}
	if(flag==true)
		cout<<"Anagram!";
	else
		cout<<"Not anagram!";
}
int main()
{
	string str1,str2;
	cout<<"Enter first string:";
	cin>>str1;
	cout<<"Enter second string:";
	cin>>str2;
	isAnagram(str1,str2);
	return 0;
}
