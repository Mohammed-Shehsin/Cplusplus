#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string& S) {
    vector<int> sentenceLength;
    int count = 0;
    bool word = false;

    for (char c : S) {
        if (c == ' ') {
            if (word) {
                count++;
                word = false;
            }
        } else if (c == '.' || c == '?' || c == '!') {
            if (word) {
                count++;
                word = false;
            }
            if (count > 0) {
                sentenceLength.push_back(count);
                count = 0;
            }
        } else {
            word = true;
        }
    }

    if (word) {
        count++;
    }
    if (count > 0) {
        sentenceLength.push_back(count);
    }

    int maxWords = 0;
    for (int len : sentenceLength) {
        maxWords = max(maxWords, len);
    }
    return maxWords;
}

int main() {
    string S1 = "We test coders. Give us a try?";
    string S2 = "Forget CVs..Save time. x x";

    cout << solution(S1) << endl;
    cout << solution(S2) << endl;

    return 0;
}
