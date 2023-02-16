#pragma once //make sure that the file will be included only once
#include<iostream>
#include<cstdlib>
using namespace std;

void print_array(int* A, int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }cout << endl;
}
int* create_random_array(int size) {
    int* A = new int[size];
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 1000;
    }
    return A;
}
int max(int arr[], int size) {
    int Max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > Max) {
            Max = arr[i];
        }
    }
    return Max;
}
int sum(int* A, int size) {
    int Sum = 0;
    for (int i = 0; i < size; i++) {
        Sum = Sum + A[i];
    }
    return Sum;
}
//basic search function
int search(int* A,int size, int value) {
    for (int i = 0; i < size; i++) {
        if (A[i] == value) {

            return i;
        }
    }
    return -1;//returns -1 if value not found

}

//binary search on sorted array
int binary_search(int* A,int size, int key) {
    int low = 0;
    int high = size - 1;
    int pos = -1;


    while (high > low && pos == -1) {
        int mid = (low + high) / 2;
        if (A[mid] == key) {
            pos = mid;
        }
        else if (A[mid] > key) {
            high = mid-1;
        }
        else  {
            low = mid + 1;
        }
    }
    return pos;
}

void exchange_sort(int* A, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (A[i] > A[j]) {
                int temp = A[j];
                A[j] = A[i];//exchange the lower one with bigger value
                A[i] = temp;
            }
        }
    }
}

int* swap(int* arr,int idx_1,int idx_2){
    int tmp = arr[idx_1];
    arr[idx_1] = arr[idx_2];
    arr[idx_2] = tmp;
    return arr;
}

int* bubbleSort(int* arr,int size){
    if(size==1) return arr;
    while(size--){
        for(int i=0;i<size;i++){
            if(arr[i]>arr[i+1]) arr = swap(arr,i,i+1);
        }
    }
    return arr;
}

int* selectionSort(int* arr,int size){
    int min;
    for (int i = 0; i < size-1; ++i) {
        for (int j = i+1; j < size; ++j) {
            min = i;
            if(arr[j]<arr[i]) min = j;
            swap(arr,i,j);
        }
    }
    return arr;
}

int* insertionSort(int* arr,int size){
    for (int i = 0; i < size-1; ++i) {
        if(arr[i+1]<arr[i]){
            int j=0;
            while(arr[i+1-j]<arr[i-j]){
                if((i-j)<0) break;
                swap(arr,i-j,i+1-j);
                j++;
            }
        }
    }
    return arr;
}

int* insertionSort_sir(int* arr,int size){
    for (int i = 0; i < size; ++i) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && i<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr;
}

void merge(int* arr,int left,int mid,int right){
    int tmp_arr_1_size = mid-left+1;
    int tmp_arr_2_size = right-mid;

    int* tmp_arr_1 = new int[tmp_arr_1_size];
    int* tmp_arr_2 = new int[tmp_arr_2_size];

    for (int i = 0; i < tmp_arr_1_size; ++i) {
        tmp_arr_1[i]=arr[left+i];
    }
    for (int i = 0; i < tmp_arr_2_size ; ++i) {
        tmp_arr_2[i]=arr[mid+i];
    }

    int indexOfArrayOne = 0;
    int indexOfArrayTwo = 0;
    int indexOfMergedArray = left;

    while(indexOfArrayOne<tmp_arr_1_size && indexOfArrayTwo < tmp_arr_2_size){
        if(tmp_arr_1[indexOfArrayOne]<tmp_arr_2[indexOfArrayTwo]){
            arr[indexOfMergedArray] = tmp_arr_1[indexOfArrayOne];
            indexOfArrayOne++;
        }
        else{
            arr[indexOfMergedArray] = tmp_arr_2[indexOfArrayTwo];
            indexOfArrayTwo++;
        }
        indexOfMergedArray++;
    }

//    while(indexOfArrayOne < tmp_arr_1_size){
//        arr[indexOfMergedArray] = tmp_arr_1[indexOfArrayOne];
//        indexOfArrayOne++;
//    }
//
//    while(indexOfArrayTwo < tmp_arr_2_size){
//        arr[indexOfMergedArray] = tmp_arr_2[indexOfArrayTwo];
//        indexOfArrayTwo++;
//    }

}

void combine(int* arr1,int* arr2,int size1,int size2,int* arrRes){
    int i=0,j=0;
    int k=0;
//    !((i+1 != size1) && (j+1 != size2))
    while( k!=(size1+size2) ){
        if(arr1[i]>arr2[j]){
            arrRes[k]=arr2[j];
            j++;
        }
        else{
            arrRes[k]=arr1[i];
            i++;
        }
        k++;
    }
}

void mergeSort(int* arr,int left,int right){
    if(right==left){
        return;
    }
    int mid = left + (right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}