// C++ program to find winner in an election.

#include "bits/stdc++.h"
using namespace std;
 
void findWinner(vector<string>& votes)
{

	// Insert all votes in a hashmap
	unordered_map<string, int> mapObj;
	for (auto& str : votes) {
		mapObj[str]++;
	}

	// Traverse through map to find the candidate
	// with maximum votes.
	int maxValueInMap = 0;
	string winner;
	for (auto& entry : mapObj) {
		string key = entry.first;
		int val = entry.second;
		if (val > maxValueInMap) {
			maxValueInMap = val;
			winner = key;
		}

		// If there is a tie, pick lexicographically
		// smaller.
		else if (val == maxValueInMap && winner > key)
			winner = key;
	}
	cout << winner << endl;
}

 
int main()
{
	vector<string> votes
		= { "john", "johnny", "jackie", "johnny",
			"john", "jackie", "jamie", "jamie",
			"john", "johnny", "jamie", "johnny",
			"john" };

	findWinner(votes);
	return 0;
}
