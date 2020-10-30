import java.util.*;
public class DecBin
{
private long low,upp;
public DecBin(long l,long u)
{
low=l;
upp=u;
}
public long convertToBin(long num)
{
if(num==0)
return 0;
else
return(num%2+10 * (convertToBin(num/2)));
}
public void generate()

{
Long binCon;
for(long i=low; i<=upp; i++)
{
binCon = convertToBin(i);
System.out.println(binCon);
}
}
public static void main(String args[])
{
Scanner Sc = new Scanner (System.in);
long l,u;
System.out.println("Enter a lower limit");
l= Sc.nextLong();
System.out.println("Enter an upper limit");
u =Sc.nextLong();
DecBin obj = new DecBin(l,u);
obj.generate();
}
}
