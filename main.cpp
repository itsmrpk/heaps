#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void adjust(int a[],int i,int n)
{
    int l,r,lar;
    lar=i;
    l=2*i;
    r=2*i+1;
    if(r<=n&&a[r]>a[lar])
        lar=2*i+1;
    if(l<=n&&a[l]>a[lar])
        lar=2*i;
  if(lar!=i){
    swap(a[i],a[lar]);
    adjust(a,lar,n);
   }
}
heapify(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
        adjust(a,i,n);
}
heapsort(int a[],int n)
{
    int i;
    heapify(a,n);
    for(i=n;i>=2;i--){
        swap(a[1],a[i]);
        adjust(a,1,i-1);
    }
}



int main()
{
    int n,i,a[1000];
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    heapsort(a,n);
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}
