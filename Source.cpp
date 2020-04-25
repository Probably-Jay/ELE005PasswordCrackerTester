// Written by Jake Bretherton to demonstrate the scaling of passwords with different character sets

#include <vector>
#include <string>
using namespace std;

vector<vector<char>> characterRange;
vector<char> lowercase = { 'a','z' };
vector<char> upercase = { 'A','Z' };
vector<char> numbers = { '0','9' };
vector<char> all_including_special = { ' ','~' };

void AddOne(string& s, int offset = 0) {

	int currentCharType = 0;
	for (int i = 0; i < characterRange.size(); i++) {
		if (s[offset] >= characterRange[i][0] && s[offset] <= characterRange[i][1]) {
			currentCharType = i;
		}
	}
	if (offset == s.size()) {
		s.push_back(characterRange[0][0]);
		return;
	}
	char n = ++s[offset];
	if (n <= characterRange[currentCharType][1]) {
		s[offset] = n;
		return;
	}
	else {
		if (currentCharType < characterRange.size() - 1) {
			currentCharType++;
			s[offset] = characterRange[currentCharType][0];
		}
		else {
			currentCharType = 0;
			s[offset] = characterRange[0][0];
			AddOne(s, ++offset);
		}
	}
}



void BruteForce(string password) {
	string guess = "";
	guess += characterRange[0][0];
	while (guess != password)
	{
		AddOne(guess);
	}
}


