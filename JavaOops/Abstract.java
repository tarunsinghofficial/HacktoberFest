abstract class Animal{
    void feature(){
        System.out.print("we have tail");
    }
}

class reptile extends Animal{
    // void feature(){
    //     System.out.print("we have long tail");
    // }
}


public class Abstract {
    public static void main(String[] args){
        reptile r = new reptile();
        r.feature();
        // Animal a = new Animal(); // it cant access abstract class directly
        // a.feature();
    }
}
