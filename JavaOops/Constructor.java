class Student{
    public
        int x;
        Student(){
            System.out.println("Constructor is called");//default constructor
        }
        Student(int x){// parameterised constructor
            this.x=x;
        }
        Student(Student s){//copy constructor
            this.x = s.x;
        }
        void print(){
            System.out.println(this.x);//containing address of current obj
        }
};
//Java doesn't create a default copy constructor if you don't write your own.
//java doesn't have destructor garbage collection happens internally

public class Constructor
{
	public static void main(String[] args) {
	    //static
		Student s1 = new Student(20);
		
		Student s2 = new Student(s1);//deep copy
		
		Student s3 = s1;//shallow copy
        s1.x=10;
		s3.print();//print 10
		System.out.println(s2.x);//it print 20
		
	}
}