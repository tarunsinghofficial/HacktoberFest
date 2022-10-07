import com.jdbc.repo.DataConnection;
import com.jdbc.repo.RealCode;
import com.jdbc.repo.RunScript;

import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Runner
{
    public static void main(String[] args) throws IOException, SQLException {
        Connection con= DataConnection.getDBconnection();
        RunScript.run();
        RealCode db=new RealCode();
        System.out.println(db.insertSubject("Physics"));
        System.out.println(db.insertSubject("Maths"));
        System.out.println(db.insertSubject("Chemistry"));

        ResultSet res= db.getAllSubjects();
        while(res.next())
        {
            System.out.print(res.getInt(1));
            System.out.println("     "+res.getString(2));
        }

        db.insertStudent("Prsad",70,"Computer Science");
        System.out.println(db.getStudentyId(2));
        ResultSet ress= db.getAllStudents();
        while(ress.next())
        {
            System.out.print(ress.getInt(1));
            System.out.print("     "+ress.getString(2));
            System.out.print("     "+ress.getFloat(3));
            System.out.println("     "+ress.getInt(4));
        }
    }
}
