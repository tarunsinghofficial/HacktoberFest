// Complete this function
char nonrepeatingCharacter(string s)
{
   int chars = 256;
   int n = s.size();
   
   int arr[chars];
   fill(arr, arr+chars, 0);
   
   for(int i=0;i<n;i++){
       arr[s[i]]++;
   }
   
   // 1 1 2 1
   
   for(int i=0;i<n;i++){
       if(arr[s[i]] == 1)
            return (char)s[i];
   }
   
   return '$';
   
}
