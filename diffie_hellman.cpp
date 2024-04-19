#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int p, g;

	cout << "Enter the values of p and g" << endl;
	cin >> p >> g;

	int a, b;

	cout << endl;
	cout << "Enter the value of a" << endl;
	cin >> a;

	// DH half key of Alice
	int ka = pow(g, a);
	ka %= p;

	cout << "Enter the value of b" << endl;
	cin >> b;

	// DH half key of Bob
	int kb = pow(g, b);
	kb %= p;

	// Shared secret key calculated by Alice
	int k = pow(kb, a);
	k %= p;

	cout << endl;
	cout << "Shared secret key calculated by Alice: " << k << endl;

	// Shared secret key calculated by Bob
	int k2 = pow(ka, b);
	k2 %= p;

	cout << "Shared secret key calculated by Bob: " << k2 << endl;

	return 0;
}
