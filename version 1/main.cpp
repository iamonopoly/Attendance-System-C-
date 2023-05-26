#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> attendance; // Map to store registration numbers and attendance

    while (true) {
        std::cout << "Enter registration number (or 'q' to quit): ";
        std::string regNumber;
        std::cin >> regNumber;

        if (regNumber == "q")
            break;

        attendance[regNumber]++; // Increment attendance for the registration number
    }

    std::cout << "Attendance Summary:" << std::endl;
    for (const auto& entry : attendance) {
        std::cout << entry.first << "  ..............  " << entry.second << std::endl;
    }

    return 0;
}
