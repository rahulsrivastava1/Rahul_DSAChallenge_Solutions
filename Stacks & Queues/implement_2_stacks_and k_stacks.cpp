// implement 2 stacks and k stacks in arrray

#include<bits/stdc++.h>
using namespace std;
class twoStacks
{
	int *arr;
	int size;
	int top1,top2;
	public:
		twoStacks(int n)
		{
			size=n;
			arr=new int[n];
			top1=-1;
			top2=size;	
		}	
		void push1(int x)
		{
			if(top1<top2-1)
			{
				top1++;
				arr[top1]=x;
			}
			else
			{
				cout<<"Stack overflow!";
				exit(1);
			}
		}
		void push2(int y)
		{
			if(top1<top2-1)
			{
				top2--;
				arr[top2]=y;
			}
			else
			{
				cout<<"Stack overflow!";
				exit(1);
			}			
		}
		int pop1()
		{
			if(top1>=0)
			{
				int x=arr[top1];
				top1--;
				return x;
			}
			else
			{
				cout<<"Stack underflow!";
				exit(1);
			}
		}
		int pop2()
		{
			if(top2<size)
			{
				int x=arr[top2];
				top2++;
				return x;
			}
			else
			{
				cout<<"Stack underflow!";
				exit(1);
			}
		}
};
class kStacks
{
	int *arr;
	int *top;
	int *next;
	int n,k,free;
	public:
		kStacks(int k,int n)
		{
			arr = new int[n];
    		top = new int[k];
    		next = new int[n];
    		for (int i = 0; i < k; i++)
        		top[i] = -1;
        	free = 0;
    		for (int i=0; i<n-1; i++)
        		next[i] = i+1;
    		next[n-1] = -1; 
		}
		bool isFull()
		{
			return (free==-1);	
		}	
		bool isEmpty(int sn)
		{
			return (top[sn] == -1);
		}
		void push(int item,int sn)
		{
			if(isFull())
			{
				cout<<"Stack overflow!";
				exit(1);
			}
			int i=free;
			free=next[i];
			next[i]=top[sn];
			top[sn]=i;
			arr[i]=item;
		}
		int pop(int sn)
		{
			if(isEmpty(sn))
			{
				cout<<"Stack underflow!";
				return INT_MAX;
			}
			int i=top[sn];
			top[sn] = next[i];
    		next[i] = free;
    		free = i;
   			return arr[i];
		}
};
int main()
{
	// for 2 stacks
	twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ts.pop2();
    // for k-Stacks
    int k = 3, n = 10;
    kStacks ks(k, n);
    
    // Let us put some itemns in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
  
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
  
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
  	
  	
  	cout<<"\nK-stacks operations\n";
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
  	return 0;
    
}
