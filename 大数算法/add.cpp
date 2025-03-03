#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string f(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int n = max(a.size(),b.size());
    string str1;
    int i=0;
    int j=0;
    while(i<n){
        int temp = 0;
        temp+=j;
        if(a.size()>i){
            temp += (a[i]-'0');
        }
        if(b.size()>i){
            temp += (b[i]-'0');
        }
        if(temp<10){
            str1+=to_string(temp);
            j = 0;
        }else {
            str1+=to_string(temp%10);
            j = 1;
        }
        i++;
    }
    if(j==1) str1+='1';
    reverse(str1.begin(),str1.end());
    return str1;
}

int main(){
    string a;
    string b;
    while(cin>>a>>b){
        cout<<f(a,b)<<endl;
    }
    return 0;
    
}
