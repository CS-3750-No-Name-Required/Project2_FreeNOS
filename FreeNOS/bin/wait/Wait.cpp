#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <wait.h>

Wait::Wait(int argc, char **argv)
 : POSIXApplication(argc, argv)
{
    //parser
}

Wait::Result Wait::exec(){
    return success
}