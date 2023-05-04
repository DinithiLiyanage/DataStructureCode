/*
 * Heap.cpp
 *
 *  Created on: May 4, 2023
 *      Author: Dinithi Liyanage
 */

#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
	int largest;
	int left = 2*root + 1;
	int right = 2*root + 2;
	if( left < n && arr[left] > arr[root]){
		largest = left;
	}
	else{
		largest = root;
	}
	if(right<n && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != root){
		swap(arr[root], arr[largest]);
		heapify(arr, n, largest);
	}

}

void buildHeap(int arr[], int n){
	for(int i = (n-1)/2; i>=0; i--){
		//calling heapify on parent nodes
		heapify(arr, n, i);
	}
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   buildHeap(arr,n);
   cout << "heapified array"<<endl;
   displayArray(arr, n);
   for(int i = n-1; i>=0; i--){
	   //placing root at the end of the array
	   swap(arr[0], arr[i]);
	   n--;
	   //heapifying the remaining array 
	   heapify(arr,n,0);
   	}

   // extracting elements from heap one by one

}



// main program
int main()
{
	//heap with given input
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);

   //heap with user inputs
   int arr[10];
   int num;
   int len = 10;
   for(int i=0; i<10; i++){
	   cout<<"Please enter number: ";
	   cin>>num;
	   arr[i] = num;

   }
   cout<<"Input array"<<endl;
   displayArray(arr,len);

   heapSort(arr, len);

   cout << "Sorted array"<<endl;
   displayArray(arr, len);
}


