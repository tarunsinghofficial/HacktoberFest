public class JavaSingleton {
    public static void main(String args[]) {
    System.out.println( Singleton.getInstance());
   System.out.println( Singleton.getInstance());
    }
}

class Singleton{
    private static Singleton instance;
    private Singleton(){
    }
    public static Singleton getInstance(){
        synchronized (Singleton.class){
        if(instance== null)
            instance = new Singleton();
        }
        return instance;
    }
}
