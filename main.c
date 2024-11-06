#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Swap(int *arr1, int *arr2){
    
    int tmp = *arr1;
    *arr1 = *arr2;
    *arr2 = tmp;
}
int Partition(int arr[], int start, int stop){
    
    int p = arr[start];
    int i = start;
    int j = stop;
    
    while(i < j){
        
        while(arr[i] <= p && i <= stop - 1){
            
            ++i;
        }
        
        while(arr[j] > p && j >= start + 1){
            
            --j;
        }
        
        if(i < j){
            
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[start], &arr[j]);
    return j;
}
void QuickSort(int start, int stop, int arr[]){
    
    if(start >= stop || start < 0){
        
        return;
    }
    
    int i = start;
    int j = start;

    int p = Partition(arr, start, stop);

    QuickSort(start, p - 1, arr);
    QuickSort(p + 1, stop, arr);
}
int main(){
    
    srand(time(NULL));
    
    const int N = 9;
    
    int arr[N];
    
    for(int i = 0; i < N; ++i){
        
        arr[i] = rand() % 10;
    }
    
    QuickSort(0, N - 1, arr);
    
    for(int i = 0; i < N; ++i){
        
        printf("%d", arr[i]);
    }

    return 0;
}
