// search an element in sorted 2-D array

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[3][4]={{1,3,5,7},
					{10,11,16,20},
					{23,30,34,50}
					};
	int target=16,flag=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(arr[i][j]==target)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
		cout<<"True";
	else
		cout<<"False";
	return 0;
}
