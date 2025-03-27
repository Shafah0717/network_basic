#include <stdio.h>   // For input/output functions like printf
#include <unistd.h>  // For the sleep function
#include <stdlib.h>  // For the rand() function (random number generation)

#define BUCKET_CAPACITY 10  // The maximum data capacity the bucket can hold
#define OUTPUT_RATE 5       // The constant output rate (how much data is sent at a time)

int main() {
    int incoming_data = 0;   // To store the random incoming data
    int bucket_level = 0;    // To store the current amount of data in the bucket

    printf("Leaky Bucket Algorithm Simulation\n");

    while (1) {  // Infinite loop to simulate the continuous process
        // Generate random incoming data between 1 and 9
        incoming_data = rand() % 9 + 1;  
        printf("Incoming Data: %d\n", incoming_data);  // Print incoming data

        if ((bucket_level + incoming_data) <= BUCKET_CAPACITY) {  // Check if the bucket has enough space
            // If the bucket can accommodate the incoming data, add it
            bucket_level += incoming_data;
            printf("Bucket Level: %d\n", bucket_level);  // Print the current bucket level
        } else {
            // If the bucket is full, drop the incoming data
            printf("Bucket Overflow! Dropping Data: %d\n", incoming_data);
        }

        // Simulate data being sent out at the defined output rate
        if (bucket_level >= OUTPUT_RATE) {  // Check if there's enough data to send
            bucket_level -= OUTPUT_RATE;  // Send out 5 units of data
            printf("Data Sent: %d\n", OUTPUT_RATE);  // Print how much data was sent
            printf("Bucket Level: %d\n", bucket_level);  // Print the updated bucket level
        } else {
            // If there's less data than the output rate, send all remaining data
            printf("Data sent=%d\n", bucket_level);
            bucket_level = 0;  // Reset bucket level to 0 since all data has been sent
            printf("Bucket Level: %d\n", bucket_level);  // Print the bucket level (which is now 0)
        }

        printf("------------------------\n");  // Separator for better clarity

        sleep(1);  // Wait for 1 second before the next cycle
    }

    return 0;  // End of the main function
}
