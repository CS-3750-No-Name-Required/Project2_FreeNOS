#ifndef __BIN_RENICE_RENICE_H
#define __BIN_RENICE_RENICE_H

#include <POSIXApplication.h>


class Renice : public POSIXApplication {
    public:

       
        Renice(int argc, char **argv);

       
        virtual ~Renice();

        
        virtual Result exec();
};


#endif /* __BIN_RENICE_RENICE_H */