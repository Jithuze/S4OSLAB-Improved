#include <stdio.h>
#include <stdlib.h>

void scan(int arr[20], int n, int start);
void sort(int arr[20],int n);

int diskQueue[20],n,start,i,max,seekTime = 0;

int main()
{
    
    printf("Enter max range: ");
    scanf("%d",&max);
    printf("Enter the size of Queue: ");
    scanf("%d",&n);
    n++;
    printf("Enter the Queue : ");
    for(i=1;i<n;i++){
        scanf("%d",&diskQueue[i]);
    }
    printf("Enter Head : ");
    scanf("%d",&start);
    
    diskQueue[0]=start;
    n++;
    diskQueue[n]=max;
    n++;
    diskQueue[n]=0;
   
    sort(diskQueue,n);
    
    printf("%d\n",n);
    for(i=0;i<n;i++){
        printf("%d ",diskQueue[i]);
    }
    
    scan(diskQueue,n,start);
    
    seekTime += max;
    printf("\nTotal seekTime : %d",seekTime);
    return 0;
}


void scan(int arr[20],int n,int start){
    int pos,diff;
    
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
    for(i=0;i<pos-1;i++){
        
        diff = abs(arr[i+1] - arr[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek time %d.\n",arr[i],arr[i+1],diff);
    }
    
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
