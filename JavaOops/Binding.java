//static binding (early binding)-> when type of object is determined at compile time
//dynamic binding (late binding)-> when type of object is determined at run time
class parent{
    void fxn(){
        System.out.println("static binding -> early binding");
    }
}
class child extends parent{
    @Override
    void fxn(){
        System.out.println("dynamic binding-> late binding");
    }
}
public class Binding {
    public static void main(String args[]){
        parent p = new child();//dynamic binding 
        p.fxn();
        parent p1 = new parent();//late binding
        p1.fxn();
    }
}
