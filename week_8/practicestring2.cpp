#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Read a sentence from the user
    string text;
    cout << "Enter a sentence: ";
    getline(cin, text);

    // 2. Display its length
    cout << "Length of sentence: " << text.length() << endl;

    // 3. Find the position of a word
    string wordToFind;
    cout << "Enter a word to find: ";
    cin >> wordToFind;

    size_t pos = text.find(wordToFind);

    // 4. Extract and display part of the sentence
    if (pos != string::npos) {
        cout << "Found \"" << wordToFind << "\" at index: " << pos << endl;
        string extracted = text.substr(pos, wordToFind.length());
        cout << "Extracted part: " << extracted << endl;

     // 5. Replace a word with a new word
    string newWord;
        cout << "Enter a new word to replace it: ";
        cin >> newWord;

        text.replace(pos, wordToFind.length(), newWord);
    } else {
        cout << "Word \"" << wordToFind << "\" not found in the sentence!" << endl;
    }

    // 6. Show the final result
    cout << "Final result: " << text << endl;

    return 0;
}