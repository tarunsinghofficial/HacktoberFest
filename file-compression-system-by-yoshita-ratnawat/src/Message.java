import java.util.*;
public class Message {
    private final String text;
    static final int CHAR_SIZE = 8;
    private final int ALPHABET_SIZE = 256;
    private final char[] characters;
    private final int[] frequencyOfChars;

    Message(final String text) {
        if(text.length() <= 0)
            throw new RuntimeException("Error: Message size <= 0");
        this.text = text;
        characters = getChars();
        frequencyOfChars = buildFrequencyTable();
    }

    public String getMessage() { return text; }
    public int getTotalFrequency() { return text.length(); }
    public char[] getCharacters() { return characters; }
    public int[] getFrequencies() { return frequencyOfChars; }
    public boolean isEmpty() { return getTotalFrequency() == 0; }

    public int getSize() {
        return CHAR_SIZE * getTotalFrequency();
    }


    private char[] getChars() {
        List list = new ArrayList<Character>();
        list.add(text.charAt(0));
        for (int i = 0; i < getTotalFrequency(); i++) {
            if (!list.contains(text.charAt(i)))
                list.add(text.charAt(i));
        }
        char[] myChars = new char[list.size()];
        for (int i = 0; i < list.size(); i++)
            myChars[i] = (Character) list.get(i);
        return myChars;
    }

    // Calculates the number of times ch appears in the string.
    public int calcFrequencyOfChar(final char ch) {
        int charFreq = 0;
        for(int i = 0; i < getTotalFrequency(); i++) {
            if(text.charAt(i) == ch)
                charFreq++;
        }
        return charFreq;
    }

    // Builds frequency table of each unique character
    private int[] buildFrequencyTable() {
        int[] frequencies = new int[ALPHABET_SIZE];
        for(final char ch : text.toCharArray()) {
            frequencies[ch]++;
        }
        return frequencies;
    }

    public String binaryCode() {
        String binarySequence = new String();
        for(int i = 0; i < getTotalFrequency(); i++) {
            binarySequence += convertBinary(getMessage().charAt(i));
        }
        return binarySequence;
    }
    
    public String[] binaryOfChars() {
        String[] binarySequence = new String[characters.length];
        for(int i = 0; i < characters.length; i++) {
            binarySequence[i] = convertBinary(characters[i]);
        }
        return binarySequence;
    }

    public String convertBinary(int decimal) {
        String binary="";
        while(decimal>0)
        {
            binary=(decimal%2)+binary;
            decimal=decimal/2;
        }

        String str =new String(), zeros ="0";
        if(binary.length()!= 8)
        {
            while(str.length() != 8)
            {
                str = zeros + binary;
                zeros += "0";
            }
        }

        return str;
    }
}
