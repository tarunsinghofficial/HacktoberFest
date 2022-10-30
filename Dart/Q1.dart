
/* make a class point, constructor receiving 
arguments in double, aother function to display, method : move,
move method will interchange x,y */

class point{
  double? x;
  double? y;  
  double? temp;
  
  point(double x, double y){
    this.x = x;
    this.y = y;
  }
  
  void display(){
    print("This function display the co-ordinates!");
    print("Point(${x}, ${y})");
  }
  
  void move(){
    temp=x;
    x=y;
    y=temp;
  }
}

void main(){
  point a = new point(12.05, 13.19);
  
  a.display();
  a.move();
  a.display();
}