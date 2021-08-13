// frequency of each distinct characters

#include<bits/stdc++.h>
using namespace std;
void frequency(string s)
{
	map<char,int> mp;
	for(int i=0;i<s.length();i++)
		mp[s[i]]++;
	for(auto it:mp)
		cout<<it.first<<" :"<<it.second<<"\n";
}
int main()
{
	string str;
	cout<<"Enter a string :";
	cin>>str;
	frequency(str);
	return 0;
}
