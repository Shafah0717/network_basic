#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main() {
    int tf, N, tt = 0;  // tf = total frames, N = window size, tt = total transmissions (sent + resent)
    srand(time(NULL));   // Initialize the random number generator with the current time

    // Input for total frames and window size
    printf("Enter the Total number of frames: ");
    scanf("%d", &tf);
    printf("Enter the Window Size: ");
    scanf("%d", &N);

    int i = 1;  // Start with the first frame
    int k;      // Loop variable for frame sending

    // Main loop to simulate sending and acknowledging frames
    while (i <= tf) {
        int z = 0;  // Count of successfully acknowledged frames in this window

        // Send frames in the current window (from i to i + N)
        for (k = i; k < i + N && k <= tf; k++) {
            printf("Sending Frame %d\n", k);
            tt++;  // Increment total transmission count
        }

        // Acknowledge or retransmit frames in the window
        for (k = i; k < i + N && k <= tf; k++) {
            int f = rand() % 2;  // Generate random number (0 = success, 1 = timeout)

            if (!f) {
                // If the frame is acknowledged (f == 0)
                printf("Acknowledgment for Frame %d\n", k);
                z++;  // Increment the count of successfully acknowledged frames
            } else {
                // If there is a timeout (f == 1)
                printf("Timeout!! Frame Number %d Not Received\n", k);
                printf("Retransmitting Window...\n");
                break;  // Exit the loop and retransmit the window
            }
        }

        printf("\n");
        i = i + z;  // Slide the window forward by the number of acknowledged frames
    }

    // Output the total number of frames sent and resent
    printf("Total number of frames which were sent and resent are: %d\n", tt);

    return 0;  // End of the program
}
