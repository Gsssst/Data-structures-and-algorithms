#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
string inorder,levelorder;

void getpreorder(int al,int ar,int bl,int br){
    int i,j;
    for(i=bl;i<=br;i++){//找层次遍历与中序遍历中第一个相同的点，该点为前序遍历当前访问结点
        bool flag = false;
        for(j=al;j<=ar;j++){
            if(inorder[j]==levelorder[i]){
                cout<<levelorder[i];
                flag = true;
                break;
            }
        }
        if(flag == true) break;
    }
    if(j>al) getpreorder(al,j-1,0,br);
    if(j<ar) getpreorder(j+1,ar,0,br);
}

int main(){
    cin>>inorder>>levelorder;
    getpreorder(0, inorder.size() - 1, 0, levelorder.size() - 1);
    
    return 0;
}
