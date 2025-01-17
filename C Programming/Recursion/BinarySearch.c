#include<stdio.h>
int bins(int a[10],int left,int right, int key) {
    int mid;
    while(left<=right) {
            mid=(left+right)/2;
            if(a[mid]==key)
            return 1;
            else if(a[mid]>key) 
            bins(a,left,mid,key);
            else 
             bins(a,mid+1,right,key);
             
    }
    return 0;
}
void main() {
    int a[10],n,i,key,j;
    printf("enter the no.of terms");
    scanf("%d",&n);
    printf("Enter the elements");
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched");
    scanf("%d",&key);
    j=bins(a,0,n-1,key);
    if(j==1) 
    printf("Item found");
    else 
    printf("not found");
}