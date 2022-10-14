#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

struct Country {
    std::string name;
    int gold;
    int silver;
    int bronze;
};

void read_file(const std::string& file_name, std::vector<Country>& values)
{
    std::ifstream file(file_name);

    if (file.fail()) {
        std::cerr << "Error reading file: " << file_name << "\n";
        exit(1);
    }

    std::string line;
    while(getline(file, line)) {
        std::istringstream input(line);
        Country c;
        input >> c.name;
        input >> c.gold;
        input >> c.silver;
        input >> c.bronze;
        values.push_back(c);
    }

    file.close();
}

void print_vector(const std::vector<Country>& values)
{
    for (Country c : values) {
        std::cout
            << std::setw(13) << std::left << c.name << " "
            << std::setw(2) << std::right << c.gold << " "
            << std::setw(2) << c.silver << " "
            << std::setw(2) << c.bronze << "\n";
    }
}

bool compare_countries(const Country& a, const Country& b)
{
    if (a.gold != b.gold) {
        return a.gold > b.gold;
    }
    if (a.silver != b.silver) {
        return a.silver > b.silver;
    }
    if (a.bronze != b.bronze) {
        return a.bronze > b.bronze;
    }

    return a.name < b.name;
}

int main(int argc, char* argv[])
{
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << argv[i] << "\n";
    // }

    if (argc != 2) {
        std::cerr << "Please specify the name of the input file.\n";
        exit(1);
    }

    std::string file_name = argv[1];
    std::vector<Country> countries;

    read_file(file_name, countries);
    std::sort(countries.begin(), countries.end(), compare_countries);
    print_vector(countries);

    return 0;
}
