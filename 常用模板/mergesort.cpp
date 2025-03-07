#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<functional>

using namespace std;
const int N = 5e5+10;
int a[N],b[N];
int n;
long long ans;

void merge(int l1,int r1,int l2,int r2){
	int i=l1,j=l2,k=l1;
	while(i<=r1&&j<=r2){
		if(a[i]>a[j]){
			ans += r1-i+1;
			b[k++] = a[j++];
		}else{
			b[k++] = a[i++];
		}
	}
	while(i<=r1) b[k++]= a[i++];
	while(j<=r2) b[k++]= a[j++];
	for(i=l1;i<=r2;i++){
		a[i] = b[i];
	}
}

void mergesort(int l,int r){
	if(l>=r) return ;
	int mid = (l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	merge(l,mid,mid+1,r);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	mergesort(1,n);
	printf("%d",ans);	
    return 0;
}
