#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Abonent {
    std::string surname;
    std::string phoneNumber;
};

void readFromFile(const std::string& filename, std::vector<Abonent>& abonents) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    Abonent abonent;
    while (file >> abonent.surname >> abonent.phoneNumber) {
        abonents.push_back(abonent);
    }
    file.close();
}

void printAllAbonents(const std::vector<Abonent>& abonents) {
    for (const auto& abonent : abonents) {
        std::cout << "Surname: " << abonent.surname << ", Phone: " << abonent.phoneNumber << std::endl;
    }
}

void printAbonent(const std::vector<Abonent>& abonents, const std::string& surname) {
    for (const auto& abonent : abonents) {
        if (abonent.surname == surname) {
            std::cout << "Surname: " << abonent.surname << ", Phone: " << abonent.phoneNumber << std::endl;
            return;
        }
    }
    std::cout << "Abonent with surname " << surname << " not found." << std::endl;
}

int main() {
    std::vector<Abonent> abonents;
    readFromFile("abonents.txt", abonents);

    int choice;
    std::string surname;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Show all abonents\n";
        std::cout << "2. Find abonent by surname\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            printAllAbonents(abonents);
            break;
        case 2:
            std::cout << "Enter surname: ";
            std::cin >> surname;
            printAbonent(abonents, surname);
            break;
        case 3:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

//2 

#include <iostream>
#include <fstream>
#include <string>

void copyFileLines(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the input file!" << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Could not open the output file!" << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    copyFileLines(inputFilename, outputFilename);

    std::cout << "Lines copied from " << inputFilename << " to " << outputFilename << " successfully." << std::endl;

    return 0;
}

//3

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void reverseFileLines(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the input file!" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Could not open the output file!" << std::endl;
        return;
    }

    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
        outputFile << *it << std::endl;
    }
    outputFile.close();
}

int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    reverseFileLines(inputFilename, outputFilename);

    std::cout << "Lines from " << inputFilename << " have been written in reverse order to " << outputFilename << " successfully." << std::endl;

    return 0;
}

//4

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void addDashesLine(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the input file!" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    auto it = std::find_if(lines.rbegin(), lines.rend(), [](const std::string& line) {
        return line.find(' ') == std::string::npos;
        });

    if (it != lines.rend()) {
        lines.insert(it.base(), "------------");
    }
    else {
        lines.push_back("------------");
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Could not open the output file!" << std::endl;
        return;
    }

    for (const auto& l : lines) {
        outputFile << l << std::endl;
    }
    outputFile.close();
}

int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    addDashesLine(inputFilename, outputFilename);

    std::cout << "Lines from " << inputFilename << " have been processed and written to " << outputFilename << " successfully." << std::endl;

    return 0;
}
