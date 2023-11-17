// similar to ProcessList.h

#ifndef __BIN_PS_PROCESSLIST_H
#define __BIN_PS_PROCESSLIST_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Output the system process list.
 */
class Renice : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Renice (int argc, char **argv);

    /**
     * Destructor
    */
    virtual ~Renice();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();
    
};

/**
 * @}
 */

#endif /* __BIN_PS_PROCESSLIST_H */
