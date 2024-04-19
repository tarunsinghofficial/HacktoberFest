package com.jdbc.repo;

import java.io.*;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

public class RunScript
{
    public static void run() throws IOException, SQLException
    {
        File currentDir = new File(".");
        File parentDir = currentDir.getParentFile();
        File newFile = new File(parentDir,"db.sql");;
        InputStreamReader reader= new FileReader(newFile);
        BufferedReader red= new BufferedReader(reader);
        String line=null;
        Connection con=DataConnection.getDBconnection();
        while((line=red.readLine())!=null)
        {

            Statement st= con.createStatement();
            st.execute(line);

        }
    }

}
