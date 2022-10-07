package com.jdbc.repo;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class RealCode
{
    Connection con;
    public RealCode() {
        con = DataConnection.getDBconnection();
    }
    public boolean insertSubject(String name) throws SQLException {
        String q="insert into subject(name) values(?);";
        PreparedStatement pst= con.prepareStatement(q);
        pst.setString(1,name);
        return pst.execute();
    }
    public ArrayList getSubjectById(int id) throws SQLException {
        List<Object> out=new ArrayList<Object>();
        String q="select * from subject where id=?;";
        PreparedStatement pst= con.prepareStatement(q);
        pst.setInt(1,id);
        ResultSet res=pst.executeQuery();
        while(res.next())
        {
            out.add(res.getInt(1));
            out.add(res.getString(2));
        }
        return (ArrayList) out;
    }
    public ResultSet getAllSubjects() throws SQLException {
        String q="select * from subject;";
        PreparedStatement pst= con.prepareStatement(q);
        ResultSet res=pst.executeQuery();
        return res;
    }
    public boolean insertStudent(String student_name, float score, String name) throws SQLException {
        String q="select * from subject where name=?;";
        PreparedStatement pst= con.prepareStatement(q);
        pst.setString(1,name);
        ResultSet checkres=pst.executeQuery();
        if(checkres.next())
        {
            String nq="insert into student(student_name,score,subject_id) values(?,?,?)";
            PreparedStatement npst= con.prepareStatement(nq);
            npst.setString(1,student_name);
            npst.setFloat(2,score);
            npst.setInt(3,checkres.getInt(1));
            return npst.execute();

        }
        insertSubject(name);
        return insertStudent(student_name,score,name);

    }
    public ArrayList getStudentyId(int id) throws SQLException {
        List<Object> out=new ArrayList<Object>();
        String q="select * from student where id=?;";
        PreparedStatement pst= con.prepareStatement(q);
        pst.setInt(1,id);
        ResultSet res=pst.executeQuery();
        while(res.next())
        {
            out.add(res.getInt(1));
            out.add(res.getString(2));
            out.add(res.getFloat(3));
            out.add(res.getInt(4));

        }
        return (ArrayList) out;
    }
    public ResultSet getAllStudents() throws SQLException {

        String q="select * from student;";
        PreparedStatement pst= con.prepareStatement(q);
        ResultSet res=pst.executeQuery();
        return res;
    }

}

