#include <iostream>
using namespace std;

void heapifyInc(int a[], int n, int i){
    int l=2*i+1,r=2*i+2,lg=i;
    if(l<n && a[l]>a[lg]) lg=l;
    if(r<n && a[r]>a[lg]) lg=r;
    if(lg!=i){ int t=a[i]; a[i]=a[lg]; a[lg]=t; heapifyInc(a,n,lg); }
}

void heapifyDec(int a[], int n, int i){
    int l=2*i+1,r=2*i+2,sm=i;
    if(l<n && a[l]<a[sm]) sm=l;
    if(r<n && a[r]<a[sm]) sm=r;
    if(sm!=i){ int t=a[i]; a[i]=a[sm]; a[sm]=t; heapifyDec(a,n,sm); }
}

void heapSortInc(int a[], int n){
    for(int i=n/2-1;i>=0;i--) heapifyInc(a,n,i);
    for(int i=n-1;i>=0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapifyInc(a,i,0);
    }
}

void heapSortDec(int a[], int n){
    for(int i=n/2-1;i>=0;i--) heapifyDec(a,n,i);
    for(int i=n-1;i>=0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapifyDec(a,i,0);
    }
}

int main(){
    int a[]={4,1,7,8,3,2};
    int n=6;
    heapSortInc(a,n);
    heapSortDec(a,n);
}
