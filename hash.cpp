//Caleb A. Street
//Algorithms
//April 7, 2021
//Open Hashing
//This code is based on the example code provided to us on the class server

#include <iostream>
#include <list>
using namespace std;


//Adds the specified value to the hash table
void  hashFunction(int value, list<int> *HT){
  int entry = value % 10;
  HT[entry].push_back(value);
}


//Searches the hash table for a specified value
void searchHashTable(int value, list<int> *HT){
  bool flag = true;
  int entry = value % 10;
  //loops through the list and checks to see if the value is in that list
  for(list<int>::iterator it = HT[entry].begin(); it != HT[entry].end(); it++){
    if(*it == value){
      cout<<"This value is in the hash table"<<endl<<endl;
      flag = false;
      break;
    }
  }
  if(flag){
    cout<<"This value is not in the hash table"<<endl<<endl;
  }
}


int main(){
  //each element of the array is a list
  list<int> HT[10];

  cout<<"\nAdding values to the hash table"<<endl;

  int num;
  while(true){

    cout<<"Please enter a positive integer value (or -1 to quit): ";
    cin>>num;
    cout<<"\n";

    //input validation
    while((!num && num != -1) || num < -1){
      cout<<"Sorry.  That value could not be accepted."<<endl;
      cout<<"Please enter a positive integer value (or -1 to quit): ";
      cin.clear();
      cin.ignore();
      cin>>num;
      cout<<"\n";
    }

    //breaks the loop if input is -1
    if(num == -1){
      break;
    }

    hashFunction(num, HT);

  }

  cin.clear();
  cin.ignore();
  cout<<"\n\nSearching the hash table"<<endl;
  while(true){

    cout<<"Please enter a positive integer value (or -1 to quit): ";
    cin>>num;

    //input validation
    while((!num && num != -1) || num < -1){
      cout<<"\nSorry. That value could not be accepted."<<endl;
      cout<<"Please enter a positive integer value (or -1 to quit): ";
      cin.clear();
      cin.ignore();
      cin>>num;
    }

    //breaks the loop if input is -1
    if(num == -1){
      break;
    }

    searchHashTable(num, HT);
    
  }
  
  return 0;
}
