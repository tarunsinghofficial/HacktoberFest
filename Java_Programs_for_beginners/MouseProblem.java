class Abc
{
	public static void main(String argsz[])
	{
		int size=(int)(Math.random()*20);
		char ch[][]=new char[size][size];
			for(int i=0;i<size;i++)
			{
				for(int j=0;j<size;j++)
				{
					ch[i][j]='-';
				}
	}
	for(int i=0;i<size;i++)
			{
		for(int j=0;j<size;j++)
				{
			System.out.print(ch[i][j]);
				}
				System.out.println();
			}
			int x=(int)(Math.random()*size);
				int y=(int)(Math.random()*size);
				ch[x][y]='*';
				System.out.println();

				for(int i=0;i<size;i++)
			{
		for(int j=0;j<size;j++)
				{
			System.out.print(ch[i][j]);
				}
				System.out.println();

			}
		}
	}