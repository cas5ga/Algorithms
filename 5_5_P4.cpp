//Caleb A. Street
//Algorithms
//March 3, 2021
//Implements the divide-and-conquer closest-pair algorithm from the book
//This is the algorithm from section 5.5 (page 194)

#include <iostream>
#include <math.h>
#include "point.h"

using namespace std;


int EfficientClosestPair(int *P, int *Q, int n){

  if(n <= 3){
    int minDistance = 100;
    int distance = 0;

    for(int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
	distance = sqrt(((P[i].getX() - P[j].getX())**2) + ((P[i].getY() - P[j].getY())**2));

	if(distance < minDistance){
	  minDistance = distance;
	}
      }
    }

    return minDistance;
  }

  else{
    int[n/2] Pl;
    int[n/2] Pr;
    int[n/2] Ql;
    int[n/2] Qr;
    
    for(int i = 0; i < ceiling(n/2); i++){
      Pl[i] = P[i];
      Ql[i] = Q[i];
    }

    for(int i = floor(n/2); i < n; i++){
      Pr[i] = P[i];
      Qr[i] = Q[i];
    }

    int dl = EfficientClosestPair(Pl, Ql, n/2);
    int dr = EfficientClosestPair(Pr, Qr, n/2);
    distance = min(dl, dr);
    int m = P[ceiling(n/2)-1].getX();

    int[num] S;
    for(int i = 0; i < n; i++){
      if(abs(Q[i].getX() - m) < distance){
	S[i] = Q[i];
      }
    }

    int dminsq = distance**2;
    for(int i = 0; i < num-1; i++){
      int k = k + 1;
      while(k <= num -1 && (S[k].getY() - S[i].getY())**2 < dminsq){
	dminsq = min((S[k].getX() - S[i].getX())**2 + (S[k].getY() - S[i].getY())**2, dminsq);
	k = k+1;
      }
    }
  }
  return sqrt(dminsq);
}
