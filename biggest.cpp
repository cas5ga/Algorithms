//Caleb A. Street
//First Programming Assignment
//January 27, 2021
//This program accepts 10 integers and returns the largest integer

#include <iostream>
using namespace std;

//Returns the largest integer in the array
int maxValue(int numberList[]){

  //Assigns the first integer in the array to max
  int max = numberList[0];

  //Loops through the list to find the largest number
  for(int i = 1; i < 10; i++){
    if(numberList[i] > max){
      max = numberList[i];
    }
  }

  return max;
}


int main(){

  int numberList[10];
  int number = 0;

  cout<<"Please enter 10 integers (hit enter key after each integer): "<<endl;

  //Gets the 10 integers from user input and stores them in an array
  for(int i = 0; i < 10; i++){
    cout<<">>> ";
    cin>>number;
    numberList[i] = number;
  }

  cout<<"The largest value entered was: "<<maxValue(numberList)<<endl;

  return 0;
}
