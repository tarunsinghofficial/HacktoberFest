package com.company;
import java.util.Random;
import java.util.Scanner;

public class GuessTheNumber {
    private int guesses = 10;
    private int warning = 4;
    private int guessedNo;
    private int[] alreadyTold = new int[10];
    int index = 0;
    int rng = 20;

    public int inputInt(){
        System.out.print("Enter Your Guess: ");
        Scanner num = new Scanner(System.in);
        return num.nextInt();
    }

    public int generateRand(int range){
        Random rand = new Random();
        return rand.nextInt(range);
    }
    public void setAlreadyTold(int guess){
        this.alreadyTold[index] = guess;
        this.index++;
    }

    public boolean isAlreadyTold(int guess){
        for(int i = 0; i < 10; i++){
            if(guess == this.alreadyTold[i]){
                return true;
            }
        }
        return false;
    }

    public void play(){
        int secretNum = generateRand(rng);
        System.out.println("I am Thinking of a word between 0-"+ rng + ".");
        int guess;
        boolean flag = true;
        do{
            System.out.println("Remaining guesses: "+this.guesses+"\nRemaining warnings: "+this.warning);
            guess = inputInt();
            if(guess == secretNum)
            {
                System.out.println("Congratulations! You have guessed the secret number!!");
                flag = false;
            }
            else if(this.warning==0 || this.guesses==0){
                    System.out.println("Game Over!");
                    flag = false;
            }
            else
            {
                if(isAlreadyTold(guess)){
                    this.warning--;
                    this.guesses--;
                    System.out.println("You have already guessed this number");
                }else
                if(guess < secretNum){
                    this.guesses--;
                    System.out.println("Guessed number is less than secret number.");
                    setAlreadyTold(guess);
                }else {
                    this.guesses--;
                    System.out.println("Guessed number is greater than secret number.");
                    setAlreadyTold(guess);
                }
            }

        }while(flag);
    }

    public static void main(String[] args){
        GuessTheNumber n = new GuessTheNumber();
        System.out.println(n.generateRand(20));
        n.play();

    }
}
