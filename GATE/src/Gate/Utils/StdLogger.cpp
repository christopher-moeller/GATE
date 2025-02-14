#include "StdLogger.h"

#include <iostream>


namespace Gate {

    void StdLogger::LogInfoMessage(const std::string &message) {
        std::cout << "[INFO] " << message << std::endl;
    }

    void StdLogger::LogErrorMessage(const std::string &message) {
        std::cout << "[ERROR] " << message << std::endl;
    }

}
