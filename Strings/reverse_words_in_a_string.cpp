// reverse words in a string

#include<bits/stdc++.h>
using namespace std;
#define OUT 0
#define IN 1
int wordscount(string s)
{
	int count=0;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ')
			count++;
	}
	return count+1;
}
void reverse(string s,int n)
{
	vector<string> temp;
	string p="";
	if(n==1)
	{
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
	else
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==' ')
			{
				temp.push_back(p);
				p="";
			}
			else
				p+=s[i];
		}
	}
	temp.push_back(p);
	for(int i=temp.size()-1;i>0;i--)
		cout<<temp[i]<<" ";
	cout<<temp[0]<<"\n";
}
int main()
{
	char str[100];
	cout<<"Enter a string:";
	gets(str);
	int len=wordscount(str);
	reverse(str,len);
	return 0;
}
