// palindrome or not?

#include<bits/stdc++.h>
using namespace std;
void palindrome(string s)
{
	string p=s;
	reverse(p.begin(),p.end());
	if(s==p)
		cout<<"Palindrome!";
	else
		cout<<"Not palindrome!";
}
int main()
{
	string str;
	cout<<"Enter a string :";
	cin>>str;
	palindrome(str);
	return 0;
}
