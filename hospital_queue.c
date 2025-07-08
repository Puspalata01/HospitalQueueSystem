#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    char problem[100];
} Patient;

Patient queue[MAX];
int front = -1, rear = -1;

// Function to add patient
void addPatient() {
    if (rear == MAX - 1) {
        printf("Queue is full. Cannot add more patients.\n");
        return;
    }

    Patient p;
    printf("Enter patient name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter patient age: ");
    scanf("%d", &p.age);
    printf("Enter problem description: ");
    scanf(" %[^\n]", p.problem);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = p;

    printf("Patient added successfully.\n");
}

// Function to show current patient
void showCurrentPatient() {
    if (front == -1 || front > rear) {
        printf("No patients in queue.\n");
        return;
    }

    Patient p = queue[front];
    printf("\nCurrently treating:\n");
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Problem: %s\n", p.problem);
}

// Function to show waiting list
void showWaitingList() {
    if (front == -1 || front > rear) {
        printf("No patients in waiting list.\n");
        return;
    }

    printf("\nWaiting List:\n");
    for (int i = front + 1; i <= rear; i++) {
        printf("%d. %s, Age: %d, Problem: %s\n", i - front, queue[i].name, queue[i].age, queue[i].problem);
    }
}

// Function to serve next patient
void serveNextPatient() {
    if (front == -1 || front > rear) {
        printf("No patients to serve.\n");
        return;
    }

    printf("Patient %s has been treated.\n", queue[front].name);
    front++;
    if (front > rear) {
        front = rear = -1; // Reset queue when empty
    }
}

// Function to estimate waiting time
void estimateWaitingTime() {
    if (front == -1 || front > rear) {
        printf("No patients in queue.\n");
        return;
    }

    int num_patients = rear - front + 1;
    int avg_time = 10; // Assume 10 minutes per patient
    printf("Estimated waiting time: %d minutes.\n", (num_patients - 1) * avg_time);
}

int main() {
    int choice;

    do {
        printf("\n------ Hospital Queue Management ------\n");
        printf("1. Add Patient\n");
        printf("2. Show Current Patient\n");
        printf("3. Show Waiting List\n");
        printf("4. Serve Next Patient\n");
        printf("5. Estimate Waiting Time\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                showCurrentPatient();
                break;
            case 3:
                showWaitingList();
                break;
            case 4:
                serveNextPatient();
                break;
            case 5:
                estimateWaitingTime();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
