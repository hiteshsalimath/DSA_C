#include <stdio.h>
#include <stdlib.h>

// Structure to represent cricket data
struct CricketPlayer {
    int id;
    char playerName[50];
    int runsScored;
};

// Function prototypes
void quickSort(struct CricketPlayer arr[], int low, int high, int *compCount, int *swapCount);
int partition(struct CricketPlayer arr[], int low, int high, int *compCount, int *swapCount);
void selectionSort(struct CricketPlayer arr[], int n, int *compCount, int *swapCount);
void generateRandomData(struct CricketPlayer arr[], int size);
void printData(struct CricketPlayer arr[], int size);
void readFile(struct CricketPlayer arr[], int *size);
void writeFile(struct CricketPlayer arr[], int size, char *filename);

int main() {
    int size = 10; // Initial size for random data
    char filename[] = "cricket_data.txt";

    // Generate random data
    printf("Generating Random Data...\n");
    struct CricketPlayer arr[size];
    generateRandomData(arr, size);

    // Display unsorted data
    printf("Unsorted Data:\n");
    printData(arr, size);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Quick Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int compCount = 0;
        int swapCount = 0;

        switch (choice) {
            case 1:
                quickSort(arr, 0, size - 1, &compCount, &swapCount);
                printf("Quick Sort Results:\n");
                break;
            case 2:
                selectionSort(arr, size, &compCount, &swapCount);
                printf("Selection Sort Results:\n");
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        // Display sorted data
        printf("Sorted Data:\n");
        printData(arr, size);

        printf("Comparisons: %d\n", compCount);
        printf("Data Transfers: %d\n", swapCount);

        // Write sorted data back to the file
        writeFile(arr, size, filename);

    } while (choice != 3);

    return 0;
}

void quickSort(struct CricketPlayer arr[], int low, int high, int *compCount, int *swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, compCount, swapCount);

        quickSort(arr, low, pi - 1, compCount, swapCount);
        quickSort(arr, pi + 1, high, compCount, swapCount);
    }
}

int partition(struct CricketPlayer arr[], int low, int high, int *compCount, int *swapCount) {
    struct CricketPlayer pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*compCount)++;
        if (arr[j].runsScored <= pivot.runsScored) {
            i++;
            // Swap arr[i] and arr[j]
            struct CricketPlayer temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*swapCount)++;
        }
    }

    // Swap arr[i + 1] and arr[high] (pivot)
    struct CricketPlayer temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*swapCount)++;

    return i + 1;
}

void generateRandomData(struct CricketPlayer arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i].id = i + 1;  // Unique ID for each player
        sprintf(arr[i].playerName, "Player%d", i + 1);  // Player name
        arr[i].runsScored = rand() % 1000 + 1;  // Random runs between 1 and 1000
    }
}

void printData(struct CricketPlayer arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Player Name: %s, Runs Scored: %d\n", arr[i].id, arr[i].playerName, arr[i].runsScored);
    }
}

void selectionSort(struct CricketPlayer arr[], int n, int *compCount, int *swapCount) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*compCount)++;
            if (arr[j].runsScored < arr[min_idx].runsScored) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        struct CricketPlayer temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        (*swapCount)++;
    }
}

void readFile(struct CricketPlayer arr[], int *size, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the size of the array
    fscanf(file, "%d", size);

    // Read data into the array
    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d %s %d", &arr[i].id, arr[i].playerName, &arr[i].runsScored);
    }

    fclose(file);
}

void writeFile(struct CricketPlayer arr[], int size, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write the size of the array
    fprintf(file, "%d\n", size);

    // Write data from the array to the file
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d %s %d\n", arr[i].id, arr[i].playerName, arr[i].runsScored);
    }

    fclose(file);
}

