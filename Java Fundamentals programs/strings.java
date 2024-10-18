public class Strings { // Class name should start with an uppercase letter
    public static void main(String[] args) {
        String name = "Keith";
        String other = "Keith";
        
        // Using equals method to compare strings
        String result = name.equals(other) ? "equal" : "They're not!";
        System.out.println(result);
    }
}
