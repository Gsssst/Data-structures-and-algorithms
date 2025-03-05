#include<vector>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

vector<int> add(vector<int> &A,vector<int> &B) // 高精度加法
{
    vector<int> res;
    for(int i=0,t=0;i<A.size() || i<B.size() || t;i++)
    {
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        res.push_back(t%10);
        t/=10;
    }
    return res;
}

vector<int> mul(vector<int> &A,vector<int> &B) // 高精度乘法
{
    vector<int> res(A.size()+B.size(),0);
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
            res[i+j]+=A[i]*B[j];
    for(int i=0,t=0;i<res.size();i++)
    {
        t+=res[i];
        res[i]=t%10;
        t/=10;
    }
    while(res.size()>1 && res.back()==0) res.pop_back();
    return res;
}

int main(){
    int n;
	cin>>n;
	vector<int> res2;
	res2.push_back(0);
	for(int i=1;i<=n;i++){
		vector<int> res1;
		res1.push_back(1);
		for(int j=1;j<=i;j++){
			int temp = j;
			vector<int> v;
			while(temp!=0){
				v.push_back(temp%10);
				temp /= 10;
			}
			res1 = mul(v,res1);
		}
		res2 = add(res1,res2);
	}
	reverse(res2.begin(),res2.end());
	for(int i=0;i<res2.size();i++) cout<<res2[i];
    return 0;
}
