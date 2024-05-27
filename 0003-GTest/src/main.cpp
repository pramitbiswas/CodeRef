#include "optArgParse.hpp"

int main(int argc, char** argv)
{
  std::unordered_map<char, std::string> map;
  opt_arg_parse(argc, argv, map);
  // for (int i=0; i<argc; i++)
  //   std::cout << argv[i] << " ";
  // std::cout << std::endl;
  for(const auto& item: map)
    std::cout << item.first << ": " << item.second << "\n";

  return 0;
}
