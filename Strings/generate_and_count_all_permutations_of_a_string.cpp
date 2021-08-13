// generate and count all permutations of a string

#include<bits/stdc++.h>
using namespace std;
void allPermutations(string s,int l,int r)
{
	if(l==r)
		cout<<s<<" ";
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			allPermutations(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
}
long long fact(int n)
{
	for(int i=n-1;i>1;i--)
		n*=i;
	return n;
}
int countPermutation(char *s)
{
	int countoccur[26]={0},len,res;
	len=strlen(s);
	for(int i=0;i<len;i++)
		countoccur[s[i]-'a']++;
	res=fact(len);
	for(int i=0;i<26;i++)
	{
		if(countoccur[i]>1)
			res=res/fact(countoccur[i]);
	}
	return res;
}
int main()
{
	char str[100];
	cout<<"Enter a word:";
	cin>>str;
	int n=strlen(str);
	allPermutations(str,0,n-1);
	int ans=countPermutation(str);
	cout<<"The no. of permutations is:"<<ans;
	return 0;
}
