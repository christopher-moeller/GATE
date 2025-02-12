#pragma once

#include "Gate/Utils/Logger.h"

namespace Gate {

    class AndroidLogger : public Logger {

        void Info(const char *message, ...) override;
        void Error(const char *message, ...) override;

    };

}
