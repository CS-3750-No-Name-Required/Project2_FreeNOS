#ifndef __LIBPOSIX_RENICE_H
#define __LIBPOSIX_RENICE_H

#include <Macros.h>
#include "types.h"

#define WEXITSTATUS(st) (st)
extern C pid_t renicepid(int level, pid_t pid, int *stat_loc, int options);

/**
 * @}
 * @}
 */

#endif /* __LIBPOSIX_RENICE_H */