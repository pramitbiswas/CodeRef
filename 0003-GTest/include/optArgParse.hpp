#ifndef OPTARGPARSE_H
#define OPTARGPARSE_H

#include<iostream>
#include<string.h>
#include<unordered_map>

#define no_arg 0
#define req_arg 1
#define opt_arg 2

void opt_arg_parse(int &argc, char **&argv,
                   std::unordered_map<char, std::string> &map);

#endif
