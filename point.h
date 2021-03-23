//Caleb A. Street
//Algorithms
//February 19, 2021
//Class that creates point objects on an x, y plane

class Point{

 public:
  //setters
  void setX(int value){
    x = value;
  }

  void setY(int value){
    y = value;
  }

  //getters
  int getX(){
    return x;
  }

  int getY(){
    return y;
  }


 private:
  int x;
  int y;

};
