#include<stdio.h>
#define max 100
int check2array(int a[],int n,int b[],int m){
    if(m!=n) return 0;
    else{
        int equal=1;//assume that 2 array is equal
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                equal=0;//2 arrays is not equal
                break;
            }
        }
        if(equal==1) return 1;
        else{
            int symmetric=1;//assume that 2 array is symmetric
            for(int i=0;i<n;i++){
                if(a[i]!=b[n-1-i]) symmetric=0;//2 arrays is not symetric
            }
            if(symmetric==0) return 0;
            else return -1;
        }
    }
}
int main(){
    int a[max];
    int b[max];
    int n,m;
    printf("Enter the elements of array a and b: ");
    scanf("%d%d",&n,&m);
    printf("Enter array a:");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter array b:");
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int ans=check2array(a,n,b,m);
    printf("%d",ans);
}
   