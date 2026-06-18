#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cctype>

using namespace std;

struct Compare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        return 1;
    }

    string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    map<string, int> word_counts;
    string separators = " ,?!.";

    size_t start = text.find_first_not_of(separators);
    while (start != string::npos) {
        size_t end = text.find_first_of(separators, start);
        string word = text.substr(start, end - start);

        for (char& c : word) {
            c = tolower(static_cast<unsigned char>(c));
        }
        word_counts[word]++;

        if (end == string::npos) {
            break;
        }
        start = text.find_first_not_of(separators, end);
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
    for (const auto& kv : word_counts) {
        pq.push(kv);
    }

    while (!pq.empty()) {
        cout << pq.top().first << " => " << pq.top().second << "\n";
        pq.pop();
    }

    return 0;
}