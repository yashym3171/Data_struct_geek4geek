#include <bits/stdc++.h>
using namespace std;


//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n){
    
    long long dp[1005][1005];
    
    for(int i=0 ; i<n ; i++){
        dp[i][i] = arr[i];
    }
    
    for(int k=1 ; k<n ; k++){
        int i=0;
        int j=k;
        while(j<n){
            
            if(j==i+1){
                dp[i][j] = max(arr[i] , arr[j]);
            }else{
                dp[i][j] = max(arr[i] + min(dp[i+2][j] , dp[i+1][j-1]) , arr[j] + min(dp[i+1][j-1] , dp[i][j-2]));
            }
            
            i++;
            j++;
        }
    }
    
    return dp[0][n-1];
    
    
    
}

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int* A = new int[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}