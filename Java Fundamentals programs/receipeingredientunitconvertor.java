package githubpr;

import java.util.*;

/*
Concepts involved:- OOP, HashMap
Functions of every line are written in comments above them
Inputs are to be given as mentioned eg- if Liquids, then on entering Liquid , it will give error
 */

public class receipeingredientunitconvertor {

    //initialising the map
    private Map<String, Map<String,Double>> unitconvertor;

    //constructor starts - everytime a object will be created,it will automatically have these properties
    public receipeingredientunitconvertor() {

        //creating the map
        unitconvertor = new HashMap<>();

        //putting values of various ingredients and their unit conversions
        Map<String, Double> allpurposeflour = new HashMap<>();
        allpurposeflour.put("cup", 125.0);
        allpurposeflour.put("tbsp", 8.0);
        allpurposeflour.put("tsp", 3.0);
        allpurposeflour.put("grams",1.0);
        unitconvertor.put("Flour", allpurposeflour);

        Map<String, Double> sugar = new HashMap<>();
        sugar.put("cup", 200.0);
        sugar.put("tbsp", 12.0);
        sugar.put("tsp", 4.0);
        sugar.put("grams",1.0);
        unitconvertor.put("Sugar", sugar);

        Map<String, Double> butter = new HashMap<>();
        butter.put("cup", 277.0);
        butter.put("tbsp", 14.0);
        butter.put("tsp", 5.0);
        butter.put("grams",1.0);
        butter.put("ml",1.0);
        unitconvertor.put("Butter", butter);

        Map<String, Double> eggs = new HashMap<>();
        eggs.put("EggInShell", 57.0);
        eggs.put("EggW/OShell", 50.0);
        eggs.put("EggYolk", 18.0);
        eggs.put("EggWhite", 30.0);
        eggs.put("grams",1.0);
        eggs.put("ml",1.0);
        unitconvertor.put("Eggs", eggs);

        Map<String, Double> general = new HashMap<>();
        general.put("ounce", 28.0);
        general.put("pound", 453.0);
        general.put("oz.liquid", 30.0);
        general.put("grams",1.0);
        general.put("ml",1.0);
        unitconvertor.put("General", general);


        Map<String, Double> liquids = new HashMap<>();
        liquids.put("metriccup", 250.0);
        liquids.put("tbsp", 50.0);
        liquids.put("tsp", 18.0);
        liquids.put("ml",1.0);
        unitconvertor.put("Liquids", liquids);

        Map<String, Double> cocoapowder = new HashMap<>();
        cocoapowder.put("cup", 120.0);
        cocoapowder.put("tbsp", 8.0);
        cocoapowder.put("tsp", 3.0);
        cocoapowder.put("grams",1.0);
        unitconvertor.put("CocoaPowder", cocoapowder);

        Map<String, Double> others = new HashMap<>();
        others.put("tspDryYeast", 120.0);
        others.put("EnvelopeDryYeast", 8.0);
        others.put("cupMilkPowder", 3.0);
        others.put("cupCornFlour", 125.0);
        others.put("tbspCornFlour", 9.0);
        others.put("tspCornFlour", 3.0);
        others.put("cupHoney", 340.0);
        others.put("tbspHoney", 21.0);
        others.put("cupYogurt", 245.0);
        others.put("tbspIcingSugar", 8.0);
        others.put("grams",1.0);
        others.put("ml",1.0);
        unitconvertor.put("Others", others);

        //Constructor Ends
    }
    public double convert(String ingredient, double quantity, String fromUnit, String toUnit) {

        //checking if the ingredient entered exists in the hashmap or not- if not print exception
        if (!unitconvertor.containsKey(ingredient)) {
            throw new IllegalArgumentException("Ingredient not found! Try Again\n");
        }

        //getting ingredient if exists from the map
        Map<String, Double> ingredientConversions = unitconvertor.get(ingredient);

        //checking if fromUnit and toUnit exists in the hashmap or not
        if (!ingredientConversions.containsKey(fromUnit) || !ingredientConversions.containsKey(toUnit)) {
            throw new IllegalArgumentException("Units not found for the given ingredient.\n");
        }

        //getting fromUnit and toUnit from the map
        double fromConversion = ingredientConversions.get(fromUnit);
        double toConversion = ingredientConversions.get(toUnit);

        //returning the converted unit to the function where it is called
        return quantity * fromConversion / toConversion;
    }


    public static void main(String[] args) {

        //introducing the program and telling the ingredients available
        System.out.println("--------WELCOME TO RECIEPE INGREDIENTS CONVERTOR--------");
        System.out.println("!!!!!!!!!NOTE:- Inputs are case sensitive!!!!!!!!!");
        System.out.println("Ingredients available:- ");
        System.out.println("1.Flour\n2.Sugar\n3.Butter\n4.Eggs\n5.General\n6.Liquids\n7.CocoaPowder\n8.Others\n");


        //calling the function - to make it neat and avoid too much information in the main function
        convertfunction();

    }

    static void convertfunction(){

        //Creating object of class
        receipeingredientunitconvertor converter = new receipeingredientunitconvertor();

        //scanner for taking input from user
        Scanner scanner=new Scanner(System.in);

        //taking ingredient (eg- flour,eggs,butter)
        System.out.println("Enter Ingredient:- ");
        String ingredient= scanner.nextLine();


        //taking unit from which we want to convert
        System.out.println("\n\nUnits available:- ");
        //to display all keys (to display all units available for the entered variable)
        unitsAvailable(converter,ingredient);
        String fromUnit= scanner.next().toLowerCase();


        //quantity of ingredient in fromUnit
        System.out.println("Enter quantity in "+ fromUnit+ " :-");
        double quantity=scanner.nextDouble();

        //asking which unit to convert to
        System.out.println("Enter conversion unit (grams/ml)");
        String toUnit=scanner.next();

        //computing value through non-static method 'convert' of class receipeingredientunitconvertor
        double convertedQuantity = converter.convert(ingredient, quantity, fromUnit, toUnit);

        //printing final output
        System.out.println(quantity + " " + fromUnit + " of " + ingredient + " is equal to " + convertedQuantity + " " + toUnit);
    }

    static void unitsAvailable(receipeingredientunitconvertor converter,String ingredient){
        Map<String,Double> mapOfIngredient= converter.unitconvertor.get(ingredient);
        Set keys = mapOfIngredient.keySet();
        Iterator i = keys.iterator();
        while (i.hasNext()) {
            System.out.println(i.next());
        }
    }
}

