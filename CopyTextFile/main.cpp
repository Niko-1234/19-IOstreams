#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main(){
    std::ifstream InFile {"IN_Files/RomeoAndJuliet.txt"};
    std::ofstream OutFile {"OUT_Files/RomeoAndJuliet1.txt"};

    if (!InFile){
        std::cerr << "Opening file fail" << std::endl;
        return 1;
    }
    if (!OutFile){
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }
    std::string line{};
    int LineNumber {0};
    while(std::getline(InFile, line)){
        if (line != ""){
            ++LineNumber;
            OutFile << std::setw(10) << std::left << LineNumber << line << std::endl;
        } else {
            OutFile << std::endl;
        }
    } 

    std::cout << "Copied!" << std::endl;

    InFile.close();
    OutFile.close();
    return 0;
}