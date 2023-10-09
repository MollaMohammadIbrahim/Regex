#include <iostream>
#include <regex>

int main() {
    std::string text = "John Doe (johndoe@example.com)";

    std::regex pattern(R"((\w+)\s+(\w+)\s+\((\w+@\w+\.\w+)\))");
    std::smatch matches;

    if (std::regex_search(text, matches, pattern)) {
        std::cout << "Full match: " << matches[0] << std::endl;
        std::cout << "First name: " << matches[1] << std::endl;
        std::cout << "Last name: " << matches[2] << std::endl;
        std::cout << "Email address: " << matches[3] << std::endl;
    } else {
        std::cout << "No match found" << std::endl;
    }

    return 0;
}
