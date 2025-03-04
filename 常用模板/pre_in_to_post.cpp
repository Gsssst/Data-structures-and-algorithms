#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
string a;//前序
string b;//中序
unordered_map<char,int> p;

void build(int al,int ar,int bl,int br){
    if(al>ar) return ;
    char root = a[al];
    int x = p[root];
    build(al+1,x-bl+al,bl,x-1);
    build(x-bl+al+1,ar,x+1,br);
    cout<<root;
    
}

int main(){
    while(cin>>a>>b){
        int x = a.size();
        int y = b.size();
        for(int i=0;i<b.size();i++) p[b[i]] = i;
        build(0,a.size()-1,0,b.size()-1);
        cout<<endl;
    }
    
    return 0;
}
