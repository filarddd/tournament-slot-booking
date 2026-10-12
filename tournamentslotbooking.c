#include <stdio.h>

int main() {
    int slots [10] = {0};
    int choice, slot, fullyBooked = 0;

    printf("Welcome to the Tournament Slot Booking System!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Book a slot\n");
        printf("2. View available slots\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               printf("Enter the slot number to book (1-10): ");
                scanf("%d", &slot);
                if (slot < 1 || slot > 10) {
                    printf("Invalid slot number! Please try again.\n");
                } else if (slots[slot - 1] == 1) {
                    printf("Slot %d is already booked! Please choose another slot.\n", slot);
                } else {
                    slots[slot - 1] = 1;
                    printf("Slot %d has been successfully booked!\n", slot);
                }
                break;
            case 2:
                printf("Available slots:\n");
                for (int i = 0; i < 10; i++) {
                    if (slots[i] == 0) {
                        printf("Slot %d is available\n", i + 1);
                    }
                    if (slots[i] == 1) {
                        printf("Slot %d is booked\n", i + 1);
                    }
                }
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n\n");
                printf("Final slot status:\n");
                for (int i = 0; i < 10; i++) {
                    if (slots[i] == 1) {
                        printf("Slot %d is booked\n", i + 1);
                    } else {
                        printf("Slot %d is available\n", i + 1);
                    }
                }
                fullyBooked = 1;
                for (int i = 0; i < 10; i++) {
                    if (slots[i] == 0) {
                        fullyBooked = 0;
                        break;
                    }
                }
                if (fullyBooked) {
                    printf("All slots are fully booked!\n");
                }
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}