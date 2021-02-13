class Solution{   
public:
    void leftRotate(int arr[], int n, int d){
        int hold1=0,hold2=0,r=0;
        hold1=arr[r];
        arr[r]=-1;
        for(int i=0;i<n;i++){
            if(hold1==-1){
                hold1=arr[r+1];
                arr[r+1]=-1;
                r=r+1;
            }            
            if(r-d<0){
                hold2=arr[n+(r-d)];
                arr[n+(r-d)]=hold1;
                hold1=hold2;
                r=n+(r-d);
            }
            else{
                hold2=arr[r-d];
                arr[r-d]=hold1;
                hold1=hold2;
                r=(r-d);
            }
    
        }
    }
};
