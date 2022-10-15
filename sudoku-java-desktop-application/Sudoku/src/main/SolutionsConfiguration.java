package main;

import java.util.ArrayList;

public final class SolutionsConfiguration 
{
public static Board original;
public  ArrayList<Integer> solnset;
//IIB:
{
solnset=new ArrayList<Integer>(0);	
}
public SolutionsConfiguration()
{
//default constructor
}
public SolutionsConfiguration(ArrayList<Integer> arry)
{
this.solnset=arry;
}
public void fillInto(Board b)
{
int[][][] arr=b.getStorage();
int index=0;
ITERATOR_LAB:
for(int i=0;i<3;++i)
{
 for(int j=0;j<3;++j)
 {
	 for(int k=0;k<9;++k)
	 {
		 if(index>=this.solnset.size())
		 {break ITERATOR_LAB;}
		 if(arr[i][j][k]!=0)
		 {continue;}
		 int x=this.solnset.get(index);
		 arr[i][j][k]=x;
		 ++index;
	 }
 }
}

}
public static SolutionsConfiguration extractSolnConfig(Board modified)
{
ArrayList<Integer> config=new ArrayList<>(0);
for(int i=0;i<3;++i)	
{
for(int j=0;j<3;++j)
 {
  for(int k=0;k<9;++k)
  {
	  int og=original.getStorage()[i][j][k];
	  int naya=modified.getStorage()[i][j][k];
	  if(og!=naya)
	  {config.add(naya);}
  }
 }
}
return new SolutionsConfiguration(config);
}

public boolean isSolved()
{
return this.solnset.size()==original.emptyTiles();
}

public static ArrayList<SolutionsConfiguration> extractSolnConfigs(ArrayList<Board> mods)
{
 ArrayList<SolutionsConfiguration> ab=new ArrayList<>(0);
 for(Board b:mods)
 {
	 ab.add(extractSolnConfig(b));
 }
 return ab;
}

}

