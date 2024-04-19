public class Sample {

    public static void main(String args[]) {
        int[] newArray = new int[5];

        // Initializing elements of array seperately
        for (int n = 0; n < newArray.length; n++) {
            newArray[n] = n;
        }
        System.out.println(newArray[2]); // Assigning 2nd element of array value
    }
}
