
#ifndef __BM_LOGGER_H
#define __BM_LOGGER_H

#include <string>

namespace bitmutation {
namespace ogl {
class Logger {
public:
    static Logger &getInstance() {
        static Logger instance;
        return instance;
    };

private:
  Logger();
  ~Logger();

public:
  void Log(std::string message);
  const std::string CurrentTimeStamp();
  Logger(Logger const &) = delete;
  void operator=(Logger const &) = delete;
};
} // namespace ogl
} // namespace bitmutation

#endif