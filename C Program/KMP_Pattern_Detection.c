#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(char *pattern, int len, int *lps)
{
    int prev_len = 0; // stores length of prev. longest pref that's suffix too
    int i;

    lps[0] = 0; // (trivial)
    i = 1;

    // processing lps from index : 1 to len-1
    while (i < len)
    {
        if (pattern[i] == pattern[prev_len])
        {
            prev_len++;
            lps[i] = prev_len;
            i++;
        }
        else // mismatch
        {
            if (prev_len != 0)
                prev_len = lps[prev_len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void find_pattern_KMP(char *pattern, char *word)
{
    int len1 = strlen(pattern), len2 = strlen(word);

    int *lps = (int *)malloc(sizeof(int) * len1); // to hold the longest match between prefix and suffix
    int j = 0;
    computeLPSArray(pattern, len1, lps); // pattern based lps computation

    int i = 0;
    while (i < len2)
    {
        if (pattern[j] == word[i])
        {
            j++;
            i++;
        }
        if (j == len1)
        {
            printf("Pattern Detected at : index = %d\n", i - j);
            j = lps[j - 1];
        }
        // when mismatch occured
        else if (i < len2 && pattern[j] != word[i])
        {
            if (j != 0)
                j = lps[j - 1]; // for non-zero lengthed matches
            else
                i = i + 1;
        }
    }
    free(lps); // recycling memory
}

// Driver program to test above function
int main()
{
    char *word = "RealabraMagicadabra";
    char *pattern = "abra";
    find_pattern_KMP(pattern, word);
    return 0;
}
