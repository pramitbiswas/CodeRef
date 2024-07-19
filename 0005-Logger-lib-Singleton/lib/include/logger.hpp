#include <iostream>
#include <string>
#include <mutex>

class Logger
{
  public:
    void log(std::string msg);
    static Logger* getLogger();
  private:
    Logger();
    ~Logger();

    static Logger* logInstance;
    static std::mutex mtx;

    Logger (const Logger &) = delete;   // copy ctor
    Logger (Logger &&) = delete;        // move ctor
    Logger& operator = (const Logger &) = delete; // copy assignment
    Logger& operator = (Logger &&) = delete;      // move assignment
};
