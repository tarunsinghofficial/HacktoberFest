class Student{
    public
        static int counter;
        Student(){
            counter++;
        }
        static void show(){
            System.out.println(counter);
        }
        static void show(int x){
            System.out.println(counter);
        }
}

public class stat
{
	public static void main(String[] args) {
		Student s1 = new Student();
		Student s2 = new Student();
		s2.show();
        s1.show(1);
	}
}
//static variable and static method occupied only single space memory all its object
//We can overload static methods.-> reason overloading is done in compile time
//We cannot override the static method.-> reason overriding is done in runtime
//i cannot call non static method and variable in static method.
// constructor can never be static 