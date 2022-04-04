#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string hashFunc(std::string input){
    unsigned int Magic = 3415431;
    unsigned int hashed = 12;
    int count = 0;
    while (input[count] != '\0'){
        hashed = hashed ^ (input[count]);
        hashed = hashed * Magic;
        count++;
    }

    std::string Output;
    std::stringstream hexstream;
    hexstream << std::hex << hashed;
    Output = hexstream.str();
    std::transform(Output.begin(), Output.end(), Output.begin(), ::toupper);
    return Output;
}

int main(){
    std::string test = "Its Lin!";
    std::cout << hashFunc(test);
    return 0;
}
