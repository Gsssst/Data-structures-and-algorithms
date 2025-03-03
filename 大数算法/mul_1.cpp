#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 1010;
vector<string> F(N);

string mul(string A, int b)
{
    int t =0;
    string C;
    for(int i=0;i<A.size()||t;i++)
    {
        if(i < A.size()) t += (A[i]-'0')* b;
        C += to_string(t % 10);
        t /= 10;
    }
    return C;
}



int main()
{
    F[0] = "1";
    for(int i=1;i<=1000;i++)
    {
        F[i] = mul(F[i-1],i);
    }
    int a;
    while(cin >> a)
    {
        reverse(F[a].begin(),F[a].end());
        cout<<F[a]<<endl;
    }
}
