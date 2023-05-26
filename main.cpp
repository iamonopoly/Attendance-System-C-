#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> attendance; // Map to store registration numbers and attendance

    // Open the existing output file
    std::ifstream existingOutputFile("output.txt");
    if (existingOutputFile) {
        std::string regNumber;
        int count;

        // Read the existing attendance from the output file
        while (existingOutputFile >> regNumber >> count) {
            attendance[regNumber] = count;
        }

        // Close the existing output file
        existingOutputFile.close();
    }

    // Open the input file
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    // Read registration numbers from the input file and update the attendance
    std::string regNumber;
    while (inputFile >> regNumber) {
        attendance[regNumber]++; // Increment attendance for the registration number
    }

    // Close the input file
    inputFile.close();

    // Open the output file in overwrite mode
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Failed to open the output file." << std::endl;
        return 1;
    }

    // Write the updated attendance to the output file
    for (const auto& entry : attendance) {
        outputFile << entry.first << "     " << entry.second << std::endl;
    }

    // Close the output file
    outputFile.close();

    std::cout << "Attendance has been updated in the output file." << std::endl;

    return 0;
}



