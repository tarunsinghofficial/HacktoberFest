import java.io.*;
import java.util.*;
 class Matrix {
    int row;
    int col;
    int[][] a;
        public Matrix(int r, int c)
    {
        row = r;
        col = c;
        a = new int[row][col];
    }
        public int getrow()
    {
        return row;
    }
    public int getcol()
    {
        return col;
    }
    public int getelement(int r, int c)
    {
        return a[r][c];
    }
    public void setelement(int r, int c, int value)
    {
        a[r][c] = value;
    }
    public static Matrix add(Matrix a, Matrix b)
    {
        if((a.row != b.row) || (a.col != b.col))
        {
          System.out.println("Matrices can not be added");
          return new Matrix(0,0);
        }
        else
        {
          Matrix m = new Matrix(a.row,a.col);
          for(int i = 0;i<m.row;i++)
          {
            for(int j = 0;j<m.col;j++)
            {
              m.setelement(i,j,(a.getelement(i,j)+b.getelement(i,j)));
            }
          }
          return m;
        }
    }
    public static Matrix mult(Matrix a, Matrix b)
    {
      Matrix m = new Matrix(a.row,b.col);
      for(int i = 0;i<a.row;i++)
      {
        for(int j = 0;j<b.col;j++)
        {
          int s = 0;
          for(int k = 0;k<a.col;k++)
          {
            s = s+(a.getelement(i,k)*b.getelement(k,j));
        
          }
          m.setelement(i,j,s);
        }
      }
 
      return m;
    }
       public void printmat()
    {
  
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
              System.out.print(a[i][j]+"	");
            }
            System.out.println("");

         }
    }
}