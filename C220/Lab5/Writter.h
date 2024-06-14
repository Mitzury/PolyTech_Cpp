#pragma once
#include <iostream>
#include <fstream>
#include <memory>

class Writer {
private:
    std::shared_ptr<std::ofstream> file;
public:
    Writer (const std::string& file) {
        std::ifstream isfile (file); 
    if(isfile){
        new std::ofstream(file);
    }
    else {
        std::cout << "file already";
    }
    }

};