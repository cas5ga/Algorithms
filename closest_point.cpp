//Caleb A. Street
//Algorithms
//February 19, 2021
//This program implements the closest point problem algorithm

#include <iostream>
#include "point.h"
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

//Returns a random number
int randomNumber(){
  clock_t time = clock();    //gets the current time
  srand(time);    //uses the current time to make the number more random
  int randNumber = (rand() % 201) - 100;     //gets a random number between -100 and 100
  return randNumber;
}

//Sets the x and y values for each of the points
void createPoints(Point *pointArray, int size){
  for(int i = 0; i < size; i++){
    int x = randomNumber();     //gets a random x value
    int y = randomNumber();     //gets a random y value
    pointArray[i].setX(x);      //sets the x value
    pointArray[i].setY(y);      //sets the y value
  }
}

//Calculates the distance between two points
void calculateDistances(Point *pointArray, int size, float *tempArray){
  float distance = 0;
  float minDistance = 1000;
  int pointOnePosition = 0;
  int pointTwoPosition = 0;
  //Loops through every possible combination of two points
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      if(i < j){
	//Gets the distance between each set of points
        distance = sqrt(pow((pointArray[i].getX() - pointArray[j].getX()), 2) + pow((pointArray[i].getY() - pointArray[j].getY()), 2));
	//Determines if the new distance is less than the shortest distance encountered so far
        if(distance < minDistance){
	  minDistance = distance;     //assigns a new shortests distance
	  pointOnePosition = i;     //assigns a new position for point one
	  pointTwoPosition = j;     //assigns a new position for point two
        }
      }
    }
  }
  //Assigns these values to the tempArray to be used int the main program
  tempArray[0] = minDistance;
  tempArray[1] = (float)pointOnePosition;
  tempArray[2] = (float)pointTwoPosition;
}


int main(){
  int numPoints = 0;
  
  cout<<"Please enter the number of points you would like to create: ";
  cin>>numPoints;

  //Input validation
  while(!numPoints){
    cout<<"Sorry.  Please enter a number: ";
    cin.clear();
    cin.ignore();
    cin>>numPoints;
  }

  Point pointArray[numPoints];

  createPoints(pointArray, numPoints);     //assigns the random values to the x and y coordinates of each point

  //Displays the points that were generated
  cout<<"\nHere are the "<<numPoints<<" random points that were generated:"<<endl;
  for(int i = 0; i < numPoints; i++){
    cout<<"Point "<<i+1<<": "<<"("<<pointArray[i].getX()<<", "<<pointArray[i].getY()<<")"<<endl;
  }

  float tempArray[3];
  calculateDistances(pointArray, numPoints, tempArray);  //Gets the shortest distance between any two points

  cout<<"\nThe two points that are the closest to each other are: "<<"("<<pointArray[(int)tempArray[1]].getX()<<", "<<pointArray[(int)tempArray[1]].getY()<<
    ") and ("<<pointArray[(int)tempArray[2]].getX()<<", "<<pointArray[(int)tempArray[2]].getY()<<")"<<endl;
  
  cout<<"The distance between these two points is: "<<tempArray[0]<<endl;
  
}
