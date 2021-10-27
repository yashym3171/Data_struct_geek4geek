
#include <bits/stdc++.h>
using namespace std;
string ReverseSort(string str);

int main(){
    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;
        cout << ReverseSort(s) << endl;
    }
return 0;
}
// } Driver Code Ends



string ReverseSort(string str){
    string g;
    sort(str.begin(),str.end());
    for(int i=str.length()-1;i>=0;i--)
    {
        g+=str[i];
    }
    return g;
}
