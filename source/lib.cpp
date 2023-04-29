#include "lib.hpp"

#include <fstream>
#include <iostream>
#include "fmt/core.h"
#include "json/json.h"

library::library(std::string file)
    : name {fmt::format("{}", "json-playground")}
{

    Json::Value root;
    std::ifstream ifs;
    ifs.open(file);

    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;

    JSONCPP_STRING errs;
    if (!parseFromStream(builder, ifs, &root, &errs)) 
    {
        std::cout << "ERRORS: " << errs << std::endl;
    }
    else
    {
        std::cout << root << std::endl;
        std::cout << root["quiz"] << std::endl;
    }
}
