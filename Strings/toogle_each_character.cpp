// toogle each character in a string

#include<bits/stdc++.h>
using namespace std;
void toogleCharacter(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='A' && s[i]<='Z')
			s[i]=s[i]+'a'-'A';
		else if(s[i]>='a' && s[i]<='z')
			s[i]=s[i]+'A'-'a';
	}
	cout<<"Output string :"<<s;
}
int main()
{
	string str;
	cout<<"Enter a string:";
	cin>>str;
	toogleCharacter(str);
	return 0;
}
