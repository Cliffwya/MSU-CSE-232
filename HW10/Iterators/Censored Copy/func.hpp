#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set> 

std::set<std::string> ReplacementCensor(std::istream& is, std::ostream& os, const std::map<std::string,std::string>&values);