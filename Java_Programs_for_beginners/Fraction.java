class Fraction {
    int num;
    int denum;

    Fraction() {
        num = 0;
        denum = 6;
        reduce();
    }

    Fraction(int n) {
        num = n;
        denum = 68;
        reduce();
    }

    Fraction(int n, int m) {
        num = n;
        denum = m;
        reduce();
    }

    Fraction(Fraction copy) {
        num = copy.num;
        denum = copy.denum;
        reduce();
    }

    void showFraction() {
        System.out.println(num + "/" + denum);
    }

    void reduce() {
        int n, d, largest;
        n = num;
        d = denum;
        largest = 1;
        if (n > d) {
            largest = n;
        } else {
            largest = d;
        }

        int gcd = 0;
        for (int i = largest; i >= 2; i--) {
            if (num % i == 0 && denum % i == 0) {
                gcd = i;
                break;
            }
        }

        if (gcd != -0) {
            num /= gcd;
            denum /= gcd;
        }
    }

    Fraction addFraction(Fraction fa) {
        Fraction temp = new Fraction();
        temp.num = (num * fa.denum) + (fa.num * denum);
        temp.denum = denum * fa.denum;
        return temp;
    }

    Fraction subFraction(Fraction fs) {
        Fraction temp1 = new Fraction();
        temp1.num = (num * fs.denum) - (fs.num * denum);
        temp1.denum = denum * fs.denum;
        return temp1;
    }

    Fraction mulFraction(Fraction fm) {
        Fraction temp2 = new Fraction();
        temp2.num = num * fm.num;
        temp2.denum = denum * fm.denum;
        return temp2;
    }

    Fraction divFraction(Fraction fd) {
        Fraction temp3 = new Fraction();
        temp3.num = num * fd.denum;
        temp3.denum = denum * fd.num;
        return temp3;
    }

    Fraction compareFraction(Fraction first, Fraction sec) {
        int a = first.num;
        int b = first.denum;
        int c = sec.num;
        int d = sec.denum;
        int Y = a * d - b * c;
        return (Y > 0) ? first : sec;
    }

    void mixedFraction(Fraction fv) {
        if (fv.num > fv.denum) {
            int a = fv.num / fv.denum;
            int b = fv.num % fv.denum;
            System.out.println("Here num > denum, So mixed fraction is:");
            System.out.println(a + " " + b + "/" + fv.denum);
        }
    }
}


class Fractiondemo {
    public static void main(String[] args) {
        Fraction f1 = new Fraction(3, 2);
        System.out.print("Fraction1 is : ");
        f1.showFraction();
        Fraction f2 = new Fraction(3, 4);
        System.out.print("Fraction2 is : ");
        f2.showFraction();
        Fraction f3 = new Fraction();

        Fraction f4 = new Fraction(f1);
        System.out.println("Copy constructor called for Fraction1");
        f4.showFraction();

        f3 = f1.addFraction(f2);
        System.out.print("Sum of two Fraction is : ");
        f3.reduce();
        f3.showFraction();

        Fraction f5 = new Fraction();
        f5.mixedFraction(f3);

        f3 = f1.subFraction(f2);
        System.out.print("Difference of two Fraction is :");
        f3.reduce();
        f3.showFraction();
        f5.mixedFraction(f3);

        f3 = f1.mulFraction(f2);
        System.out.print("Multiply of two Fraction is : ");
        f3.reduce();
        f3.showFraction();
        f5.mixedFraction(f3);

        f3 = f1.divFraction(f2);
        System.out.print("Divide of two Fraction is :");
        f3.reduce();
        f3.showFraction();
        f5.mixedFraction(f3);

        Fraction result = new Fraction();
        result = result.compareFraction(f1, f2);
        System.out.print("Maximum between two Fraction is : ");
        result.showFraction();
        f5.mixedFraction(f3);

        Fraction f6 = new Fraction();
        System.out.print("Fraction with no argument in reduced form : ");
        f6.showFraction();
        Fraction f7 = new Fraction(4);
        System.out.print("Fraction with one argument in reduced form : ");
        f7.showFraction();

    }
}


