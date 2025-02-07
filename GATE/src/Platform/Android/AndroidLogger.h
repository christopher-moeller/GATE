#pragma once

#include "Gate/Utils/Logger.h"

namespace Gate {

    class AndroidLogger : public Logger {

        void info(const char *message, ...) override;
        void error(const char *message, ...) override;

    };

}
