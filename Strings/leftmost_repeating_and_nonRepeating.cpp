// leftmost repeating and non-repeating character

#include<bits/stdc++.h>
using namespace std;
int leftmostRepeating(string& s)
{
	int firstIndex[256];
	for(int i=0;i<256;i++)
		firstIndex[i]=-1;
	int res=INT_MAX;
	for(int i=0;i<s.length();i++)
	{
		if(firstIndex[s[i]]==-1)
			firstIndex[s[i]]=i;
		else
			res=min(res,firstIndex[s[i]]);
	}
	return (res==INT_MAX)?-1:res;
}
int leftmostNonRepeating(string s)
{
	int firstIndex[256];
	for(int i=0;i<256;i++)
		firstIndex[i]=-1;
	for(int i=0;i<s.length();i++)
	{
		if(firstIndex[s[i]]==-1)
			firstIndex[s[i]]=i;
		else
			firstIndex[s[i]]=-2;
	}
	int res=INT_MAX;
	for(int i=0;i<256;i++)
	{
		if(firstIndex[i]>=0)
			res=min(res,firstIndex[i]);
	}
	if(res==INT_MAX)
		return -1;
	else
		return res;
}
int main()
{
	string str;
	cout<<"Enter a word:";
	cin>>str;
	int index1=leftmostRepeating(str);
	if(index1==-1)
		cout<<"No repeating character found!"<<"\n";
	else
		cout<<"Leftmost repeating character is:"<<str[index1]<<"\n";
	int index2=leftmostNonRepeating(str);
	if(index2==-1)
		cout<<"No non-repeating character found!"<<"\n";
	else
		cout<<"Leftmost non-repeating character is:"<<str[index2];
	return 0;
}
