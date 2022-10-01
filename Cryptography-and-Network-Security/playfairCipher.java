package com.company;
import java.io.*;
import java.util.*;

class Playfair {
    String key;
    String plainText;
    char[][] matrix = new char[5][5];
    public Playfair(String key, String plainText)
    {
        this.key = key.toLowerCase();
        this.plainText = plainText.toLowerCase();
    }
    public void cleanPlayFairKey()
    {
        LinkedHashSet<Character> set = new LinkedHashSet<Character>();
        String newKey = "";
        for (int i = 0; i < key.length(); i++)
            set.add(key.charAt(i));
        Iterator<Character> it = set.iterator();
        while (it.hasNext())
            newKey += (Character)it.next();
        key = newKey;
    }
    public void generateCipherKey()
    {
        Set<Character> set = new HashSet<Character>();
        for (int i = 0; i < key.length(); i++)
        {
            if (key.charAt(i) == 'j')
                continue;
            set.add(key.charAt(i));
        }
        String tempKey = new String(key);
        for (int i = 0; i < 26; i++)
        {
            char ch = (char)(i + 97);
            if (ch == 'j')
                continue;
            if (!set.contains(ch))
                tempKey += ch;
        }
        for (int i = 0, idx = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                matrix[i][j] = tempKey.charAt(idx++);
        System.out.println("Playfair Cipher Key Matrix:");
        for (int i = 0; i < 5; i++)
            System.out.println(Arrays.toString(matrix[i]));
    }
    public String formatPlainText()
    {
        String message = "";
        int len = plainText.length();
        for (int i = 0; i < len; i++)
        {
            if (plainText.charAt(i) == 'j')
                message += 'i';
            else
                message += plainText.charAt(i);
        }
        for (int i = 0; i < message.length(); i += 2)
        {
            if (message.charAt(i) == message.charAt(i + 1))
                message = message.substring(0, i + 1) + 'x' + message.substring(i + 1);
        }
        if (len % 2 == 1)
            message += 'x'; // dummy character
        return message;
    }
    public String[] formPairs(String message)
    {
        int len = message.length();
        String[] pairs = new String[len / 2];
        for (int i = 0, cnt = 0; i < len / 2; i++)
            pairs[i] = message.substring(cnt, cnt += 2);
        return pairs;
    }
    public int[] getCharPos(char ch)
    {
        int[] keyPos = new int[2];
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (matrix[i][j] == ch)
                {
                    keyPos[0] = i;
                    keyPos[1] = j;
                    break;
                }
            }
        }
        return keyPos;
    }

    public String encryptMessage()
    {
        String message = formatPlainText();
        String[] msgPairs = formPairs(message);
        String encText = "";
        for (int i = 0; i < msgPairs.length; i++)
        {
            char ch1 = msgPairs[i].charAt(0);
            char ch2 = msgPairs[i].charAt(1);
            int[] ch1Pos = getCharPos(ch1);
            int[] ch2Pos = getCharPos(ch2);
            if (ch1Pos[0] == ch2Pos[0]) {
                ch1Pos[1] = (ch1Pos[1] + 1) % 5;
                ch2Pos[1] = (ch2Pos[1] + 1) % 5;
            }
            else if (ch1Pos[1] == ch2Pos[1])
            {
                ch1Pos[0] = (ch1Pos[0] + 1) % 5;
                ch2Pos[0] = (ch2Pos[0] + 1) % 5;
            }
            else {
                int temp = ch1Pos[1];
                ch1Pos[1] = ch2Pos[1];
                ch2Pos[1] = temp;
            }
            encText = encText + matrix[ch1Pos[0]][ch1Pos[1]] + matrix[ch2Pos[0]][ch2Pos[1]];
        }
        return encText;
    }
}
public class playfairCipher {
    public static void main(String[] args)
    {
        System.out.println("Example-1\n");
        Scanner sc=new Scanner(System.in);
        String key1=sc.nextLine();
        String plainText1=sc.nextLine();
        System.out.println("Key: " + key1);
        System.out.println("PlainText: " + plainText1);

        Playfair playfair = new Playfair(key1, plainText1);
        playfair.cleanPlayFairKey();
        playfair.generateCipherKey();

        String encText1 = playfair.encryptMessage();
        System.out.println("Cipher Text is: " + encText1);
    }
}
