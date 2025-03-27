#include<stdio.h>
#include<time.h>
#include <stdlib.h>  // For the rand() function (random number generation)

int main() {
    int tf, f, tt = 0; // tf = total frames, f = frame success/failure, tt = total transmission attempts
    srand(time(NULL));  // Initialize the random number generator with the current time
    printf("Enter the Total number of frames: ");
    scanf("%d", &tf);  // Input the total number of frames

    int i = 1;  // Start with the first frame
    while(i <= tf) {
        printf("Sending the frame %d\n", i);
        tt++;  // Increment total transmission attempts
        f = rand() % 2;  // Generate random number (0 or 1) to simulate success or timeout

        if(f == 0) {
            // If the random number is 0, it means acknowledgment is received
            printf("Acknowledgment for frame %d received\n", i);
            i++;  // Move to the next frame
        } else {
            // If the random number is 1, it means timeout occurred (no acknowledgment)
            printf("Timeout for frame number %d. Not received.\n", i);
            printf("Retransmitting frame %d\n", i);  // Retransmit the same frame
        }
    }

    printf("Total number of frames sent and resent: %d\n", tt);  // Print the total number of transmissions (sent + resent)
    return 0;  // End of the program
}
