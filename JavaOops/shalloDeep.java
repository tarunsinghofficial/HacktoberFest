class Student{
    public
        int x;
        Student(){
            System.out.println("Constructor is called");//default constructor
        }
        Student(int a){// parameterised constructor
            x=a;
        }
        Student(Student s){// copy constructor
            x = s.x;
        }
        void print(){
            System.out.println(this.x);//containing address of current obj
        }
};

//Java doesn't create a default copy constructor if you don't write your own.
//java doesn't have destructor garbage collection happens internally

public class shalloDeep
{
	public static void main(String[] args) {
	    //static
		Student s1 = new Student(20);
		
		Student s2 = new Student(s1);//deepcopy
		
		Student s3 = s1;//shallo copy
		s1.x=10;
		s3.print();
		System.out.println(s2.x);
		
	}
}