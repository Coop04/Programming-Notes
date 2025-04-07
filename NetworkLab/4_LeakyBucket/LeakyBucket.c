#include <stdio.h> 
 
int main() { 
    int bucket_size, outgoing_rate, num_packets, incoming_packet, buffer = 0; 
 
    printf("Enter the bucket size (Bytes): "); 
    scanf("%d", &bucket_size); 
    printf("Enter the outgoing rate (Bytes per second): "); 
    scanf("%d", &outgoing_rate); 
    printf("Enter the no of packets: "); 
    scanf("%d", &num_packets); 
 
    for (int i = 0; i < num_packets; i++) { 
        printf("Enter the incoming packet size (Bytes): "); 
        scanf("%d", &incoming_packet); 
 
        if (buffer + incoming_packet > bucket_size) { 
            int dropped = (buffer + incoming_packet) - bucket_size; 
            printf("Dropped %d bytes of data from packet\n", dropped); 
            buffer = bucket_size;  
        } else { 
            buffer += incoming_packet; 
        } 
 
        printf("Current Bucket buffer size %d out of %d\n", buffer, bucket_size); 
 
         
        if (buffer >= outgoing_rate) { 
            buffer -= outgoing_rate; 
            printf("After outgoing %d bytes left out of %d in buffer\n", buffer, bucket_size); 
        } else { 
            printf("After outgoing 0 bytes left out of %d in buffer\n", bucket_size); 
            buffer = 0; 
        } 
    } 
 
    return 0; 
}