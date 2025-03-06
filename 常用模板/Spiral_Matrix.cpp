#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int num = 1;
    int i = 0;
    int j = 0;
    int starti = 0;
    int startj = 0;
    vector<vector<int>> res(n, vector<int>(n, 0));
    int offset = 1;
    int loop = n/2;
    while(loop--){
        i = starti;
        j = startj;
        for(j;j<n-offset;j++){
            res[i][j] = num++;
        }
        for(i;i<n-offset;i++){
            res[i][j] = num++;
        }
        for(j;j>startj;j--){
            res[i][j] = num++;
        }
        for(i;i>starti;i--){
            res[i][j] = num++;
        }
        starti++;
        startj++;
        offset++;
    }
    if(n%2){
        res[n/2][n/2] = num;
    }
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(res[i][j]<10) cout<<"  "<<res[i][j];
			else cout<<" "<<res[i][j];
		}
		cout<<endl;
	}


    return 0;
}
