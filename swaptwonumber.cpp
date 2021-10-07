#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 10;
    int b = 20;
    cout << "a = " << a << " " << "b = " << b <<"\n";
    
    // Swap by using third variable
    int t = a;
    a = b;
    b = t;
    cout << "a = " << a << " " << "b = " << b <<"\n";
    
    // Swap without using third variable 
    b = a + b;
    a = b - a;
    b = b - a;
    cout << "a = " << a << " " << "b = " << b <<"\n";
    return 0;
}
