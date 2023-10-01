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
    //similar to Sleep.cpp & ProcessList.cpp
    ProcessClient process;
    ProcessID pid = atoi(arguments().get("PROCESS_ID")); //gets the process id in value type pid_t. atoi turns str into int
    ProcessClient::Info info;
    ProcessClient::Result result = process.processInfo(pid, info); 
    if(result==ProcessClient::Success){
        //instead of printing out the table it will run waitpid 
        //lib > libpoisx > sys > wait> waitpid 
        waitpid(pid, 0,0);
    }else{
        ERROR("invalid pid `" << arguments().get("PROCESS_ID") << "'");
        return InvalidArgument;
    }
    
    //Done
    return Success;

}

