//
// Created by User on 5/27/2025.
//
#include"heap.h"

void heapify(Student arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l].average > arr[largest].average) {
        largest = l;
    }
    if (r < n && arr[r].average > arr[largest].average) {
        largest = r;
    }
    if (largest != i) {
        Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(Student arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        Student temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %.2f\n", arr[i].Neptun,arr[i].average);
    }
    printf("\n");
}