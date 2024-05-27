#include<getopt.h>
#include "optArgParse.hpp"

void opt_arg_parse(int &argc, char **&argv,
                   std::unordered_map<char, std::string> &map)
{
  std::cout << "given args are: " << std::endl;
  // argv[2][2]='3';
  for (int i=0; i<argc; i++)
    std::cout << argv[i] << "\n";
  std::cout << std::endl;

  const struct option longopts[] =
  {
    {"version", no_arg, 0, 'v'},
    {"age", req_arg, 0, 'a'},
    {"name", opt_arg, 0, 'n'},
    {0, 0, 0, 0},
  };

  char opt = 0;
  while( (opt=getopt_long(argc, argv, "va:n::", longopts, NULL)) != -1 )
  {
    std::cout << opt << std::endl;
    switch (opt)
    {
    case 'v':
      std::cout << "no arg" << std::endl;
      map['v'] = "";
      break;
    case 'a':
      if (optarg[0] == '=')
      {
        memmove(optarg++, optarg, strlen(optarg)-1);
      }
      std::cout << "req arg: " << optarg << std::endl;
      map['a'] = optarg;
      break;
    case 'n':
      if ( optarg == NULL
          && optind < argc
          && argv[optind][0] != '\0'
          && argv[optind][0] != NULL
          && argv[optind][0] != '-' )
      {
        optarg = argv[optind++];
      }
      if (optarg == NULL)
      {
        std::cout << "no optional arg" << std::endl;
        map['n'] = "";
      }
      else
      {
        if (optarg[0] == '=')
        {
          memmove(optarg++, optarg, strlen(optarg)-1);
        }
        std::cout << "optional arg present: " << optarg << std::endl;
        map['n'] = optarg;
      }
      break;

    default:
      std::cout << "optargs [-v] [-n [arg]] [-a arg]" << std::endl;
      break;
    }
  }
}
