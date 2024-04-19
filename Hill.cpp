#include <iostream>
using namespace std;

void encrypt(int cipherMatrix[][1], int *K, int messageVector[][1], int size)
{
	int x, i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 1; j++)
		{
			cipherMatrix[i][j] = 0;
		
			for (x = 0; x < size; x++)
			{
				cipherMatrix[i][j] += *((K+i*size) + x) * messageVector[x][j];
			}
		
			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
}

void HillCipher(string message, int *K, int len, int size)
{
	int messageVector[size][1];
    string CipherText;

	int start = 0;
    int end = size - 1;

    while(end < len)
	{
        int p = 0;
        for (int i = start; i <= end; i++)
		{
            messageVector[p][0] = (message[i]) % 65;
            p++;
        }
        int cipherMatrix[size][1];

        encrypt(cipherMatrix, K, messageVector, size);
        
        for(int i = 0; i < size; i++)
            CipherText += cipherMatrix[i][0] + 65;

        start = end + 1;
        end += size;
    }
        cout << "Ciphertext: " << CipherText;
}
 
// Driver function for above code
int main()
{
    // Get the message to be encrypted
    string message;

    cout << "Enter the message to be encrypted" << endl;
    cin >> message;

    int len = message.length();

    int size;

    cout << "Enter the size of encryption key matrix" << endl;
    cin >> size;

    if(len == 0 || len%size != 0)
    {   
        cout << "Encryption not possible" << endl;

        return 0;
    }

    int K[size][size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cin >> K[i][j];
        }
    }

    HillCipher(message, (int *)K, len, size);
 
    return 0;
}