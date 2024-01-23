#include<stdio.h>
#include<string.h>
#include<stdlib.h>




void quicksort(int a[25],int first, int last);
void initRandArr(int a[], int n);
void displayArray(int a[], int n);



int main(){
	int n = 5;
	int a[n];
	initRandArr(a, n);
	int first = 0;
	int last = n-1;
	displayArray(a,last);
	
	quicksort(a,first,last);
	displayArray(a,last);
}

void quicksort(int a[25],int first, int last){
	int temp;
	
	if(first<last){
		int pivot=first;
		int i=first;
		int j=last;
		
		while(i<j){
			
			while(a[i]<=a[pivot] && i<last){
			i++;
			}
			
			while(a[j] > a[pivot]){
			j--;
			}
			
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,first,j-1);
		quicksort(a,j+1,last);
	}
}

void initRandArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; // Adjustment of the range
    }
}

void displayArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d \t", a[i]);
    }
    printf("\n");
}


