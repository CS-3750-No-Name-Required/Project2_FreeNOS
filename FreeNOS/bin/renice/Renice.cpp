#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
#include <ProcessClient.h>
#include <string.h>
#include <Process.h>
#include "Renice.h"

Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Changes the priority of a runnign process");
    parser().registerPositional("PRIORITY", "Change schedule priority at this level");
    parser().registerPositional("PID", "Process ID of process that priority will be changed");

    parser().registerFlag('n', "priorityFlag", "Change priority level");
}

Renice::Result Renice::exec()
{
    //Add renice call code
    

    // Output the table
    // write(1, *out, out.length());
    // return Success;
}
