#include <iostream>
using namespace std;
class shape
{
    float radius;
    float width;
    float length;
    public:
shape()
    {
        radius=0.0;
        width=0.0;
        length=0.0;
    }
shape(float r)
    {
        radius=r;
    }
shape(float w,float l)
    {
        width=w;
        length=l;
    }
    void circle_perimeter()
    {
        float perimeter;
        perimeter=2*3.14*radius;
cout<<"perimeter of circle is "<<perimeter<<endl;;
    }
    void rectangle_perimeter()
    {
        float perimeter;
        perimeter=2*(length+width);
cout<<"perimeter of rectangle is "<<perimeter<<endl;
    }
    ~shape()
    {

    }
};
int main()
{

    float r,w,l;
cout<<"enter radius of circle \n";
cin>>r;
cout<<"enter width and length of rectangle \n";
cin>>w>>l;
    shape circle(r);
    shape rectangle(w,l);
circle.circle_perimeter();
rectangle.rectangle_perimeter();
}
