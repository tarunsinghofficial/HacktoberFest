/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package ta.pkg2;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
/**
 *
 * @author HP
 */
public class TA2 {
    /**
     * @param args the command line arguments
     * @throws java.io.FileNotFoundException
     */
    public static void main(String[] args) throws FileNotFoundException,IOException {
        // TODO code application logic here
        File f = new File("C:\\Users\\HP\\OneDrive\\Desktop\\SEM 4\\Java Programs\\PratPrograms\\TA-2\\src\\ta\\pkg2\\kirana.txt");
        File cust = new File("C:\\Users\\HP\\OneDrive\\Desktop\\SEM 4\\Java Programs\\PratPrograms\\TA-2\\src\\ta\\pkg2\\customers.txt");
        BufferedReader br = new BufferedReader(new FileReader(f));
        Scanner sc = new Scanner(System.in);
        ArrayList<BillCalc> bill = new ArrayList<>(20);
        String str,str1,str1a,str1b,str2,str3,str4,str5,str6,str7,str8,str9,str10;
        LineNumberReader lineNumberReader = new LineNumberReader(new FileReader(f));
        int ch = 0,qtn = 0;
        int count = 0;
        String p;
        do{
            System.out.println("Select a sub-category:");
            while((str = br.readLine())!=null){
                //char[] ch = str.toCharArray();
    //            System.out.println(ch);
                boolean bool = str.matches("^[0-9].*$");
                if(bool){
                    System.out.println(str);
                }
            }
            System.out.println("Your choice??...");
            System.out.println("[Enter '0' to generate bill]...");
            System.out.print("");
            ch = sc.nextByte();
            switch(ch){
                case 1 : 
                    BufferedReader br1 = new BufferedReader(new FileReader(f));
                    BufferedReader br1a = new BufferedReader(new FileReader(f));
                    while(!"2. Dal".equals(str1 = br1.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        boolean bool = Character.isDigit(str1.charAt(0));
                        if(!bool){
                            System.out.println(str1);
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                    }
                    //do{
                        System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"2. Dal".equals(str1a = br1a.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    //lineNumberReader.setLineNumber(count);
                    //System.out.println(count);
                    //System.ouprintln(lineNumberReader.getLineNumber());
                    break;
                case 2:
                    BufferedReader br2 = new BufferedReader(new FileReader(f));
                    BufferedReader br2a = new BufferedReader(new FileReader(f));
                    while (!"3. Rice".equals(str2 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>8)){
                            boolean bool = Character.isDigit(str2.charAt(0));
                            if(!bool){
                                System.out.println(str2);
                            }
                            //count++;
                        }
                    }
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    //if((lineNumberReader.getLineNumber()>8)){
                    count = 0;
                        System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"3. Rice".equals(str1a = br2a.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        count++;
                        if(count > 8){
                        
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        }
                        }
                        
                    //}while(qtn != 0);
                        for(BillCalc b : bill){
                            b.display();
                        }
                    //}
                    break;
                    case 3:
                    BufferedReader br3 = new BufferedReader(new FileReader(f));
                    BufferedReader br3a = new BufferedReader(new FileReader(f));
                    while (!"4. Cooking Oils".equals(str3 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>17)){
                            boolean bool = Character.isDigit(str3.charAt(0));
                            if(!bool){
                                System.out.println(str3);
                            }
                            //count++;
                            //System.out.println(count);
                        }
                    }
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    count = 0;
                    System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"4. Cooking Oils".equals(str1a = br3.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        count++;
                        if(count>17){
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        }
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    break;
                    case 4:
                    BufferedReader br4 = new BufferedReader(new FileReader(f));
                    while (!"5. Snacks".equals(str4 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>26)){
                            boolean bool = Character.isDigit(str4.charAt(0));
                            if(!bool){
                                System.out.println(str4);
                            }
                            //count++;
                            //System.out.println(count);
                        }
                    }
                    count = 0;
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"5. Snacks".equals(str1a = br4.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        count++;
                        if(count>26){
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        }
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    break;
                    case 5:
                    BufferedReader br5 = new BufferedReader(new FileReader(f));
                    while (!"6. Packed Food".equals(str5 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>32)){
                            boolean bool = Character.isDigit(str5.charAt(0));
                            if(!bool){
                                System.out.println(str5);
                            }
                            //count++;
                            //System.out.println(count);
                        }
                    }
                    count = 0;
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"6. Packed Food".equals(str1a = br5.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        count++;
                        if(count>32){
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        }
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    break;
                    case 6:
                    BufferedReader br6 = new BufferedReader(new FileReader(f));
                    while (!"7. Beverages".equals(str6 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>41)){
                            boolean bool = Character.isDigit(str6.charAt(0));
                            if(!bool){
                                System.out.println(str6);
                            }
                            //count++;
                            //System.out.println(count);
                        }
                    }
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    count = 0;
                    System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"7. Beverages".equals(str1a = br6.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        count++;
                        if(count>41){
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        }
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    break;
                    case 7:
                    BufferedReader br7 = new BufferedReader(new FileReader(f));
                    while (!"8. Personal Care".equals(str7 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>48)){
                            boolean bool = Character.isDigit(str7.charAt(0));
                            if(!bool){
                                System.out.println(str7);
                            }
                            //count++;
                            //System.out.println(count);
                        }
                    }
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    count = 0;
                    System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"8. Personal Care".equals(str1a = br7.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        if(count>48){
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        }
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    break;
                    case 8:
                    BufferedReader br8 = new BufferedReader(new FileReader(f));
                    while (!"9. Baby care".equals(str8 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>56)){
                            boolean bool = Character.isDigit(str8.charAt(0));
                            if(!bool){
                                System.out.println(str8);
                            }
                            //count++;
                            //System.out.println(count);
                        }
                    }
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    count=0;
                    System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"9. Baby care".equals(str1a = br8.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        count++;
                        if(count>56){
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        }
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    break;
                    case 9:
                    BufferedReader br9 = new BufferedReader(new FileReader(f));
                    while (!"10.Household and cleaning".equals(str9 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>64)){
                            boolean bool = Character.isDigit(str9.charAt(0));
                            if(!bool){
                                System.out.println(str9);
                            }
                            //count++;
                            //System.out.println(count);
                        }
                    }
                    System.out.println("hi");
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    count=0;
                    System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"10.Household and cleaning".equals(str1a = br9.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        count++;
                        if(count>64){
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        }
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    break;
                    case 10:
                    BufferedReader br10 = new BufferedReader(new FileReader(f));
                    while (!"end".equals(str10 = lineNumberReader.readLine())){
                        if((lineNumberReader.getLineNumber()>69)){
                            boolean bool = Character.isDigit(str10.charAt(0));
                            if(!bool){
                                System.out.println(str10);
                            }
                            //count++;
                            //System.out.println(count);
                        }
                    }
                    //System.out.println(count);
                    //lineNumberReader.setLineNumber(count);
                    count=0;
                    System.out.println("Enter you product choice:");
                        p = sc.next();
                        System.out.println("Enter Quantity:");
                        qtn = sc.nextInt();
                        System.out.println(qtn);
                        while(!"end".equals(str1a = br10.readLine())){
                        //char[] ch = str.toCharArray();
                        //            System.out.println(ch);
                        count++;
                        if(count>69){
                        str1b = str1a;
                        //System.out.println(str1a);
                        String[] dsplit = str1a.split("\\.");
                        //System.out.println(dsplit[0]);
                        if(dsplit[0].equals(p)){
                            //System.out.println(dsplit[1]);
                            String[] csplit = dsplit[1].split(",");
                            //System.out.println(qtn);
                            for(int z = 0; z < qtn; z++){
                                //System.out.println("hi");
                                if(Integer.parseInt(csplit[2])!=0)
                                    bill.add(new BillCalc(csplit[0],Double.parseDouble(csplit[1]),Integer.parseInt(csplit[2])));
                                else
                                    System.out.println("Out of Stock!");
                            }
                            
                        }
                        //count++;
//                        String[] ssplit = str1.split(",");
                        
                        }
                        }
                    //}while(qtn != 0);
                    for(BillCalc b : bill){
                        b.display();
                    }
                    break;
                    case 11:
                        System.out.println("Bill");
                        break;
            }    
        }while(ch != 0);
        //double amt = BillCalc.rawBill(bill);
        System.out.println("Do you want to remove items from?[Yes/No]");
        if(sc.next().equals("Yes")){           
            ArrayList<BillCalc> needToRemove = new ArrayList<>(20);
            System.out.println("Enter no of elements to remove..");
            int toRemove = sc.nextInt();
            System.out.println("Enter elements to remove[to stop enter 'stop']...");
            for(int i = 0; i < toRemove; i++){
                BillCalc ntr;
                ntr = bill.get(sc.nextInt());
                needToRemove.add(ntr);
            }
            //needToRemove.add(bill.get(sc.nextInt()));
//            for(BillCalc b : needToRemove){
//                b.display();
//            }
            bill.removeAll(needToRemove);
            System.out.println("Cart Items..");
            for(BillCalc b : bill){
                b.display();
            }
        }
        double amt = BillCalc.rawBill(bill);
        String pts = null;
        //System.out.println(amt);
        System.out.println("Are you already a member?[Yes/No]..");
        Scanner sc1 = new Scanner(System.in);
        String isMem = sc1.next();
        if(isMem.equals("Yes")){
            System.out.println("Enter your name(in capital):");
            String cName = sc1.next();
            BufferedReader cbr = new BufferedReader(new FileReader(cust));
            String cus;
            while((cus=cbr.readLine())!=null){
                if(cus.equals("Customer Name: "+cName)){
                    cbr.readLine();
                    cus = cbr.readLine();
                    String[] ssplit=cus.split(":");
                    pts = (ssplit[1]);
                    break;
                }
            }
            System.out.println("Your current points are: "+pts);
            if(Integer.parseInt(pts)>20){
                System.out.println("You are eligible for discount!");
            //System.out.println("Do you want to use points??");
            //if(sc.next().equals("Yes")){
                String oldContent = "";
                BufferedReader reader = new BufferedReader(new FileReader(cust));
                String line = reader.readLine();

                while (line != null){
                        oldContent = oldContent + line + System.lineSeparator();
                        line = reader.readLine();
                }
                String pStr;
                int newPts = Integer.parseInt(pts);
                System.out.println("Do you want to use points??");
                if(sc.next().equals("Yes")){
                    pStr = Double.toString(newPts-20);
                    amt = amt - 0.2*amt;
                    //String newContent = oldContent.replace(pts, pStr);
                }
                else{
                    pStr = Double.toString(newPts+20);
                    //String newContent = oldContent.replace(pts, pStr);
                }
                String newContent = oldContent.replace(pts, pStr);
                FileWriter writer = new FileWriter(cust);
                writer.write(newContent);
                reader.close();
                writer.close();
            //}
        }
        else{
                System.out.println("You don't have enough points");
        }
        }
        else{
            System.out.println("Do you want to become a member?[Yes/No]");
            String newM = sc1.next();
            if(newM.equals("Yes")){
               System.out.println("Enter your details:");
               FileWriter fw = new FileWriter(cust, true);
               BufferedWriter bw = new BufferedWriter(fw);
               bw.newLine();
               bw.write("Customer Name: "+sc1.next());
               bw.newLine();
               bw.write("ID:23");
               bw.newLine();
               bw.write("POINTS:20");
               bw.newLine();
               bw.write("CONTACT NO: "+sc1.next());
               bw.close();
            }
            else{
                
                System.out.println(amt);
            }
        }
        System.out.println(amt);
        for(BillCalc b : bill){
            //System.out.println(b.pname);
            b.stockDecrement(b.pname);
        }
        
        //for(BillCalc b : bill){
            //System.out.println(b.pname);
        BillCalc billc = new BillCalc("",0,0);
        billc.billDisplay(bill,amt);
        //}
        //BillCalc.stockDecrement(bill);
    }
    
}