#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int a[10]={1,3,2,24,54,22,22,523,32,1000};

int partition(int *a,int l,int r){
    int mid = a[l];
    while(l<r){
        while(a[r]>=mid&&l<r) r--;
        a[l] = a[r];
        while(a[l]<=mid&&l<r) l++;
        a[r] = a[l];
    }
    a[l] = mid;
    return l;
}

void quick_sort(int *a,int l,int r){
    if(l>r) return ;
    int m = partition(a,l,r);
    quick_sort(a,l,m-1);
    quick_sort(a,m+1,r);
}

int main() {
	quick_sort(a,0,9);
	for(int i=0;i<10;i++) cout<<a[i]<<endl;


	return 0;
}
