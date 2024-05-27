#include<iostream>
#include<getopt.h>
#include<string.h>

#define no_arg 0
#define req_arg 1
#define opt_arg 2

int main(int argc, char** argv)
{
  std::cout << "given args are: " << std::endl;
  for (int i=0; i<argc; i++)
    std::cout << argv[i] << " ";
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
      break;
    case 'a':
      if (optarg[0] == '=')
      {
        memmove(optarg++, optarg, strlen(optarg)-1);
      }
      std::cout << "req arg: " << optarg << std::endl;
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
      }
      else
      {
        if (optarg[0] == '=')
        {
          memmove(optarg++, optarg, strlen(optarg)-1);
        }
        std::cout << "optional arg present: " << optarg << std::endl;
      }
      break;

    default:
      std::cout << "optargs [-v] [-n [arg]] [-a arg]" << std::endl;
      break;
    }
  }

  return 0;
}
