//Caleb A. Streetd
//First Programming Assignment - Addendum 1
//February 1, 2021
//This program accepts 10 integers and returns the largest integer

//The basic operation of this algorithm is a comparision (greater than comparison)

#include <iostream>
using namespace std;


int main(){

  int numberList[10];
  int number = 0;
  int max = 0;
  int count = 0;

  //Adds blank space to clear the screen
  for(int i = 0; i < 100; i++){
    cout<<"\n";
  }
  
  cout<<"Please enter 10 integers (hit enter key after each integer): "<<endl<<endl;

  //Gets the 10 integers from user input and stores them in an array
  for(int i = 0; i < 10; i++){
    cout<<"Integer "<<i+1<<": ";
    cin>>number;
    //Input Validation
    //Works with characters, but not with doubles (floating point number)
    //System will take numbers before the '.' as one integer, and the numbers
    //after the '.' as another integer (skips one input)
    while(!number){
      cout<<endl<<"Sorry.  Please enter an integer."<<endl;
      cout<<"Integer "<<i+1<<": ";
      cin.clear();
      cin.ignore();
      cin>>number;
      cout<<'\n';
    }
    numberList[i] = number;
  }

  //Loops through the list to find the largest number
  for(int i = 1; i < 10; i++){
    if(numberList[i] > max){
      max = numberList[i];
    }
    count += 1;
  }

  cout<<endl<<"The largest value entered was: "<<max<<endl<<endl;

  cout<<"The total number of comparisons executed by this algorithm was: "<<count<<endl;

  return 0;
}
