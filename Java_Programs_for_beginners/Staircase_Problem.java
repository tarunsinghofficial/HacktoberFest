class StairCaseProblem {
    public static int countWays(int n) {
        int[] lookupTable = new int[n + 1]; // Initialize lookup table
        lookupTable[0] = 1; // Setting the first three values
        lookupTable[1] = 1;
        lookupTable[2] = 2;

        for (int i = 3; i <= n; i++)
            lookupTable[i] = lookupTable[i - 1] + lookupTable[i - 2] + lookupTable[i - 3]; // Fill up the table by summing up previous two values

        return lookupTable[n];
    }

    public static void main(String args[]) {
        System.out.println(countWays(3));
    }
};
