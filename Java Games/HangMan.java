package com.company;

import java.util.Random;
import java.util.Scanner;

public class HangMan {
    private String[] wordCollection = {"banana", "apple", "mango", "pinapple", "grapefruit", "kiwi", "custardapple", "dragonfruit", "coconut", "strawberry", "blueberry", "melon", "tangerine", "apricot", "peach", "orange", "cherry", "grape", "watermelon", "pear"};
    private String compPick = null;
    private int guesses;
    private int warning = 4;
    private String alphabets = "abcdefghijklmnopqrstuvwxyz";

    private char[] guessedWord = null;
    private int[] indices;

    public char inputChar(){
        System.out.print("Enter Your Guess: ");
        Scanner num = new Scanner(System.in);
        return num.next().charAt(0);
    }

    public void pickWord(){
        int rng = wordCollection.length;
        Random num = new Random();
        int i = num.nextInt(rng);
        this.compPick = wordCollection[i];
    }

    public void setGuessedWord(){
        int length = this.compPick.length();
        this.guessedWord = new char[length];
        for(int i = 0; i < length; i++){
            this.guessedWord[i] = '_';
        }
    }

    public void setGuess(String word){
        this.guesses = (int) (word.length()*1.5);
    }

    public Boolean isInPick(char letter) {
        return this.compPick.indexOf(letter) != -1;
    }

    public void setIndices(char letter){
        int length = this.compPick.length();
        int ind = 0;
        char[] comPickArray = this.compPick.toCharArray();
        this.indices = new int[length];
        for(int i = 0; i < length; i++){
            if(letter == comPickArray[i]){
                this.indices[ind] = i;
                ind++;
            }
        }
    }

    public void updateGuessed(char letter, int[] loc) {
        int length = this.guessedWord.length;
        int ind = 0;
        for(int i = 0; i < length; i++){
            if(i == loc[ind]){
                ind++;
                this.guessedWord[i] = letter;
            }
        }

    }

    public void removeAlphabet(char letter){
            this.alphabets = this.alphabets.replace(letter, ' ');
    }

    public boolean alreadyGuessed(char letter){
        if(this.alphabets.indexOf(letter) == -1){
            this.warning--;
            return true;
        }
        else{
            return false;
        }
    }

    public boolean wordGuessed(){
        for(int i = 0; i < this.guessedWord.length; i++){
            if(guessedWord[i] == '_'){
                return false;
            }
        }
        return true;
    }

    public void play() {
        pickWord();
        setGuessedWord();
        setGuess(this.compPick);
        System.out.println("I am thinking of a " + this.compPick.length() + " letter word.");
        boolean flag = true;
        do {
            if ((this.warning == 0 || this.guesses == 0) || wordGuessed()) {
                if(wordGuessed()){
                    System.out.println(this.guessedWord);
                    System.out.println("Congrats!");
                }else{
                    System.out.println("You failed. The word was: " + this.compPick);
                }
                flag = false;
            } else
            {
                System.out.println("You have " + this.guesses + " guesses.");
                System.out.println("You have " + this.warning + " warnings.");
                System.out.println("Alphabets remaining: " + this.alphabets);
                System.out.println(this.guessedWord);
                char guessLetter = inputChar();
                if (isInPick(guessLetter)) {
                    if (alreadyGuessed(guessLetter)) {
                        System.out.println("You have already guessed this letter.");
                    }
                    else{

                        setIndices(guessLetter);
                        updateGuessed(guessLetter, this.indices);
                        removeAlphabet(guessLetter);
                    }

                }
                else{
                    System.out.println("Wrong Guess!");
                    this.guesses--;
                }
            }
        }while (flag) ;

    }

    public static void main(String args[]) {
        HangMan h = new HangMan();
        h.play();

    }
}
