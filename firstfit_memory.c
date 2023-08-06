#include<stdio.h>

int main(){
    int i,j,block_no,block_size[10],process_no,process_size[10];
    
    printf("Enter no of free blocks :\t");
    scanf("%d",&block_no);
    
    printf("Enter the size of free blocks :\n");
    for(i=0;i<block_no;i++){
        scanf("%d",&block_size[i]);
    }
    
    printf("Enter no of processes :\t");
    scanf("%d",&process_no);
    
    printf("Enter size of processes : \n");
    for(i=0;i<process_no;i++){
        scanf("%d",&process_size[i]);
    }
    
    printf("\tFIRST FIT\n");
    
    for(i=0;i<block_no;i++){
        printf("size of free block %d: %d\n",i+1,block_size[i]);
    }
    printf("\n\n");
    for(i=0;i<process_no;i++){
        printf("size of process %d: %d\n",i+1,process_size[i]);
    }
    printf("\n");
  
    printf("PNo\tAllocBlock\tAllocSize\tFragInBlock\n");
    
    i=0;
    while(i<process_no){
        for(j=0;j<block_no;j++){
            if(process_size[i]<=block_size[j]){  //if process size is less then block size ,allocate it 
                block_size[j] -= process_size[i];
                break;
            }
        }
        
        printf("%d\t%d\t\t%d\t\t%d\n",i+1,j+1,process_size[i],block_size[j]);
        i++;
    }
    return 0;
}
