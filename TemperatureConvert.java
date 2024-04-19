import java.io.*;

public class TemperatureConvert
{

    public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
     
        System.out.print("Enter temperature in Fahrenheit: ");
        float F =Float.parseFloat(br.readLine());

        float C = (F - 32) * (9 / 5);

        System.out.println( "Temperature in Celsius:"+C);

    }
}