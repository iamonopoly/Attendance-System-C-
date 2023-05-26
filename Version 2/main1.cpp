#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> attendance; // Map to store registration numbers and attendance

    // Open the input file
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    // Read registration numbers from the input file
    std::string regNumber;
    while (inputFile >> regNumber) {
        attendance[regNumber]++; // Increment attendance for the registration number
    }

    // Close the input file
    inputFile.close();

    // Open the output file
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Failed to open the output file." << std::endl;
        return 1;
    }

    // Write the attendance summary to the output file
    outputFile << "Attendance Summary:" << std::endl;
    for (const auto& entry : attendance) {
        outputFile << entry.first << "  ..............  " << entry.second << std::endl;
    }

    // Close the output file
    outputFile.close();

    std::cout << "Attendance summary has been written to the output file." << std::endl;

    return 0;
}
