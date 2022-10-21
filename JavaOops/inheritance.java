class Animal{  
    static void eat(){System.out.println("eating...");} //static methods cannot be overide
    void walk(){
        System.out.println("walking animal...");
    } 
}  
class Dog extends Animal{  
    void bark(){
        System.out.println("barking...");
        super.walk();// super -> invoke the imediate parent class  // this and super cannot used in static methods
    }  
    @Override
    void walk(){
        System.out.println("walking dog...");
    }
}  
class BabyDog extends Dog{  
    void weep(){
        System.out.println("weeping...");
        super.walk();
    }  
}  
class inheritance{  
    public static void main(String args[]){  
    BabyDog d=new BabyDog();  
    d.weep();  
    d.bark();  
    d.eat();  //Animal.eat() is the right way
    d.walk();
    }
}  
//static methods are consume same memory for different obj eg=> obj.eat() ,obj1.eat() run on same memory