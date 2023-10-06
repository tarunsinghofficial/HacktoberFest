//Program to compute sums of given query ranges on array

import java.util.*;

class Query
{                                                      // Class to represent a query range
	int L;
	int R;
	Query(int L, int R)
  {
		this.L = L;
		this.R = R;
	}
}

class MO
{
	static void queryResults(int a[], int n, ArrayList<Query> q, int m)                              //n --> size of arr , m -->no of queries
  {
		int block = (int) Math.sqrt(n);                                                  //sq root decomposition block size
	
		Collections.sort(q, new Comparator<Query>()                           // Sort all queries so that queries of same block are arranged together, same block must hve R in asc order
    {			
			public int compare(Query x, Query y)
      {
				if (x.L/block != y.L/block)                                        // Different blocks, sort by block
					return (x.L < y.L ? -1 : 1);

				return (x.R < y.R ? -1 : 1);                                      	// Same block, sort by R value asc order
			}
		});

		int currL = 0, currR = 0;  
		int currSum = 0;
	
		for (int i=0; i<m; i++)                                                   // Traverse through all queries
		{
			int L = q.get(i).L, R = q.get(i).R;
			while (currL < L)                                            // Remove extra elements of previous range
			{
				currSum -= a[currL];
				currL++;
			}
			while (currL > L)                                            // Add Elements of current Range
			{
				currSum += a[currL-1];
				currL--;
			}
			while (currR <= R)
			{
				currSum += a[currR];
				currR++;
			}
			while (currR > R+1)                                  // Remove elements of previous range
			{
				currSum -= a[currR-1];
				currR--;
			}

			System.out.println("Sum of [" + L +
						", " + R + "] is " + currSum);
		}
	}

	// Driver program
	public static void main(String argv[])
  {
		ArrayList<Query> q = new ArrayList<Query>();
		q.add(new Query(0,4));
		q.add(new Query(1,3));
		q.add(new Query(2,4));

		int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
		queryResults(a, a.length, q, q.size());
	}
}
