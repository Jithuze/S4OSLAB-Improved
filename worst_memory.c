#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;  // Initialize allocation array to -1 (not allocated)
    }
    
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;  // Initialize worstIdx to -1 (invalid index)
        
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    
    printf("\nProcess No.\tProcess Size\tBlock No.\tFragment\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            int fragment = blockSize[allocation[i]];
            printf("%d\t\t%d\n", allocation[i] + 1, fragment);
        } else {
            printf("Not Allocated\tN/A\n");
        }
    }
}

int main() {
    int m, n;
    
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the sizes of memory blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }
    
    worstFit(blockSize, m, processSize, n);
    
    return 0;
}
