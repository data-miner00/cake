#include "lib1.h"
#ifdef USE_LIB2
#include "lib2.h"
#endif

int getZero() {
#ifdef USE_LIB2
    return getOne();
#else 
    return 0;
#endif 
}

