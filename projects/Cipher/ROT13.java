package Cipher;

public class ROT13 {

    private String encodeDecodeROT13(String inputText){
        StringBuilder str = new StringBuilder();
        int cipInt = 0;
        char cipChar;
        for (int i = 0; i < inputText.length(); i++){
            char ch = inputText.charAt(i);
            int chi = charToNum(ch);
            cipInt = (chi + 13) % 26;
            if ((int)ch >= 65 && (int)ch <= 90 ){
                cipChar = numToChar(cipInt, 1);
            }else{
                cipChar = numToChar(cipInt, 0);
            }
            str.append(cipChar);
        }
        return str.toString();
    }

    public String encodeDecodeProcedureROT13(String inputText){

        StringBuilder str1 = new StringBuilder();
        StringBuilder encodedText = new StringBuilder();
        String plainText = null;
        String encode;
        int noSpclChar = 0;

        for (int i = 0; i < inputText.length(); i++){
            if (('A' <= inputText.charAt(i) && inputText.charAt(i) <= 'Z') || ('a' <= inputText.charAt(i) && inputText.charAt(i) <= 'z')){

                str1.append(inputText.charAt(i));
                plainText = str1.toString();
                noSpclChar = 1;

            }else {

                noSpclChar = 0;
                if (plainText != null){
                    encodedText.append(encodeDecodeROT13(plainText));
                }
                str1.delete(0, i);

                plainText = null;
                encodedText.append(inputText.charAt(i));

            }

        }

        if (noSpclChar == 1 & plainText != null){
            encodedText.append(encodeDecodeROT13(plainText));
        }

        encode = encodedText.toString();

        return encode;
    }

    private int charToNum(char c){
        int ret = -1;
        if (c == 'A'||c == 'a'){
            ret = 0;
        }else if(c == 'B'||c == 'b'){
            ret = 1;
        }else if(c == 'C'||c == 'c'){
            ret = 2;
        }else if(c == 'D'||c == 'd'){
            ret = 3;
        }else if(c == 'E'||c == 'e'){
            ret = 4;
        }else if(c == 'F'||c == 'f'){
            ret = 5;
        }else if(c == 'G'||c == 'g'){
            ret = 6;
        }else if(c == 'H'||c == 'h'){
            ret = 7;
        }else if(c == 'I'||c == 'i'){
            ret = 8;
        }else if(c == 'J'||c == 'j'){
            ret = 9;
        }else if(c == 'K'||c == 'k'){
            ret = 10;
        }else if(c == 'L'||c == 'l'){
            ret = 11;
        }else if(c == 'M'||c == 'm'){
            ret = 12;
        }else if(c == 'N'||c == 'n'){
            ret = 13;
        }else if(c == 'O'||c == 'o'){
            ret = 14;
        }else if(c == 'P'||c == 'p'){
            ret = 15;
        }else if(c == 'Q'||c == 'q'){
            ret = 16;
        }else if(c == 'R'||c == 'r'){
            ret = 17;
        }else if(c == 'S'||c == 's'){
            ret = 18;
        }else if(c == 'T'||c == 't'){
            ret = 19;
        }else if(c == 'U'||c == 'u'){
            ret = 20;
        }else if(c == 'V'||c == 'v'){
            ret = 21;
        }else if(c == 'W'||c == 'w'){
            ret = 22;
        }else if(c == 'X'||c == 'x'){
            ret = 23;
        }else if(c == 'Y'||c == 'y'){
            ret = 24;
        }else if(c == 'Z'||c == 'z'){
            ret = 25;
        }
        return ret;
    }

    private char numToChar(int i, int j){
        char c = '\0';
        if (i == 0){
            if (j == 1){
                c = 'A';
            }else{
                c = 'a';
            }

        }else if(i == 1){
            if (j == 1){
                c = 'B';
            }else{
                c = 'b';
            }
        }else if(i == 2){
            if (j == 1){
                c = 'C';
            }else{
                c = 'c';
            }
        }else if(i == 3){
            if (j == 1){
                c = 'D';
            }else{
                c = 'd';
            }
        }else if(i == 4){
            if (j == 1){
                c = 'E';
            }else{
                c = 'e';
            }
        }else if(i == 5){
            if (j == 1){
                c = 'F';
            }else{
                c = 'f';
            }
        }else if(i == 6){
            if (j == 1){
                c = 'G';
            }else{
                c = 'g';
            }
        }else if(i == 7){
            if (j == 1){
                c = 'H';
            }else{
                c = 'h';
            }
        }else if(i == 8){
            if (j == 1){
                c = 'I';
            }else{
                c = 'i';
            }
        }else if(i == 9){
            if (j == 1){
                c = 'J';
            }else{
                c = 'j';
            }
        }else if(i == 10){
            if (j == 1){
                c = 'K';
            }else{
                c = 'k';
            }
        }else if(i == 11){
            if (j == 1){
                c = 'L';
            }else{
                c = 'l';
            }
        }else if(i == 12){
            if (j == 1){
                c = 'M';
            }else{
                c = 'm';
            }
        }else if(i == 13){
            if (j == 1){
                c = 'N';
            }else{
                c = 'n';
            }
        }else if(i == 14){
            if (j == 1){
                c = 'O';
            }else{
                c = 'o';
            }
        }else if(i == 15){
            if (j == 1){
                c = 'P';
            }else{
                c = 'p';
            }
        }else if(i == 16){
            if (j == 1){
                c = 'Q';
            }else{
                c = 'q';
            }
        }else if(i == 17){
            if (j == 1){
                c = 'R';
            }else{
                c = 'r';
            }
        }else if(i == 18){
            if (j == 1){
                c = 'S';
            }else{
                c = 's';
            }
        }else if(i == 19){
            if (j == 1){
                c = 'T';
            }else{
                c = 't';
            }
        }else if(i == 20){
            if (j == 1){
                c = 'U';
            }else{
                c = 'u';
            }
        }else if(i == 21){
            if (j == 1){
                c = 'V';
            }else{
                c = 'v';
            }
        }else if(i ==22){
            if (j == 1){
                c = 'W';
            }else{
                c = 'w';
            }
        }else if(i ==23){
            if (j == 1){
                c = 'X';
            }else{
                c = 'x';
            }
        }else if(i ==24){
            if (j == 1){
                c = 'Y';
            }else{
                c = 'y';
            }
        }else if(i == 25){
            if (j == 1){
                c = 'Z';
            }else{
                c = 'z';
            }
        }
        return c;
    }
}
