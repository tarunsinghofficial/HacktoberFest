package angga.relasiclass.percobaan4;

public class MainPercobaan4 {
    public static void main(String[] args) {
        Penumpang p1 = new Penumpang("12345", "Mr. Krab");
        Gerbong gerbong = new Gerbong("A", 10);
        gerbong.setPenumpang(p1, 1);
        System.out.println(gerbong.info());
        
        Penumpang budi = new Penumpang("123", "Karjo");
        gerbong.setPenumpang(budi, 1);
        System.out.println(gerbong.info());
        /*Penumpang p2 = new Penumpang("12345", "Mrs. Puff");
        gerbong.setPenumpang(p2, 1);
        System.out.println(gerbong.info());*/
    }
}
