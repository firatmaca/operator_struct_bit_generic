#ifndef TOBITS_H
#define TOBITS_H
#include "stdint.h"

class toBits
{
public:
    toBits();
    template<typename Type>
    void operator=(Type);
    operator uint8_t() const ;
    uint8_t b1 :1;
    uint8_t b2 :1;

private:
  toBits *datam;
};

#endif // TOBITS_H
