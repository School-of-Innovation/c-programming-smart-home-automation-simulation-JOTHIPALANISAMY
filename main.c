#include <stdio.h>

// Function prototypes
void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]);
void toggleLight(int rooms, int lights[]);
void readTemperature(int rooms, int temp[]);
void checkMotionSensor(int rooms, int motion[]);
void lockUnlockSecurity(int rooms, int locks[]);
void houseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]);

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    
    // Arrays to store device states
    int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
    
    // Initialize the system
    initializeSystem(rooms, lights, temp, motion, locks);
    
    int choice;
    do {
        // Display menu
        printf("\n===== Smart Home Menu =====\n");
        printf("1. Toggle Light\n");
        printf("2. Read Temperature\n");
        printf("3. Check Motion Sensor\n");
        printf("4. Lock/Unlock Security System\n");
        printf("5. House Status Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: toggleLight(rooms, lights); break;
            case 2: readTemperature(rooms, temp); break;
            case 3: checkMotionSensor(rooms, motion); break;
            case 4: lockUnlockSecurity(rooms, locks); break;
            case 5: houseStatus(rooms, lights, temp, motion, locks); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[]) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;  // All lights OFF
        temp[i] = 22 + (i % 3);  // Assigning some default temperature values
        motion[i] = 0;  // No motion detected
        locks[i] = 1;  // All doors locked
    }
    printf("Initializing system...\n");
}

void toggleLight(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }
}

void readTemperature(int rooms, int temp[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Temperature in Room %d is %d°C.\n", room, temp[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }
}

void checkMotionSensor(int rooms, int motion[]) {
    int room;
    printf("Enter room number to check motion (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
    } else {
        printf("Invalid room number!\n");
    }
}

void lockUnlockSecurity(int rooms, int locks[]) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
    } else {
        printf("Invalid room number!\n");
    }
}

void houseStatus(int rooms, int lights[], int temp[], int motion[], int locks[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s, %s\n",
               i + 1,
               lights[i] ? "ON" : "OFF",
               temp[i],
               motion[i] ? "Motion Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
