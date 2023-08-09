#include <stdio.h>

void fifo(int[],int[],int,int);

int main(){
    int i,p, f, pages[30], frames[20];
    printf("Number of frames : ");
    scanf("%d",&f);
    
    for(i=0;i<f;++i){
        frames[i] = -1;
    }
    
    printf("Number of pages : ");
    scanf("%d",&p);
    
    printf("Enter the reference string \n");
    for(i=0;i<p;++i){
        scanf("%d", &pages[i]);
    }
    
    fifo(pages, frames, p, f);
    
    return 0;
}

void fifo(int pages[], int frames[], int p, int f){
    printf("\nRefStr  |\tFrames\n");
    int i,j,k,flag, faultCount = 0, queue = 0;
    for(i=0;i<p;++i){
        printf("%d\t|\t", pages[i]);
        flag=0;
        for(j=0;j<f;++j){
            if(frames[j] == pages[i]){
                flag = 1;
                printf("\tHit");
                break;
            }
        }
        if(flag == 0) {
            frames[queue] = pages[i];
            faultCount++;
            queue = (queue+1) % f;
            
            for(k=0;k<f;k++){
                printf("%d  ",frames[k]);
            }
        }
        printf("\n\n");
    }
    printf("Total Page Faults = %d\n",faultCount);
}
