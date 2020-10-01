/* implementing coin change probelm to print no of possible ways to form the sum with dynamic programming concepts */

#include<bits/stdc++.h>  
using namespace std;


void coin_change(int coins[], int n, int amt) {
	int i, j, x, y; 
    	int table[amt+1][n]; 
    	for (i = 0; i < n; i++) 
        	table[0][i] = 1; 
	for (i = 1; i < amt + 1; i++) { 
		for (j = 0; j < n; j++) { 
			if(i-coins[j] >= 0)
				x = table[i - coins[j]][j];
			else 
				x = 0;
	 		if(j >= 1)
	 			y = table[i][j - 1]; 
	 		else
	 			y = 0;
	 		table[i][j] = x + y; 
		} 
	    } 
	    cout << "Available Combinations : " << table[amt][n-1] << "\n"; 
		return;
}


int main()  
{  
    	int amt,n;
    	cout << "Amount : ";
    	cin >> amt;
    	cout << "No of coins : ";
    	cin >> n;
    	int coins[n];
    	if(n > 0) {
    		cout << "Enter coins : ";
		for(int i=0;i<n;i++)
			cin>>coins[i];
    		coin_change(coins,n,amt);
    	}
    	else
    		cout<<"No coins available\n";       
    	return 0;
}
