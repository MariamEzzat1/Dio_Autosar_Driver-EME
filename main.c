#include "Dio.h"
int main (void)
{
    while(1)
    {
    Port_init();
    Dio_WriteChannel(39, STD_HIGH);
    }
    return 0;
}
