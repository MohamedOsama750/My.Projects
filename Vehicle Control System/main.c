#include <stdio.h>

// Function to set vehicle speed based on traffic light data
void setVehicleSpeed(char trafficLight, int *vehicleSpeed) {
    switch (trafficLight) {
        case 'G':
            *vehicleSpeed = 100;
            break;
        case 'O':
            *vehicleSpeed = 30;
            break;
        case 'R':
            *vehicleSpeed = 0;
            break;
        default:
            printf("Invalid traffic light color.\n");
    }
}

// Function to set room temperature and AC state
void setRoomTemperature(int roomTemperature, int *acState, int *engineTemperatureControllerState) {
    if (roomTemperature < 10 || roomTemperature > 30) {
        *acState = 1;
        roomTemperature = 20;
    } else {
        *acState = 0;
    }
}

// Function to set engine temperature and Engine Temperature Controller state
void setEngineTemperature(int engineTemperature, int *engineTemperatureControllerState) {
    if (engineTemperature < 100 || engineTemperature > 150) {
        *engineTemperatureControllerState = 1;
        engineTemperature = 125;
    } else {
        *engineTemperatureControllerState = 0;
    }
}

int main() {
    int engineState = 0; // 0 is OFF, 1 is ON
    int acState = 0;     // 0 is OFF, 1 is ON
    int vehicleSpeed = 0;
    int roomTemperature = 20;
    int engineTemperatureControllerState = 0; // 0 is OFF, 1 is ON
    int engineTemperature = 125;

    char choice;

    do {
        printf("Vehicle Control System Menu:\n");
        printf("a. Turn on the vehicle engine\n");
        printf("b. Turn off the vehicle engine\n");
        printf("c. Quit the system\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            engineState = 1;
            char sensorsChoice;

            while (engineState) {
                printf("Sensors Set Menu:\n");
                printf("a. Turn off the engine\n");
                printf("b. Set traffic light color\n");
                printf("c. Set room temperature\n");
                printf("d. Set engine temperature\n");
                printf("Enter your choice: ");
                scanf(" %c", &sensorsChoice);

        char trafficLight;
                switch (sensorsChoice) {
                    case 'a':
                        engineState = 0;
                        break;
                    case 'b':
                        printf("Enter traffic light color (G, O, R): ");
                        scanf(" %c", &trafficLight);
                        setVehicleSpeed(trafficLight, &vehicleSpeed);
                        break;
                    case 'c':
                        printf("Enter room temperature: ");
                        scanf("%d", &roomTemperature);
                        setRoomTemperature(roomTemperature, &acState, &engineTemperatureControllerState);
                        break;
                    case 'd':
                        printf("Enter engine temperature: ");
                        scanf("%d", &engineTemperature);
                        setEngineTemperature(engineTemperature, &engineTemperatureControllerState);
                        break;
                    default:
                        printf("Invalid choice.\n");
                }

                printf("Current Vehicle State:\n");
                printf("Engine state: %s\n", engineState ? "ON" : "OFF");
                printf("AC: %s\n", acState ? "ON" : "OFF");
                printf("Vehicle Speed: %d km/hr\n", vehicleSpeed);
                printf("Room Temperature: %d\n", roomTemperature);
                printf("Engine Temperature Controller State: %s\n", engineTemperatureControllerState ? "ON" : "OFF");
                printf("Engine Temperature: %d\n", engineTemperature);
            }
        } else if (choice == 'b') {
            engineState = 0;
        } else if (choice == 'c') {
            printf("Exiting the system.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("Current Vehicle State:\n");
        printf("Engine state: %s\n", engineState ? "ON" : "OFF");
        printf("AC: %s\n", acState ? "ON" : "OFF");
        printf("Vehicle Speed: %d km/hr\n", vehicleSpeed);
        printf("Room Temperature: %d\n", roomTemperature);
        printf("Engine Temperature Controller State: %s\n", engineTemperatureControllerState ? "ON" : "OFF");
        printf("Engine Temperature: %d\n", engineTemperature);
    } while (1);

    return 0;
}
