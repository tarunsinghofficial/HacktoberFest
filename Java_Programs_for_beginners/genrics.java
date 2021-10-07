package com.company;
import java.io.IOException;
import java.lang.reflect.Method;

class Printer <T>
{
    //Write your code here
    public void printArray(T[] elements){
        for(T element : elements){
            System.out.println(element);
        }
    }

}

class main {


    public static void main( String args[] ) {
        Printer myPrinter = new Printer();
        Integer[] intArray = { 1, 2, 3 };
        String[] stringArray = {"Hello", "World"};
        myPrinter.printArray(intArray);
        myPrinter.printArray(stringArray);
        int count = 0;

        for (Method method : Printer.class.getDeclaredMethods()) {
            String name = method.getName();

            if(name.equals("printArray"))
                count++;
        }

        if(count > 1)System.out.println("Method overloading is not allowed!");

    }
}
