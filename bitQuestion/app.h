#ifndef APP_H
#define APP_H
#include "stdint.h"
struct Data8_t{
    template<typename Type>
    void operator=(Type);
    operator uint8_t() const ;
private:
    uint8_t data1;
};

struct toBits{
    uint8_t b0:1;
    uint8_t b1:1;
    void myfoo();

private:

};
class app
{
public:
    app();
};

#endif // APP_H
