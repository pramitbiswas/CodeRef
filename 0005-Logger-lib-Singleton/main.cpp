#include <iostream>
#include <thread>
#include <string>
#include "logger.hpp"

void user1log()
{
  Logger* logger1 = Logger::getLogger();
  logger1->log("Msg from user1");
}

void user2log()
{
  Logger* logger1 = Logger::getLogger();
  logger1->log("Msg from user2");
}

int main(int argc, char const *argv[])
{
  std::thread t1(user1log);
  std::thread t2(user2log);

  t1.join();
  t2.join();

  return 0;
}
