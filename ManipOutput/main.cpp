#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

void DrawRuler(int RulerLength){
    for(int i = 1; i <= RulerLength; i++){
        if (i%10 == 0)
            std::cout << i/10;
        else if (i%5 == 0)
            std::cout << "+";
        else
            std::cout << "-";
    }
    std::cout << std::endl;
}

void ColumnNames(int pos1, int pos2, int pos3, int pos4){
    std::cout << std::setw(pos1) << std::left  << "Country" 
              << std::setw(pos2) << std::left  << "City" 
              << std::setw(pos3) << std::right << "Population" 
              << std::setw(pos4) << std::right << "Price"
              << std::endl;
    std::cout << std::setfill('-') << std::setw(pos1 + pos2 + pos3 + pos4) << "" << std::endl;
}

struct City {
    std::string name;
    long population;
    double cost;
};

struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main(){
    Tours Tours
    {"Tour Ticket Prices from Miami",
        {
            {
                "Colombia",{
                    {"Bogota", 8778000,400.91},
                    {"Cali", 240100,424.11},
                    {"Medelin", 2464000,400.12},
                    {"Cartagena", 972000,400.33}
                },
            },
            {
                "Brazil",{
                    {"Rio", 1350000,435.91},
                    {"Sao Paulo", 11310000,987.11},
                    {"Salvador", 18234000,855.99}
                },
            },
            {
                "Chile",{
                    {"Valdiva", 260000,546.65},
                    {"Santiago", 7040000,548.78}
                },
            },
            {
                "Argentina",{
                    {"Buenos Aires", 3010000,723.77}
                },
            },
            {
                "Poland",{
                    {"Warsaw", 1200000,231.45},
                    {"Cracow", 305000,453.53},
                    {"Poznan", 204300,213.86}
                },
            }
        }
    };

    int CountryColWidth {20};
    int CityColWidth {20};
    int PopulationColWidth {15};
    int PriceColWidth {15};
    int PageWidth = CountryColWidth + CityColWidth + PopulationColWidth + PriceColWidth;

    //Tabel header
    DrawRuler(PageWidth);
    std::cout << std::endl;
    std::cout << std::setw(PageWidth/2 + Tours.title.length()/2) << std::right << Tours.title << std::endl;
    std::cout << std::endl;

    //Table column names
    ColumnNames(CountryColWidth,CityColWidth,PopulationColWidth,PriceColWidth);

    //reset fill and set precision
    std::cout << std::setfill(' ');
    std::cout << std::setprecision(2) << std::fixed;

    //report data
    for(auto country : Tours.countries){
        for(int i = 0; i < country.cities.size(); i++){  
            std::cout << std::setw(CountryColWidth) << std::left << ((i == 0) ? country.name : "")
                      << std::setw(CityColWidth) << std::left << country.cities.at(i).name
                      << std::setw(PopulationColWidth) << std::right << country.cities.at(i).population
                      << std::setw(PriceColWidth) << std::right << country.cities.at(i).cost
                      << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}