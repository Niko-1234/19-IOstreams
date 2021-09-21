#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

bool FindSubstring(std::string substring, std::string string){
    // int MatchChar {0};
    // for (auto x : string){
    //     if (substring.at(MatchChar) == x)
    //         ++MatchChar;
    //     else 
    //         MatchChar = 0;

    //     if (MatchChar >= substring.size()) return true;
    // }
    // return false;
    std::size_t found = string.find(substring);
    if (found == std::string::npos) {return false;}
    else {return true;}
}

int main(){
    std::ifstream InFile {"IN_Files/RomeoAndJuliet.txt"};
    std::string SearchingWord;
    std::string WordRead;
    int WordCounter {0};
    int MatchCounter {0};

    if (!InFile){
        std::cerr << "Opening file fail" << std::endl;
        return 1;
    }

    std::cout << "Type searching word: " << std::endl;
    std::cin >> SearchingWord;

    while (InFile >> WordRead){
        ++WordCounter;
        if (FindSubstring (SearchingWord, WordRead))
            ++MatchCounter;
    }

    std::cout << "In text are " << MatchCounter << " '" << SearchingWord << "' words" << std::endl;
    std::cout << WordCounter << " words were searched." << std::endl;

    InFile.close();
    return 0;
}