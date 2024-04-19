package com.jdbc.repo;


import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DataConnection
{
    public static Connection getDBconnection()
    {
        Connection connectionString=null;
        try
        {
            Class.forName("com.mysql.jdbc.Driver");

            connectionString= DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbcdemo?characterEncoding=utf8","root","password");
        }
        catch (ClassNotFoundException e)
        {
            System.out.println("Where is JDBC class?");
        }
        catch(SQLException s)
        {
            System.out.println("Connection Failed...!");
            s.printStackTrace();
            System.out.println("=================================================================");
            System.out.println(s.toString());
        }

        if(connectionString!=null)
        {
            System.out.println("Connected Succesfully...!");
        }
        return connectionString;
    }
}
