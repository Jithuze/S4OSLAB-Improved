#include <stdio.h>

void main() {
    int frames[20], pages[50], pageFaults = 0, count1, numFrames, i, j, k = 0, numPages, replacementPos, temp, counters[20], freqCounters[20];

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    printf("Enter the reference string: ");
    for (i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    for (i = 0; i < numFrames; i++) {
        frames[i] = -1;  // Initialize frames with -1 (no page loaded yet)
    }

    for (i = 0; i < numPages; i++) {
        count1 = 0;

        for (j = 0; j < numFrames; j++) {
            if (pages[i] != frames[j]) {
                count1++;
            }
        }

        if (count1 == numFrames) {
            pageFaults++;

            if (k < numFrames) {
                frames[k] = pages[i];
                k++;

                for (j = 0; j < k; j++) {
                    printf("\t%d", frames[j]);
                }

                printf("\n");
            } else {
                for (replacementPos = 0; replacementPos < numFrames; replacementPos++) {
                    counters[replacementPos] = 0;

                    for (j = i - 1; j >= 0; j--) {
                        if (frames[replacementPos] != pages[j]) {
                            counters[replacementPos]++;
                        } else {
                            break;
                        }
                    }
                }

                for (replacementPos = 0; replacementPos < numFrames; replacementPos++) {
                    freqCounters[replacementPos] = counters[replacementPos];
                }

                for (replacementPos = 0; replacementPos < numFrames; replacementPos++) {
                    for (j = replacementPos + 1; j < numFrames; j++) {
                        if (freqCounters[replacementPos] < freqCounters[j]) {
                            temp = freqCounters[replacementPos];
                            freqCounters[replacementPos] = freqCounters[j];
                            freqCounters[j] = temp;
                        }
                    }
                }

                for (replacementPos = 0; replacementPos < numFrames; replacementPos++) {
                    if (counters[replacementPos] == freqCounters[0]) {
                        frames[replacementPos] = pages[i];
                    }

                    printf("\t%d", frames[replacementPos]);
                }

                printf("\n");
            }
        }
    }

    printf("\nThe number of page faults is %d", pageFaults);
}
