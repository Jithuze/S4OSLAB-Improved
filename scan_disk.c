/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void scan(int arr[20], int n, int start);
void sort(int arr[20],int n);


int main()
{
    int diskQueue[20],n,start,i;
    printf("Enter the size of Queue: ");
    scanf("%d",&n);
    printf("Enter the Queue : ");
    for(i=1;i<=n;i++){
        scanf("%d",&diskQueue[i]);
    }
    printf("Enter Head : ");
    scanf("%d",&start);
    
    diskQueue[0]=start;
    ++n;
    sort(diskQueue,n);
    scan(diskQueue,n,start);
    return 0;
}


void scan(int arr[20],int n,int start){
    int i,pos,diff,seekTime=0,current;
    
    for(i=0;i<n;i++) {
        if(arr[i]==start) {
            pos=i;
            break;
        }
    }
    
    printf("\nMovement of Cylinders\n");
    for(i=pos;i<n-1;i++){
        diff = abs(arr[i+1] - arr[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d.\n",arr[i],arr[i+1],diff);
    }
    current=i;
    for(i=pos-1;i>=0;i--){
        
        diff = abs(arr[current] - arr[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d.\n",arr[current],arr[i],diff);
        current = i;
    }
    
    printf("\nTotal seekTime : %d",seekTime);
}

void sort(int arr[20],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
