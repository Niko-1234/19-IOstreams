#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main(){
    std::ifstream InFile;
    // std::string Name;
    // int num;
    // double total;

    // InFile.open("IN_Files/test.txt");
    // if (!InFile){
    //     std::cerr << "Opening file fail" << std::endl;
    //     return 1;
    // } 
    // while (InFile >> Name >> num >> total)
    // {
    //     std::cout << std::setw(10) << std::left << Name
    //               << std::setw(10) << num 
    //               << std::setw(10) << total 
    //               << std::endl;
    // }

    // std::string line;
    // InFile.open("IN_Files/poem18.txt");
    // if (!InFile){
    //     std::cerr << "Opening file fail" << std::endl;
    //     return 1;
    // } 
    // while (std::getline(InFile,line))
    // {
    //     std::cout << line << std::endl;
    // }

    char X {};
    InFile.open("IN_Files/poem18.txt");
    if (!InFile){
        std::cerr << "Opening file fail" << std::endl;
        return 1;
    } 
    while (InFile.get(X))
    {
        std::cout << X;
    }

    InFile.close();
    return 0;
}