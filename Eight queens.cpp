#include<string>
#include<iostream>
#include<vector>

using namespace std;

vector<string> res;

bool isvalid(int row,int col,vector<string> &chess){
    for(int i=1;i<row;i++){
        if(chess[i][col]=='Q') return false;
    }
    for(int i=row-1,j=col-1;i>=1&&j>=1;j--,i--){
        if(chess[i][j]=='Q') return false;
    }
    for(int i=row-1,j=col+1;i>=1&&j<=8;j++,i--){
        if(chess[i][j]=='Q') return false;
    }
    return true;
}

void dfs(int row,vector<string> &chess,string str){
    if(row==9){
        res.push_back(str);
    }
    for(int col=1;col<=8;col++){
        if(isvalid(row,col,chess)){
            chess[row][col] = 'Q';
            str = str+to_string(col);
            dfs(row+1,chess,str);
            chess[row][col] = '.';
            str = str.substr(0,str.size()-1);
        }
    }
}

int main(){
    string str="";
    vector<string> chess(9,string(9,'.'));
    dfs(1,chess,str);
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        cout<<res[x-1]<<endl;
    }
    return 0;
}
