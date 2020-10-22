/* C/C++ program to remove invalid parenthesis */
#include <bits/stdc++.h> 
using namespace std; 

// method checks if character is parenthesis(open 
// or closed) 
bool isParenthesis(char c) 
{ 
	return ((c == '(') || (c == ')')); 
} 

// method returns true if string contains valid 
// parenthesis 
bool isValidString(string str) 
{ 
	int cnt = 0; 
	for (int i = 0; i < str.length(); i++) 
	{ 
		if (str[i] == '(') 
			cnt++; 
		else if (str[i] == ')') 
			cnt--; 
		if (cnt < 0) 
			return false; 
	} 
	return (cnt == 0); 
} 

// method to remove invalid parenthesis 
void removeInvalidParenthesis(string str) 
{ 
	if (str.empty()) 
		return ; 

	// visit set to ignore already visited string 
	set<string> visit; 

	// queue to maintain BFS 
	queue<string> q; 
	string temp; 
	bool level; 

	// pushing given string as starting node into queue 
	q.push(str); 
	visit.insert(str); 
	while (!q.empty()) 
	{ 
		str = q.front(); q.pop(); 
		if (isValidString(str)) 
		{ 
			cout << str << endl; 

			// If answer is found, make level true 
			// so that valid string of only that level 
			// are processed. 
			level = true; 
		} 
		if (level) 
			continue; 
		for (int i = 0; i < str.length(); i++) 
		{ 
			if (!isParenthesis(str[i])) 
				continue; 

			// Removing parenthesis from str and 
			// pushing into queue,if not visited already 
			temp = str.substr(0, i) + str.substr(i + 1); 
			if (visit.find(temp) == visit.end()) 
			{ 
				q.push(temp); 
				visit.insert(temp); 
			} 
		} 
	} 
} 

// Driver code to check above methods 
int main() 
{ 
	string expression = "()())()"; 
	removeInvalidParenthesis(expression); 

	expression = "()v)"; 
	removeInvalidParenthesis(expression); 

	return 0; 
} 
