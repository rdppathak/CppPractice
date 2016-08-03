#include <stdio.h>
#include <stdlib.h>
// To create executable just type following commands
// gcc RotatedSortedArraySearch.cpp -o RotatedSortedArraySearch

bool search(int arr[], int low, int high, int key){
    if (low>high) return false;

    int mid;
    mid = (low+high)/2;

    if (arr[mid] == key) return true;

    if (arr[low] <= arr[mid]){
        if (key >= arr[low] && key<arr[mid]){
            return search(arr, low, mid-1, key);
        }

        return search(arr, mid+1, high, key);
    }

    if (key>=arr[mid] && key <= arr[high]){
        return search(arr, mid+1, high, key);
    }
    return search(arr, low, mid-1, key);
}

int main(){
    int arr[] = {8, 1, 2, 3, 4, 5, 6, 7};
    int size;
    size = sizeof(arr)/sizeof(arr[0]);
    printf("Length of array: %d\n", size);
    bool result=false;
    int element = 8;
    result = search(arr, 0, size-1, element);
    printf("Status of element[%d] in array[%d]\n", element, result);
    return 0;
}
