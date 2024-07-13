#include <iostream> 
#include<vector>
#include<stack>
using namespace std;
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
bool M[4][4] = { { 0, 0, 1, 0 },{ 0, 0, 1, 0 },{ 0, 0, 0, 0 },{ 0, 0, 1, 0 } };

bool know(int a,int b)
{
	return M[a][b];
}

int findCelebrity(int n) {
 	int p = 0 ;
	int q = n-1 ;

	while(p<q)
	{
		if(know(p,q))
		{
			p++;
		}
		else{
			q--;
		}
	}

	int celeb = p;
	bool knowAny = false;
	bool KnownToAll = true;

	for(int i = 0;i<n;i++)
	{
		if(know(celeb,i))
		{
			knowAny = true;
			break;
		}
	}

	for(int i = 0;i<n;i++)
	{
		if(i != celeb && !know(i,celeb))
		{
			KnownToAll = false;
			break;
		}
	}

	if(knowAny or !KnownToAll)
	{
		celeb = -1;
	}

	return celeb;
};

//Two pointer approach

int findCelebrity(int n) {
    
    // Two pointers pointing at start and end of search space.
    int p = 0, q = n-1; 

    // Finding celebrity.
    while(p < q) {
        if(know(p, q)) {
            // This means p cannot be celebrity.
            p++;  
        }
        else {
            // This means q cannot be celebrity.
            q--; 
        }
    }

    int celebrity = p;
    bool knowAny = false, knownToAll = true;

    // Verify whether the celebrity knows any other person.
    for(int i = 0; i < n; i++) {
        if(know(celebrity, i)) {
            knowAny = true;
            break;
        }
    }

    // Verify whether the celebrity is known to all the other person.
    for(int i = 0; i < n; i++) {
        if(i != celebrity and !know(i, celebrity)) {
            knownToAll = false;
            break;
        }
    }

    if(knowAny or !knownToAll) {
        // If verificatin failed, then it means there is no celebrity at the party.
        celebrity = -1;
    }

    return celebrity;
}

//Approach using stack

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and copare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
        
    }
};
