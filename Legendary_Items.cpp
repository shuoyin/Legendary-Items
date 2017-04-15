#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;

double cal(int P, int Q, int N, int n, vector<double> &v){
    if(v[n]>=0)
        return v[n];
    double k=cal(P,Q,N,n-1,v);
    vector<double> p;
    double pp=int(P/pow(2,N-n))/100.0;
    while(pp<1){
        p.push_back(pp);
        pp = min(1.0, pp+Q/100.0);
    }
    p.push_back(1);
    vector<double> cp(p.size());
    cp[0]=1;
    for(int i=1;i<cp.size(); i++) cp[i]=cp[i-1]*(1-p[i-1]);
    for(int i=0;i<cp.size(); i++) cp[i]*=p[i];
    double r=0;
    for(int i=0; i<p.size(); i++) r+=cp[i]*(k+i+1);
    v[n]=r;
    return r;
}

int main()
{
    int P, Q, N;
    cin>>P>>Q>>N;
    vector<double> e(N+1, -1);
    e[0]=0;
    cal(P,Q,N,N,e);
    printf("%.2f", e[N]);
    return 0;
}
