#include <iostream>
using namespace std;

int main() {
    int Test_case;
    int Arr_size,No_rotate;
    cin>>Test_case;
//    cout<<"\n";
    for(int i=0;i<Test_case;i++){
        cin>>Arr_size>>No_rotate;
//        cout<<"\n";
        int Arr[Arr_size];
        for(int j=0;j<Arr_size;j++){
            cin>>Arr[j];
        }
        int Hold[No_rotate];
        for(int k=0;k<No_rotate;k++){
            Hold[k]=Arr[k];
        }
        for(int l=No_rotate;l<Arr_size;l++){
            Arr[l-No_rotate]=Arr[l];
        }  
        for(int m=0;m<No_rotate;m++){
        Arr[Arr_size-No_rotate+m]=Hold[m];
        }
        for(int n=0;n<Arr_size;n++){
            cout<<Arr[n]<<' ';
        }  
        cout<<"\n";
    }
	return 0;
}