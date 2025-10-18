
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class FileWrite {
    public static void main(String[] args) {
        String data = "Hello world is printed here.";
        try {
            OutputStream out = new FileOutputStream("output.txt");
            byte[] dataBytes = data.getBytes();

            out.write(dataBytes);
            System.out.println("Data is written to the file.");
            out.close();


        } catch (IOException e) {
            System.out.println("Error!" + e);
        }
    }
}
