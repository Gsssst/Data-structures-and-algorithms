#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<functional>

using namespace std;
string s;
int k;
int mark;
int n;

char find_min(int l,int r){
	char minc = s[l];
	mark = l+1;
	for(int i=mark;i<=r;i++){
		if(s[i]<minc){
			minc = s[i];
			mark = i+1;
		}
	}
	return minc;
}

int main(){
	cin>>s;
	cin>>k;
	int n = s.size();
	string ans;
	for(int i=0;i<n-k;i++){
		ans += find_min(mark,k+i);
	}
	while(ans[0]=='0'&&ans.size()>1) ans = ans.substr(1);
	cout<<ans<<endl;
    return 0;
}
