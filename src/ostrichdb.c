#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ostrichdb.h"

//=========================================================//
// Author: Marshall A Burns aka @SchoolyB
//
// Copyright 2024 Marshall A Burns and Solitude Software Solutions LLC
// Licensed under MIT License (see LICENSE file for details)
//=========================================================//

// Runs the build script for OstrichDB
int ost_build() {
    if (chdir("scripts") != 0) {
        perror("Failed to change directory to scripts");
        return -1;
    }

    int status = system("./build.sh");
    if (status == -1) {
        perror("Failed to execute build script");
        return -1;
    }

    return WEXITSTATUS(status);
}

// Assumes the DBMS is already built and currently running
int ost_restart() {
    int status = system("./scripts/restart.sh");
    if (status == -1) {
        perror("Failed to execute restart script");
        return -1;
    }

    return WEXITSTATUS(status);
}

