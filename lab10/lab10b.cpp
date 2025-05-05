// Program to calculate players' scores based on word uniqueness
#include <bits/stdc++.h>
using namespace std;


vector<int> game();

int main() {
    int testCases;
    cout << "Enter the number of test cases: ";
    cin >> testCases;
    
    while (testCases--) {
        vector<int> scores = game();
        cout << "Scores: " << scores[0] << " " << scores[1] << " " << scores[2] << "\n";
    }

    return 0;
}

// Function that returns players' scores 
vector<int> game() {
    int wordCount;
    cout << "Enter the number of words: ";
    cin >> wordCount;
    
    vector<vector<string>> playerWords(3, vector<string>(wordCount));
    unordered_map<string, int> wordFrequency;
    
    for (int player = 0; player < 3; player++) {
        if (wordCount==1) cout << "Enter " << wordCount << " word for player " << player + 1 << ": ";
        else
        {
            cout << "Enter " << wordCount << " words for player " << player + 1 << ": ";
        }
        for (int index = 0; index < wordCount; index++) {
            cin >> playerWords[player][index];
            wordFrequency[playerWords[player][index]]++;
        }
    }

    vector<int> playerScores(3, 0);
    for (int player = 0; player < 3; player++) {
        for (int index = 0; index < wordCount; index++) {
            string word = playerWords[player][index];
            if (wordFrequency[word] == 1) playerScores[player] += 3;
            else if (wordFrequency[word] == 2) playerScores[player] += 1;
        }
    }

    return playerScores;
}