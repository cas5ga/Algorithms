//Caleb A. Street
//Algorithms
//March 8, 2021
//Implements MergeSort and QuickSort
//Tracks wich sorting algorithm is faster

#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

/*The merge and mergeSort functions listed below are not my own work
These two functions are from the GeeksforGeeks website.  This website
can be found at: geeksforgeeks.org/merge-sort/ */

//Merges two subarrays of arr[].
//First subarray is arr[l..m]
//Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r){
  int n1 = m - l + 1;
  int n2 = r - m;

  //Create temp arrays
  int L[n1], R[n2];

  //Copy data to temp arrays L[] and R[]
  for(int i = 0; i < n1; i++){
    L[i] = arr[l + i];
  }
  for(int j = 0; j < n2; j++){
    R[j] = arr[m + 1 + j];
  }

  //Merge the temp arrays back into arr[l..r]

  //Initial index of first subarray
  int i = 0;

  //Initial index of second subarray
  int j = 0;

  //Initial index of the merged subarray
  int k = l;

  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }
    else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  //Copy the remaining elements of
  //L[], if there are any
  while(i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  //Copy the remaining elements of
  //R[], if there are any
  while(j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}


//l is for left index and r is
//right index of the sub-array
//of arr to be sorted
void mergeSort(int arr[], int l, int r){
  if(l >= r){
    return; //returns recursively
  }
  int m = l + (r-l)/2;
  mergeSort(arr, l, m);
  mergeSort(arr, m+1, r);
  merge(arr, l, m, r);
}


/*The swap, partition, and quickSort functions listed below are not my own work.
These three functions are from the GeeksforGeeks website.  This website
can be found at: geeksforgeeks.ort/cpp-program-for-quicksort/ */


//A utility function to swap two elements
void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}


/*This function takes last element as pivot, places
  the pivot element at its correct position in sorted
  array, and places all smaller (smaller than pivot)
  to left or pivot and all greater elements to right
  of pivot */
int partition(int arr[], int low, int high){
  int pivot = arr[high]; //pivot
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++){
    //If current element is smaller than or equal to pivot
    if(arr[j] <= pivot){
      i++; //increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], & arr[high]);
  return (i + 1);
}


/*The main function that implements QucikSort
  arr[] --> Array to be sorted
  low --> Starting index
  high --> Ending index */
void quickSort(int arr[], int low, int high){
  if(low < high){
    /*pi is partioning index, arr[p] is now
      at right place */
    int pi = partition(arr, low, high);

    //Separately sort elements before
    //partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

//This function generates random numbers from 1 to 1000
int randomNumber(){
  clock_t time = clock();
  srand(time);
  int number = ((rand() % 1000) + 1);
  return number;
}


int main(){
  int rows = 100;
  int columns = 1000;
  
  int array[rows][columns];
  int arrayCopy[rows][columns];
  int number;

  //Creates a 2D array of size rows x columns
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      number = randomNumber();
      array[i][j] = number;
      //Cout statement slows the program down to prevent
      //duplicate random numbers since this program is using
      //time to generate random numbers.
      cout<<endl;
    }
  }

  //Makes a copy of the previous array
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      arrayCopy[i][j] = array[i][j];
    }
  }
  

  //Sorts each of the arrays using mergeSort
  cout<<"Sorting the arrays with mergeSort"<<endl;
  clock_t startTime = clock();
  for(int i = 0; i < rows; i++){
    mergeSort(array[i], 0, columns-1);
    cout<<"Sorted array #"<<i+1<<endl;
  }
  clock_t finishTime = clock();
  clock_t totalTimeMergeSort = finishTime - startTime;
  
  cout<<endl;

  //Sorts each of the arrays using quickSort
  cout<<"Sorting the arrays with quickSort"<<endl;
  startTime = clock();
  for(int i = 0; i < rows; i++){
    quickSort(arrayCopy[i], 0, columns-1);
    cout<<"Sorted array #"<<i+1<<endl;
  }
  finishTime = clock();
  clock_t totalTimeQuickSort = finishTime - startTime;
  
  cout<<endl;

  cout<<"The average sorting time with mergeSort was: "<<(totalTimeMergeSort/rows)<<" clicks"<<endl<<endl;
  cout<<"The average sorting time with quickSort was: "<<(totalTimeQuickSort/rows)<<" clicks"<<endl<<endl;
  
  return 0;
}
