#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string inFile = "input.txt";   
    string outFile = "output.txt"; 

    ifstream in(inFile);
    ofstream out(outFile);

    string words[100]; 
    int count[100] = {0}; 
    int wordCount = 0;
    int totalWords = 0;   
    int sentenceCount = 0, charCount = 0;

    string word;
    char ch;
    while (in.get(ch)) {
        charCount++;
        if (ch == '.' || ch == '!' || ch == '?') sentenceCount++;
    }
    in.clear(); 
    in.seekg(0);    

    while (in >> word) {
        totalWords++; 

        bool found = false;
        for (int i = 0; i < wordCount; i++) {
            if (words[i] == word) {
                count[i]++;
                found = true;
                break;
            }
        }
        if (!found) {
            words[wordCount] = word;
            count[wordCount] = 1;
            wordCount++;
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < wordCount; i++) {
        if (count[i] > count[maxIndex]) maxIndex = i;
    }

    out << "Кількість символів: " << charCount;
    out << "Кількість слів: " << totalWords;
    out << "Кількість речень: " << sentenceCount;
    out << "Найчастіше слово: " << words[maxIndex]<< " " << count[maxIndex] << " разів";

    cout << "все";
    in.close();
    out.close();
    return 0;
}
