#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
double PI = acos(-1);

class angle
{
public:
    int degree;
    angle(){
        
    }
    angle(int d){
        degree = d;
    }
    angle operator-(angle b)
    {
        angle c;
        c.degree = degree-b.degree;
        return c;
    }
    void print(){
        printf("%.2lf\n",sin(degree/180.0*PI));
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        angle a(x),b(y);
        a = a-b;
        a.print();
    }
    return 0;
}
