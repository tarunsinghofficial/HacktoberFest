import java.security.SecureRandom;

public class rolldie{
    public static void main(String[] args) {
       SecureRandom rand = new SecureRandom();
        int[] freq=new int[7];

        for (int k=1;k<=6000000;k++){
            ++freq[1+ rand.nextInt(6)];
        }

        System.out.println("Face\tFrequency");
        for(int i=1;i<freq.length;i++){
            System.out.println(i +"\t" + freq[i]);
        }

    }
}