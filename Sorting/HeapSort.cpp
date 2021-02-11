#include <iostream>   
using namespace std; 
  
void heapify(int arr[], int n, int i) 
{ 
    int largest=i; 
    int left=2*i+1; 
    int right=2*i+2; 

    if(right<n && arr[right]>arr[largest]){
        largest=right; 
    }
        
    if(left<n&&arr[left]>arr[largest]){ 
        largest=left;
    }
  
    if(largest!=i){ 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  
void heapSort(int arr[], int n) 
{ 
    for(int i=n/2 -1; i>= 0; i--){
        heapify(arr, n, i); 
    }
  
    for(int i=n-1; i>=0; i--){ 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 
  
void printArray(int arr[], int n) 
{ 
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<" "; 
    }
} 
  
int main() 
{ 
    int n;
    cout<<"Enter size of array";
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    
    heapSort(arr, n); 
    cout << "Heap sorted array: \n"; 
    printArray(arr, n); 

    return 0;
} 

