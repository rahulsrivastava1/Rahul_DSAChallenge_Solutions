// print the length of valid substring

#include<bits/stdc++.h>
using namespace std;
int findMaxLen(string s)
{
	int len=s.length();
	stack<int> st;
	st.push(-1);
	int res=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(')
			st.push(i);
		else
		{
			if(!st.empty())
				st.pop();
			if(!st.empty())
				res=max(res,i-st.top());
			else
				st.push(i);
		}
	}
	return res;
}
int main()
{
	string str1= "((()()";
    cout <<"Length of valid substring is:"<<findMaxLen(str1) << endl;
    string str2= "()(()))))";
    cout <<"Length of valid substring is:"<<findMaxLen(str2) << endl;
	return 0;
}
