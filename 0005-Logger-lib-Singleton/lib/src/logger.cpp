#include "logger.hpp"

Logger* Logger::logInstance = nullptr;
std::mutex Logger::mtx;

Logger* Logger::getLogger()
{
  if (logInstance==nullptr) // as lock is expensive
  {
    mtx.lock();
    if (logInstance==nullptr)
      logInstance = new Logger();
    mtx.unlock();
  }

  return logInstance;
}

void Logger::log(std::string msg)
{
  std::cout << msg << std::endl;
}

Logger::Logger(){}
Logger::~Logger()
{
  if (logInstance!=nullptr) // as lock is expensive
  {
    mtx.lock();
    if (logInstance!=nullptr)
      delete logInstance;
    mtx.unlock();
  }
}
