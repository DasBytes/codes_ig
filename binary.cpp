#include<bits/stdc++.h>
using namespace std;

int binarySearch(int A[], int x, int high,int low)
{
    if(high>=low)
    {
        int mid= low+(high-low)/2;
        if(x==A[mid])
        return mid;
        if(x>A[mid])
        return binarySearch( A,  x, high, mid+1);

        return binarySearch( A,  x, mid-1, low);



    }
    return -1;
}


int main()
{
    int A[5];
    int x;
     int n=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

   cout<<"enter search number"<<endl;
   cin>>x;
    int result=binarySearch(A,x,n-1,0);
    if(result==-1)
    {
        cout<<"not found";
    }
    else
        cout<<"found at"<<result<<endl;
}
