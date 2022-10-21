class Student{
    private
        int rollno;
    public
        static int counter;
        Student(){
            counter++;
        }
        void getRollno(){
            System.out.println(rollno);
        }
        void setRollno(int x){
            rollno = x;
        }
        void show(){
            System.out.println(counter);
        }
}

public class setget
{
	public static void main(String[] args) {
		Student s1 = new Student();
		Student s2 = new Student();
		s1.setRollno(12);
        s1.getRollno();
		s2.show();
	}
} 
