#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>


std::string path ="";
int size;


int main (int argc, char* argv[]){
    if(argc == 1){
        std::cout << "Please enter file path as an Argument" << std::endl;
        return -1;
    }

    path = argv[1];

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()){
        std::cout << "File can not be open";
        return -1;
    }

    file.seekg(0,std::ios::end);
    std::streamsize size=file.tellg();


    if (size == -1){
        std::cout << "Error calculating file size";
        return -1;
    }
     if (size == 0){
         std::cout << "File is empty" << std::endl;
        return -1;
     }
    file.seekg(0);
    
    unsigned char bytes[16] = {0};
    int bytesALeer = std::min(static_cast<int>(size), 16);

    file.read(reinterpret_cast<char*>(bytes), bytesALeer);

    if (!file.gcount() != bytesALeer){
        std::cout << "Error reading file";
        return -1;
    }
    std::cout << "Primeros " << bytesALeer << " bytes." << std::endl;
    for (int i=0; i<bytesALeer;i++){
            std::cout << std::hex;
            std::cout << std::setw(2) << std::setfill('0') << bytes[i] << " ";
    }

    
}