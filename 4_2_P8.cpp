//Caleb A. Street
//Algorithms
//February 22, 2021
//Section 4.2 - Problem 8
//The graph used for this problem is the graph located in Section 4.2 - Problem 1a

#include <iostream>
#include <stack>
#include <time.h>

using namespace std;


int main(){
  //Depth First Seach Based Algorithm
  clock_t startTime = clock();
  int numberOfNodes = 7;
  string nodeArray[numberOfNodes] = {"a", "b", "c", "d", "e", "f", "g"};
  int matrix[][numberOfNodes] = {{0,1,1,0,0,0,0}, {0,0,0,0,1,0,1}, {0,0,0,0,0,1,0},{1,1,1,0,0,1,1},
				 {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,1,1,0}};
  stack <string> nodeStack;

  //Finds a source node
  int tempPosition;
  bool isSource = true;
  int sourcePosition = -1;
  for(int i = 0; i < numberOfNodes; i++){
    isSource = true;
    for(int j = 0; j < numberOfNodes; j++){
      if(matrix[j][i] == 1){
	isSource = false;
	break;
      }
    }
    //Sets the position of the source node
    if(isSource){
      sourcePosition = i;
      break;
    }
  }
  
  string tempArray[numberOfNodes];
  int counter = 0;

  nodeStack.push(nodeArray[sourcePosition]);

  //Executes the depth first search
  bool isEndNode = false;
  while(!nodeStack.empty()){
    isEndNode = false;
    //Finds the end node
    while(!isEndNode){
      isEndNode = true;
      for(int i = 0; i < numberOfNodes; i++){
        if(matrix[sourcePosition][i] == 1){
	  sourcePosition = i;
	  nodeStack.push(nodeArray[i]);
	  isEndNode = false;
	  break;
        }
      }
    }
    //Adds the end node to the temporary array
    tempArray[counter] = nodeStack.top();
    nodeStack.pop();
    counter += 1;

    //Removes the edges pointing to the end node
    for(int i = 0; i < numberOfNodes; i++){
      matrix[i][sourcePosition] = 0;
    }

    //Moves source position to the previous node
    if(!nodeStack.empty()){
      for(int i = 0; i < numberOfNodes; i++){
	if(nodeStack.top() == nodeArray[i]){
	  sourcePosition = i;
	}
      }
    }
  }

  //Adds any original source nodes that may have been missed
  bool flag = false;
  for(int i = 0; i < numberOfNodes; i++){
    flag = false;
    for(int j = 0; j < numberOfNodes; j++){
      if(nodeArray[i] == tempArray[j]){
	flag = true;
	break;
      }
    }
    if(!flag){
      tempArray[counter] = nodeArray[i];
      counter += 1;
    }
  }

  //Reverses the temporary array into the sorted list
  string sortedList[numberOfNodes];
  counter = 0;
  for(int i = numberOfNodes-1; i >= 0; i--){
    sortedList[counter] = tempArray[i];
    counter += 1;
  }

  //Prints out the sorted list
  cout<<"Here is the sorted list using the DFS based algorithm: "<<endl;
  for(int i = 0; i < numberOfNodes; i++){
    cout<<sortedList[i];
    if(i < numberOfNodes-1){
      cout<<", ";
    }
  }
  cout<<endl<<endl;

  clock_t endTime = clock();
  clock_t totalTimeOne = endTime - startTime;

  
  //Source Removal Algorithm
  startTime = clock();
  int newMatrix[][numberOfNodes] = {{0,1,1,0,0,0,0}, {0,0,0,0,1,0,1}, {0,0,0,0,0,1,0}, {1,1,1,0,0,1,1},
				    {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,1,1,0}};
  string tempNodeArray[numberOfNodes] = {"a", "b", "c", "d", "e", "f", "g"};
  string sortedNodeArray[numberOfNodes];

  bool noSource = false;
  counter = 0;
  while(!noSource){
    //Finds a source node
    isSource = true;
    sourcePosition = -1;
    for(int i = 0; i < numberOfNodes; i++){
      isSource = true;
      for(int j = 0; j < numberOfNodes; j++){
	if(newMatrix[j][i] == 1){
	  isSource = false;
	  break;
	}
      }
      //Sets the position for the source node
      if(isSource && tempNodeArray[i] != " "){
	sourcePosition = i;
	break;
      }
    }

    //Adds the source node to the sorted list
    sortedNodeArray[counter] = tempNodeArray[sourcePosition];
    counter += 1;

    //Removes all edges going out of the source node
    for(int i = 0; i < numberOfNodes; i++){
      newMatrix[sourcePosition][i] = 0;
    }

    //Removes the source node from the temporary list
    tempNodeArray[sourcePosition] = " ";

    //Checks to see if there are any more nodes in the temporary list
    flag = false;
    for(int i = 0; i < numberOfNodes; i++){
      if(tempNodeArray[i] != " "){
	flag = true;
	break;
      }
    }
    if(!flag){
      noSource = true;
    }
  }

  //Prints out the sorted list
  cout<<"Here is the sorted list using the source removal algorithm: "<<endl;
  for(int i = 0; i < numberOfNodes; i++){
    cout<<sortedNodeArray[i];
    if(i < numberOfNodes-1){
      cout<<", ";
    }
  }
  cout<<endl<<endl;
  
  endTime = clock();
  clock_t totalTimeTwo = endTime - startTime;

  cout<<"The amount of time it took to complete the first algorithm was: "
      <<totalTimeOne<<" clicks or "<<((float)totalTimeOne)/CLOCKS_PER_SEC<<" seconds"<<endl;
  cout<<"The amount of time it took to complete the second algorithm was: "
      <<totalTimeTwo<<" clicks or "<<((float)totalTimeTwo)/CLOCKS_PER_SEC<<" seconds"<<endl;
  
  return 0;
}
