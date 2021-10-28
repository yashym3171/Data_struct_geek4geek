#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxarea=0;
    void rowarea(int arr[MAX][MAX],int m,int k){//here k is row
        stack<int> s;//pushing index into it
        for(int l=0;l<m;l++){
            if(s.empty() || arr[k][l]>=arr[k][s.top()]){
                s.push(l);
            }else{
                while(!s.empty() && arr[k][s.top()]>arr[k][l]){
                    //pop untill stack.top is not greater then arr[l]
                    int h=arr[k][s.top()];
                    s.pop();
                    int newtop=!s.empty()?s.top():-1;//prev index of building whose height<h
                    int len=l-(newtop+1);//counts the columns which are of height h
                    maxarea=max(maxarea,len*h);
                }
                s.push(l);
            }
        }
        while(!s.empty()){//further maximize while stack is not empty
            int h=arr[k][s.top()];
            s.pop();
            int newtop=!s.empty()?s.top():-1;
            int len=m-(newtop+1);
            maxarea=max(maxarea,len*h);
        }
    }
    int maxArea(int arr[MAX][MAX], int n, int m) {
        rowarea(arr,m,0);//calculate for 1st row
        for(int k=1;k<n;k++){//start from 2nd row
            //update values for a row
            for(int l=0;l<m;l++){
                if(arr[k][l]==1){
                    arr[k][l]+=arr[k-1][l];
                }
            }
           //calculate area for kth row
           rowarea(arr,m,k);
        }
        return maxarea;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
