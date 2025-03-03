#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
string a,b;

string sub(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    string s;
    int len = max(a.size(),b.size());
    int i = 0;
    int j = 0;
    while(i<len){
        int temp = 0;
        temp -= j;
        if(i<a.size()) temp+=(a[i]-'0');
        if(i<b.size()) temp-=(b[i]-'0');
        if(temp>=0){
            j = 0;
            s += char(temp+'0');
        }else{
            j = 1;
            temp+=10;
            s += char(temp+'0');
        }
        i++;
    }
    reverse(s.begin(),s.end());
    while(s[0]=='0'){
        s = s.substr(1);
    }
    return s;
}

int main(){
    cin>>a>>b;
    string c = sub(a,b);
    cout<<c<<endl;
    return 0;
}
