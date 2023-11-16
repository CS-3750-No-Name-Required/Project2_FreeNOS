#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
#include <ProcessClient.h>
#include <string.h>
#include <Process.h>
#include "Renice.h"
#include <stdlib.h>
#include "sys/renice.h"

Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Changes the priority of a runnign process");
    parser().registerPositional("PRIORITY", "Change schedule priority at this level");
    parser().registerPositional("PID", "Process ID of process that priority will be changed");

    parser().registerFlag('n', "priorityFlag", "Change priority level");
}

Renice::~Renice(){}

Renice::Result Renice::exec()
{
    if(arguments().get("priorityFlag")){
        const ProcessClient process;
        ProcessID pid = (atoi(arguments().get("PID")));
        int priorityFlag = (atoi(arguments().get("PRIORITY")));

        ProcessClient:: Info info;
        const ProcessClient::Result result = process.processInfo(pid, info);

        // Checking if PID exists
        if (result != ProcessClient:: Success) {
            ERROR("PID '" << pid << "' not found")
            return InvalidArgument;
        }

        // Checking if the new PID is valid
        if( priorityFlag > 5 || priorityFlag < 1){
            ERROR("Failed to set priorit for PID " << pid)
            return InvalidArgument;
        }

         //Add renice call code
        renicepid(pid, priorityFlag, 0, 0);
        printf("Process %d set to priority %d, from priority %d./n", pid, priorityFlag, info.kernelState.priority);
    }

    return Success;
}
