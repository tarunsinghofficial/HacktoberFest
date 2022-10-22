
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ta.pkg2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author HP
 */

public class BillCalc {   
    String pname;
    double cost;
    int quant;
    BillCalc(String pname, double cost, int quant){
        this.pname = pname;
        this.cost = cost;
        this.quant = quant;
    }
    void display(){
        System.out.println("Product Name: "+pname+"Price: "+cost+"Quantity: "+quant);
    }
    
    String getName(){
        return pname;
    }
    
    double getCost(){
        return cost;
    }
    static double rawBill(ArrayList<BillCalc> bill){
        double amt=0;
        for (BillCalc b : bill) {
            amt += b.cost;
        }
        return amt;
    }
    
    void billDisplay(ArrayList<BillCalc> bl, double amt){
        System.out.println("--------------------------------------BILL--------------------------------------");
        System.out.println("---------------------------------------------------------------|----------------");
        System.out.println("Product Name                                                   |         Price     ");
        for(BillCalc b : bl){
            System.out.println(b.pname+"\t\t\t\t\t\t"+b.cost);
        }
                            //Hindustan Unilever Limited owns the Annapurna atta brand(0 kg)
        System.out.println("---------------------------------------------------------------|----------------");
        System.out.println("                   Total Amount After Discount                 | "+amt);
    }
    
    void stockDecrement(String dname) throws FileNotFoundException, IOException{
        File f;
        f = new File("C:\\Users\\HP\\OneDrive\\Desktop\\SEM 4\\Java Programs\\PratPrograms\\TA-2\\src\\ta\\pkg2\\kirana.txt");
        String pts = null,name1;
        //System.out.println(amt);
        //System.out.println("Are you already a member?[Yes/No]..");
        //Scanner sc1 = new Scanner(System.in);
        //String isMem = sc1.next();
        //if(isMem.equals("Yes")){
            //System.out.println("Enter your name(in capital):");
            //String cName = sc1.next();
            BufferedReader cbr = new BufferedReader(new FileReader(f));
            String cus;
            String[] name = null;
            String[] ssplit = null;
            while((cus=cbr.readLine())!=null){
                ssplit = cus.split("\\.");
                name = ssplit[1].split(",");
//                name1 = dcr.pname;
                if(dname.equals(name[0])){
                    pts = (name[2]);
                    break;
                }
            }
            //System.out.println("Your current points are: "+pts);
            if(Integer.parseInt(pts)>0){
                //System.out.println("You are eligible for discount!");
            //System.out.println("Do you want to use points??");
            //if(sc.next().equals("Yes")){
                String oldContent = "";
                BufferedReader reader = new BufferedReader(new FileReader(f));
                String line = reader.readLine();

                while (line != null){
                        oldContent = oldContent + line + System.lineSeparator();
                        line = reader.readLine();
                }
                String[] pStr;
                pStr = pts.split("\\|");
                int newPts = Integer.parseInt(pStr[0]);
//                System.out.println("Do you want to use points??");
//                if(sc.next().equals("Yes")){
                    //pStr = Integer.toString(newPts-1);
                    //String newContent = oldContent.replace(pts, pStr);
                //}
//                else{
//                    pStr = Double.toString(newPts+20);
//                    //String newContent = oldContent.replace(pts, pStr);
//                }
                String newContent = oldContent.replace(pts+".|", Integer.toString(newPts-1)+".|");
                
                FileWriter writer = new FileWriter(f);
                writer.write(newContent);
                reader.close();
                writer.close();
               }
    }
}
