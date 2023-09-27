#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
 : POSIXApplication(argc, argv)
{
    //parser
    parser().setDescription("Suspends execution of the calling process until one of its children terminates.");
    parser().registerPositions("PROCESS_ID", "Suspend execution until ...");
}

Wait::Result Wait::exec(){
    //Done
    return Success

}

