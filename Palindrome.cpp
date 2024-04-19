bool isPalindrome(long x){

long reversed_number=0;
int a=x;
if(x<0)
{
    return false;
    return 0;
}

 if(x>=0 && x<=9)
{
    return true;
    return 0;
}
if(x%10==0)
{
    return false;
}

if(x>=-2^31||x<=2^31-1)
{

    while(x>0)
    {
        reversed_number=reversed_number*10 + x%10;
        x/=10;
    }
}


if(a==reversed_number)
{
    return true;
}
return false;
}
