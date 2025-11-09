#include <iostream>
using namespace std;

class MaxPQ{
    int a[1000];
    int n;
public:
    MaxPQ(){ n=0; }

    void push(int x){
        a[n]=x;
        int i=n++;
        while(i>0){
            int p=(i-1)/2;
            if(a[p]>=a[i]) break;
            int t=a[p]; a[p]=a[i]; a[i]=t;
            i=p;
        }
    }

    void pop(){
        if(n==0) return;
        a[0]=a[--n];
        int i=0;
        while(true){
            int l=2*i+1,r=2*i+2,lg=i;
            if(l<n && a[l]>a[lg]) lg=l;
            if(r<n && a[r]>a[lg]) lg=r;
            if(lg==i) break;
            int t=a[i]; a[i]=a[lg]; a[lg]=t;
            i=lg;
        }
    }

    int top(){
        if(n==0) return -1;
        return a[0];
    }

    bool empty(){ return n==0; }
};

int main(){
    MaxPQ pq;
    pq.push(10);
    pq.push(4);
    pq.push(15);
    pq.push(7);
    pq.pop();
    int x = pq.top();
}
