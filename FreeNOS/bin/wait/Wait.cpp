#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ProcessClient.h>
#include "Wait.h"
#include "sys/wait.h"
#include "sys/types.h"

Wait::Wait(int argc, char **argv)
 : POSIXApplication(argc, argv)
{
    //parser
    parser().setDescription("Suspends execution of the calling process until one of its children terminates.");
    parser().registerPositional("PROCESS_ID", "Suspend execution until ...");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec(){
    //similar to Sleep.cpp
    int pid = 0;
    if ((pid = atoi(argument().get("PROCESS_ID"))) <= 0)
    {
        ERROR("invalid pid `" << arguments().get("PROCESS_ID") << "'");
        return InvalidArgument;
    }

    //Wait now
    if(waitpid(pid, 0, 0) != 0)
    {
        ERROR("failed to wait: " << strerror(errno));
        return IOError
    }
    //Done
    return Success;

}

