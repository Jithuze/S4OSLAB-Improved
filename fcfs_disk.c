#include<stdio.h>
#include<stdlib.h>

int main(){
    int diskQueue[20],n,i,head,seekTime = 0,diff;
    printf("Enter the size of queue : ");
    scanf("%d",&n);
    n++;
    printf("Enter the Queue : ");
    for(i=1;i<n;i++){
        scanf("%d",&diskQueue[i]);
    }
    
    printf("Enter Head : ");
    scanf("%d",&head);
    
    diskQueue[0]=head;
    
    for(i=0;i<n-1;i++){
        diff = abs(diskQueue[i+1] - diskQueue[i]);
        seekTime += diff;
        printf("Move from %d to %d with seek %d \n",diskQueue[i],diskQueue[i+1],diff);
    }
    
    printf("Total SeekTime : %d\n",seekTime);
}
