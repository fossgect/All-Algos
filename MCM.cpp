
  // DP - MCM memoization
#include<bits/stdc++.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;
 int static dp[1001][1001];
int MCM(int *arr,int i,int j)
{
   if(i>=j)
      return 0;
   if(dp[i][j]!=-1)
      return dp[i][j];

   int ans=INT_MAX;
   for(int k=i;k<j;k++)
   {
       int tempans=MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];

       if(tempans<ans)
          ans=tempans;
   }
  return dp[i][j]=ans;
}
int main()
{
    int n,sum;
    cout<<"array size : ";
    cin>>n;
    int arr[n];
    cout<<"array elements : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
   cout<<"\nmin cost of matrix multiplication : "<<MCM(arr,1,n-1)<<endl;
    return 0;
}
