#include <iostream>
using namespace std;

int pivot( int arr[], int n){
    int l=0, h=n-1, mid=0;
    
    mid=(l+h)/2;
    if ( n<2)
        return mid;
        
    while( l<=h){
        mid=(l+h)/2;

        if ( arr[mid]<arr[mid-1])
            return mid;
    
        if ( arr[0]<arr[mid])
            l=mid+1;
    
        else
            h=mid-1;
    }
}

int binarySearch( int arr[], int n, int k){
    int l=0, h=n-1, mid=0;

    if ( n>2){

        if ( k<arr[0])
            l=pivot( arr, n);
        else
            h=pivot( arr, n)-1;
    } 

    while ( l<=h){
        mid=(l+h)/2;
        
        if ( k==arr[mid])
            return mid;
        
        if ( k<arr[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int main() {
	int t, n, k;
	cin >> t;
	
	for(int i=0; i<t; i++){
	    cin >> n;
	    int arr[n];
	    
	    for ( int j=0; j<n; j++){
	        cin >> arr[j];
	    }
	    cin >> k;
	    
	    cout << binarySearch( arr, n, k) << "\n";
	}
	return 0;
}