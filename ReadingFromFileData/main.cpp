#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

void PrintHeader(int col1, int col2){
    std::cout << std::setw(col1) << std::left  << "Student" 
              << std::setw(col2) << std::right << "Score" 
              << std::endl;
    std::cout << std::setfill('-') << std::setw(col1 + col2) << "" << std::endl;
    std::cout << std::setfill(' ');
}

void PrintRec(int col1, int col2, std::string Name, int points){
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(col1) << std::left  << Name 
              << std::setw(col2) << std::right << points 
              << std::endl;
}

void PrintSumup(int col1, int col2, double AverageScore){
    std::cout << std::setfill('-') << std::setw(col1 + col2) << "" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw(col1) << std::left  << "Average score" 
              << std::setw(col2) << std::right << AverageScore
              << std::endl;

}

int CalcScore(std::string response, std::string key){
    int points {0};
    for (int i {0}; i < key.size(); ++i){
        if (response.at(i) == key.at(i))
            points++;
    }
    return points;
}

int main(){
    std::ifstream InFile {"IN_Files/responses.txt"};
    std::string ResponsesKey;
    std::string name{};
    std::string response{};
    double SumPoints {0};
    int RecCounter {0};
    double AverageScore {0};


    if (!InFile){
        std::cerr << "Opening file fail" << std::endl;
        return 1;
    }
    //Table Header
    int ColWidthName {20};
    int ColWidthPoints {10};
    PrintHeader(ColWidthName,ColWidthPoints);

    //Read first rec as key
    InFile >> ResponsesKey;
    //Table Data
    while (InFile >> name >> response){
            int score = CalcScore(response,ResponsesKey);
            SumPoints += score;
            RecCounter++;
            PrintRec(ColWidthName,ColWidthPoints,name,score);
    }
    
    if (RecCounter != 0)
        AverageScore = static_cast<double>(SumPoints)/RecCounter;
    //Table SumUp
    PrintSumup(ColWidthName,ColWidthPoints,AverageScore);

    InFile.close();
    return 0;
}