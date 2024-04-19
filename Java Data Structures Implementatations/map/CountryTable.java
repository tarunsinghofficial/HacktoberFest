/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package map;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class CountryTable {

public String name, language;
public int area, population;

public CountryTable(String name, String language, int area, int population) {
    this.name = name;
    this.language = language;
    this.area = area;
    this.population = population;
}

    @Override
    public String toString() {
       return "("+name+","+language+","+area+","+population+")";
             
    }

}
