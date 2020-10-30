        #include <iostream>
        #include <bits/stdc++.h>
        
        using namespace std;
        
        void
        swapi (int *a, int *b)
        {
          int t = *a;
          *a = *b;
          *b = t;
          // cout << *a << " " << *b << endl;
        }
        
        
        vector < int >
InsertionSort (vector < int >arr, int n)
{
  int i, j, tp = 0;

  for (i = 1; i < n; i++)
    {
      j = i - 1;
      tp = arr[i];
      while (j >= 0 && arr[j] > tp)
	{
	  arr[j + 1] = arr[j];
	  j--;
	}
      arr[j + 1] = tp;
    }

  return arr;
}
        
        
        
        int
        main ()
        {
        //   cout << "Hello World\n";
          std::vector < int >vec;
          vec = {202, 4, -5, 66, -2, 0, 96, 5, 78, 12, 48, 88};
        
          vec = InsertionSort (vec, vec.size());
            for (int x:vec)
            {
              cout << x << " ";
            }
          return 0;
        }
