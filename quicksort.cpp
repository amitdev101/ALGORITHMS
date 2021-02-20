// Applying quicksort method
#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int start, int end){
    int i = start+1;
    int piv = A[start];
    
    for(int j = start+1; j<=end ; j++){
        if( A[j]<piv ){
            swap(& A[i], & A[j]);
            i++;
        }
    }
    // swapping pivot to its correct position
    swap(& A[start], & A[i-1]);
    return i-1;

}

void quicksort(int A[], int start, int end){
    if(start < end){
        int piv_pos = partition(A,start,end);
        quicksort(A,start,piv_pos-1);
        quicksort(A,piv_pos+1,end);
    }
}

int main(){
    int n = 10;
    int arr[] = {1,2,3,4,-1,0,99,-666,123,0};
    quicksort(arr,0,n-1);
    for(int i=0; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;

}