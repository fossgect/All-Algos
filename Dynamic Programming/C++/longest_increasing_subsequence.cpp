#include<bits/stdc++.h>  
using namespace std; 

void lis( int arr[], int n )  
{  
    	vector<int> lis_series[n];
    	int lis_len[n],i,j;  
    	lis_len[0] = 1;
    	lis_series[0].push_back(arr[0]);
    	for (i = 1; i < n; i++)  
    	{ 
      		lis_len[i] = 1;
       	 	for(j = 0; j < i; j++) {
       	 		if(arr[j] < arr[i] && lis_len[i] < lis_len[j]+1) {
      	  			lis_len[i] = lis_len[j] + 1;
      	  			lis_series[i].push_back(arr[j]);
        		}	
      	  	}
      	  	lis_series[i].push_back(arr[i]);
    	}
    	int high = lis_len[0], index = 0; 
    	for (i=1; i<n ;i++) {
    		if(lis_len[i] > high) {
    			high = lis_len[i];
    			index = i;
    		}
    	}
    	cout << "Length of longest increasing subsequence is : " << high << "\n";
    	cout << "Series : ";
    	for (auto u: lis_series[index])
    		cout<<u<<" ";
    	cout<<"\n";
    	return;
}  
    

int main()  
{  
    	int n;
    	cout << "Array size : ";
    	cin >> n;
    	int arr[n];
    	if(n > 0) {
    		cout << "Array elements : ";
		for(int i=0;i<n;i++)
			cin>>arr[i];
    		lis(arr,n);
    	}
    	else
    		cout<<"Array is empty\n";       
    	return 0;  
}
