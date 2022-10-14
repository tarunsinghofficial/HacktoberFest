#include <stdio.h>
 
int main()
{
    int a = 10, b = 0, c = 10;
 
    // The given program will generate a rough ouline of India
    char* str = "TFy!QJu ROo TNn(ROo)SLq SLq ULo+UHs UJq "
                "TNn*RPn/QPbEWS_JSWQAIJO^NBELPeHBFHT}TnALVlBL"
                "OFAkHFOuFETpHCStHAUFAgcEAelclcn^r^r\\tZvYxXyT|S~Pn SPm "
                "SOn TNn ULo0ULo#ULo-WHq!WFs XDt!";
 
    while (a != 0)
    {
        // read each character of encoded string
        a = str[b++];
        while (a-- > 64)
        {
            if (++c == 90) // 'Z' is 90 in ascii
            {
                // reset c to 10 when the end of line is reached
                c = 10;        // '\n' is 10 in ascii
 
                // print newline
                putchar('\n'); // or putchar(c);
            }
            else
            {
                // draw the appropriate character
                // depending on whether b is even or odd
                if (b % 2 == 0)
                    putchar('!');
                else
                    putchar(' ');
            }
        }
    }
 
    return 0;
}
