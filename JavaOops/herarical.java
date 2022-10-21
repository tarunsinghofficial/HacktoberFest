class parent{
        parent(){
            System.out.println("I am parent");
        }
}

class son extends parent{
      son(){
        System.out.println("I am son");
      }
}
class daughter extends parent{
      daughter(){
        System.out.println("I am daughter");
      }
}

public class herarical {
    public static void main(String args[]){
        daughter d = new daughter();
        son s = new son();
    }
}
