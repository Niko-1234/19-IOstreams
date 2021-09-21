#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main(){
    std::ofstream OutFile {"OUT_Files/output.txt"};

    if (!OutFile){
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }
    std::string record;
    std::cout << "What do u want write in file: ";
    std::getline(std::cin, record);
    OutFile << record << std::endl;

    OutFile.close();
    return 0;
}