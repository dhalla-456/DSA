#include <bits/stdc++.h> 
using namespace std;

// void solve(string str,string output,int index,vector<string> &ans)
// {
// 	if(index >= str.length())
// 	{
// 		if(output.length() > 0)
// 		{
// 			ans.push_back(output);
// 		}
// 		return;
// 	}

// 	solve(str,output,index+1,ans); //exclude call

// 	char element = str[index];
// 	output.push_back(element);
// 	solve(str,output,index+1,ans);
// }

void solve2(string str,int index,string ans){
	if(index == str.length()){
		cout<<ans<<endl;
		return;
	}

	//include
	solve2(str,index+1, ans + str[index]);

	//exclude
	solve2(str,index+1,ans);
}

// vector<string> subsequences(string str){
	
// 	vector<string> ans;
// 	string output = "";
// 	int index = 0 ;
// 	solve(str,output,index,ans);
// 	return ans;
// }

int main(){
	string s = "abc";
	int index = 0;
	string ans = "";
	solve2(s,index,ans);
}
