#include<stdio.h>
#include<string.h>

//1. linear, sentinel, binary searches
//calculate the element comparisons, index comparisons for linear search, sentinel and binary search

//2. bubble and insertion sorting
//Compute the total number of comparisons, data transfer operations for each sort

//Search for any two data types

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void linearSearch(int arr[], int target, int n);
void sentinelSearch(int arr[], int target, int n);
int binarySearch(int arr[], int target, int n);
int display(int arr[], int n);

int main() {
    int choice;
    int n, target, result;
    
    printf("Enter the number of players: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the runs scored by each player:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Linear Search\n");
        printf("4. Sentinel Search\n");
        printf("5. Binary Search\n");
        printf("6. Display Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &target);
                linearSearch(arr, target, n);
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &target);
                sentinelSearch(arr, target, n);
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &target);
                result = binarySearch(arr, target, n);
                if (result != -1) {
                    printf("Element found at position %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 6:
                display(arr, n);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}


void bubbleSort(int arr[], int n){
	
	int i, j, temp;
	int compare = 0, data_trans = 0;
	
	for (i = 0; i < n-1; i++){
		compare++;
		// Last i elements are already in place
		for (j = 0; j < n-i-1; j++){
			compare ++;
			
			if (arr[j] > arr[j+1]){
				//swaping
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
				printf("\n%d", arr[j]);
				printf("\tswapped with %d", arr[j+1]);
				compare ++;
				data_trans += 3;
			}
		}
	}
	printf("\nSorted arry using bubble sort = ");
	for(i=0; i<n; i++){
		printf("%d \t", arr[i]);
	}
	
	printf("\nTotal number of comparision in bubble sort are %d", compare);
	printf("\nTotal number of data transfer operations are %d", data_trans);
}

int display(int arr[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}

void insertionSort(int arr[],int n){
	int i,j;
	int compare = 0, data_trans = 0;
	
	for(j=1; j<n; j++){
		compare++;
		
		int key = arr[j];
		i = j-1;
		data_trans += 2;
		
		while(i>=0 && arr[i]>key){
			compare++;
			arr[i+1] = arr[i];
			i = i-1;
			data_trans += 2;
		}
		arr[i+1] = key;
		data_trans++;
	}
	
	for(i=0; i<n; i++){
		printf("%d\t", arr[i]);
	}
	
	printf("\nTotal number of comparision in insertion sort are %d", compare);
	printf("\nTotal number of data transfer operations are %d", data_trans);
}

void linearSearch(int arr[], int target, int n){
	int i;
	
	for(i=0; i<n; i++){
		if (target == arr[i]){
			printf("The element is fount at position %d.", i+1);
		}
	}printf("!!Element not found!!");
	
//	while(target != arr[i]){
//		i ++;
//	}
//	printf("The element is fount at position %d.", i+1);
}

void sentinelSearch(int arr[], int target, int n){
    int i = 0;
    arr[n] = target;

    while (arr[i] != target) {
        i++;
    }

    if (i < n) {
        printf("Element found at position %d\n", i + 1);
    } else {
        printf("Element not found\n");
    }
}

int binarySearch(int arr[], int target, int n){
	
	int low = 1, high = n;
	
	while(low <= high){
		int mid = ((low + high)/2);
		
		if(target < arr[mid-1]){
			high = mid - 1;
		}
		else if(target > arr[mid-1]){
			low = mid +1;	
		}
		else {
			return mid;
		}
	}
}









