//
//  main.cpp
//  SortsSortsSorts
//
//  Created by Brandon Jonas on 2/21/14.
//  Copyright (c) 2014 Brandon Jonas. All rights reserved.
//

#include <iostream>

using namespace std;

void bubble(int arr[], int left, int right);

void selection(int arr[], int left, int right);
void selectionAdd(int a[], int left, int right);

void insertion(int a[], int left, int right);
void insertionAdd(int a[], int left, int right);

void quicksort(int a[], int left, int right);

void fixUp(int *heap, int k);
void fixDown(int *heap, int heapsize, int k);
void heapsort(int *heap, int heapsize);

void merge(int* arr, int left, int mid, int right);
void mergesort(int *a, int left, int right);



int main()
{

    int arr[5]= {4, 13, 1, 2, 28};
    
    int heap[9] = {81, 18, 14, 9, 7, 1, 5, 2, 4};
    
    
    //bubble(arr, 0, 4);
    
    //selection(arr, 0, 4);
    
    //selectionAdd(arr, 0, 4);
    
    //insertion(arr, 0, 4);
    
    //insertionAdd(arr, 0, 4);
    
    //quicksort(arr, 0, 4);
    
    //heapsort(heap, 9);
    
    mergesort(arr, 0, 4);
    
    return 0;
}

void bubble(int arr[], int left, int right) {
    int temp;
    
    
    for (int i = left; i < right; i++){
        for (int j = right; j > i; j--){
            if (arr[j] < arr [j - 1])
			{
				temp = arr[j-1];
				arr[j-1] = arr [j];
				arr[j] = temp;
                
                for (int i = 0; i<right+1; ++i) {
                    cout<<arr[i] << " ";
                }
                cout<< "\n";
			}
        }
    }
    
    for (int i = 0; i<right+1; ++i) {
        cout<<arr[i] << " ";
    }
   
    
}

void selection(int arr[], int left, int right) {
    
    for (int i = left; i < right; i++) {
        int min = i;
        for (int j = i+1; j <= right; j++)
            if (arr[j] < arr[min])
                min = j;
        swap(arr[i], arr[min]);
        
        
        for (int i = 0; i<right+1; ++i) {
            cout<<arr[i] << " ";
        }
        cout<< "\n";
        
    }
    
    for (int i = 0; i<right+1; ++i) {
        cout<<arr[i] << " ";
    }
}

void selectionAdd(int a[], int left, int right) {
    for (int i = left; i < right; i++) {
        int min = i;
        for (int j = i+1; j <= right; j++){
            if (a[j] < a[min])
                min = j;
        }
        
        if (min != i){
            swap(a[i], a[min]);
        }
        
        for (int i = 0; i<right+1; ++i) {
            cout<<a[i] << " ";
        }
        cout<< "\n";
    }
    
    for (int i = 0; i<right+1; ++i) {
        cout<<a[i] << " ";
    }
}

void insertion(int a[], int left, int right) {
    int temp;
    
    for (int i = left + 1; i <= right; i++){
        for (int j = i; j > left; j--){
            if (a[j] < a [j - 1])
			{
				temp = a[j-1];
				a[j-1] = a [j];
				a[j] = temp;
                
                for (int i = 0; i<right+1; ++i) {
                    cout<<a[i] << " ";
                }
                cout<< "\n";
			}
        }
    }
}

void insertionAdd(int a[], int left, int right) {
    int i;
    int temp;
    
    for (i = right; i > left; i--){
        if (a[i] < a [i - 1])
        {
            temp = a[i-1];
            a[i-1] = a [i];
            a[i] = temp;
            
        }
    }
    for (int i = left+2; i <= right; i++) {
        int j=i;
        int v=a[i];
        while (v < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
    
    for (int i = 0; i<right+1; ++i) {
        cout<<a[i] << " ";
    }
}

void quicksort(int a[], int left, int right){
    
    int lhs= left;
    int rhs = right;
    char pivot = a[(left+right)/2];
    char tmp;
    
    while(lhs <= rhs){
        while (a[lhs] < pivot) {
            lhs++;
        }
        
        while (a[rhs] >= pivot) {
            rhs--;
        }
        
        if (lhs <= rhs) {
            tmp = a[lhs];
            a[lhs] = a[rhs];
            a[lhs] = tmp;
            
            lhs++;
            rhs--;
        }
        
    }
    
    if (left<rhs) {
        quicksort(a, left, rhs);
    }
    
    if (lhs< right) {
        quicksort(a, lhs, right);
    }
    
    
}

void fixUp(int *heap, int k){
    int temp;
    
    while (k>1 && heap[k/2]>heap[k]) {
        temp = heap[k/2];
        heap[k/2] = heap[k];
        heap[k/2] = temp;
        
        k=k/2;
    }
}

void fixDown(int *heap, int heapsize, int k){
    while (2*k > heapsize) {
        int j = 2*k;
        
        if(j < heapsize && heap[j] < heap[j+1]){
            j++;
        }
        if (heap[k] >= heap[j]) {
            break;
        }
        
        swap(heap[k], heap[j]);
        k=j;
    }
}

void heapsort(int *heap, int heapsize){
    
    for (int i = heapsize; i >= 2; i--) {
        swap(heap[i], heap[1]);
        fixDown(heap, i-1, 1);
        
    }
    
}

void mergesort(int *a, int left, int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left, mid, right);
    }
}

void merge(int* arr, int left, int mid, int right)
{
    int i1 = 0;
    int i2 = left;
    int i3 = mid + 1;
    
    int temp[right-left+1];
    
    while ( i2 <= mid && i3 <= right )
        if ( arr[i2] < arr[i3] )
            temp[i1++] = arr[i2++];
        else
            temp[i1++] = arr[i3++];
    
    while ( i2 <= mid )
        temp[i1++] = arr[i2++];
    
    while ( i3 <= right )
        temp[i1++] = arr[i3++];
    
    for ( int i = left; i <= right; i++ )
        arr[i] = temp[i-left];
}




