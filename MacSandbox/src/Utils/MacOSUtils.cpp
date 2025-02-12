#include "MacOSUtils.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <iostream>


void MacOSUtils::EnsureSingleProgramInstance() {
    
    static const char* lockFilePath = "/tmp/myapp.lock";  // Path to a lock file

    // Open a lock file (will create it if it doesn't exist)
    int lockFile = open(lockFilePath, O_CREAT | O_RDWR, 0666);
    if (lockFile == -1) {
        std::cerr << "Failed to open lock file." << std::endl;
        exit(0);
    }

    // Attempt to acquire an exclusive lock (non-blocking)
    if (flock(lockFile, LOCK_EX | LOCK_NB) == -1) {
        std::cerr << "Another instance of the application is already running." << std::endl;
        exit(0);
    }
    
}
