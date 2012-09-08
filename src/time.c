#include "time.h"
#include "stock.h"
#include <string.h>

void time_get_time_from_stock(struct stock *_stock, struct time *tm)
{
    char time_buf[3] = {0}; 
    memcpy(time_buf, _stock->time+0, 2);
    tm->hour = atoi(time_buf);
    memcpy(time_buf, _stock->time+2, 2);
    tm->min = atoi(time_buf);
    memcpy(time_buf, _stock->time+4, 2);
    tm->sec = atoi(time_buf);
}
