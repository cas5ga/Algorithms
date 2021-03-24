//Caleb A. Street
//Algorithms
//March 24, 2021
//Implements heapSort
//Part of this code was obtained from the class server

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void display(int *ar, int size)
{
   for(int i = 1; i<size; i++)
      cout << ar[i] << " ";
   cout << endl;
}

//Creates a heap from an array
void heapify(int *ar, int size){
  bool flag = true;
  while(flag){
    flag = false;
    for(int i = size-1; i > 1; i--){
      if(ar[i] > ar[(int) floor(i/2)]){
	swap(ar[i], ar[(int) floor(i/2)]);
	flag = true;
      }
    }
  }
}

//Sorts an array by heapSort
void heapSort(int *ar, int size){
  int length = size;
  int counter = 0;
  for(int i = 1; i < size-1; i++){
    heapify(ar, length-counter);
    counter++;
    swap(ar[1], ar[length-counter]);
  }
}

int main()
{
  int value;
  vector<int> listOfValues;
  listOfValues.push_back(100);
  
  cout<<"Please enter the first integer value: ";
  cin>>value;

  //Input Validataion
  while(!value){
    cout<<"Sorry. Please enter an integer value: ";
    cin.clear();
    cin.ignore();
    cin>>value;
  }

  //Used vectors for easily dynamic size
  while(value != -999){
    listOfValues.push_back(value);
    
    cout<<"Please enter the next integer value (-999 to quit): ";
    cin>>value;

    //Input Validation
    while(!value){
      cout<<"Sorry. Please enter an integer value (-999 to quit): ";
      cin.clear();
      cin.ignore();
      cin>>value;
    }
  }
  cout<<endl;

  int length = listOfValues.size();
  int array[length];
  for(int i = 0; i < length; i++){
    array[i] = listOfValues[i];
  }

  cout<<"Array before sorting: ";
  display(array, length);
  
  heapSort(array, length);

  cout<<"\nArray after sorting: ";
  display(array, length);
  
  return 0;
}
