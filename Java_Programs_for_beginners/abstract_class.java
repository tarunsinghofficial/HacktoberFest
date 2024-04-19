abstract class calculations {

    abstract void calculate(float c);
}

class sub1 extends calculations{

   void calculate(float c){
    System.out.println("squrae is" + (c*c));
   }
    
}

class sub2 extends calculations{

    void calculate (float c){
        System.out.println( " cube is " +(c*c*c)) ;
    }
}

class sub3 extends calculations {
    void calculate (float c){
        System.out.println("square root is " + Math.sqrt(c));
    }
}

public class abstract_class {
    public static void main(String[] args) {
        sub1 s  = new sub1();
        sub2 ss = new sub2();
        sub3 sss = new sub3();

        s.calculate(3);
        ss.calculate(4);
        sss.calculate(64);

    }
}
