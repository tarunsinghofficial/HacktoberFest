public class BackHanded
{
    int state = 0;

    BackHanded(int s)
    {
        state = s;
    }

    public static void main(String... hi)
    {
        BackHanded b1 = new BackHanded(1);
        BackHanded b2 = new BackHanded(2);
        System.out.println(b1.go(b1) + " " + b2.go(b2));
    }

    int go(BackHanded b)
    {
        if (this.state == 2)
        {
            b.state = 5;
            go(this);
        }

        return ++this.state;
    }
}