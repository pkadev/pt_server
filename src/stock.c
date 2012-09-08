#include "stock.h"
#include "html_parser.h"
#include <string.h>
#include <stdio.h>
#include <locale.h>

static unsigned int get_uint(char *data)
{
    return (unsigned int)atoi(data);
}

double to_double(char *str)
{
    double res, dec;
    char *p = strstr(str, ".");
    if (p != NULL) {
        *(p+3) = 0;
        res = atoi(str);
    } else {
        return atoi(str);
    }
    dec = (double)atoi(p+1); 
    
    res += (dec/100);
    return res;
}

struct stock convert_to_stock(struct html_table *table)
{
    struct stock _stock = {0};

    _stock.sequence = (unsigned int)atoi(table->sequence);
    memcpy(_stock.exchange, table->exchange, strlen(table->exchange));
    memcpy(_stock.board, table->board, strlen(table->board));
    memcpy(_stock.time, table->time, strlen(table->time));
    memcpy(_stock.paper, table->paper, strlen(table->paper));
    _stock.bid = to_double(table->bid);
    _stock.bid_depth = (unsigned int)atoi(table->bid_depth);
    _stock.bid_depth_total = (unsigned int)atoi(table->bid_depth_total);
    _stock.bid_number = (unsigned int)atoi(table->bid_number);
    _stock.offer = to_double(table->offer);
    _stock.offer_depth = (unsigned int)atoi(table->offer_depth);
    _stock.offer_depth_total = (unsigned int)atoi(table->offer_depth_total);
    _stock.offer_number = (unsigned int)atoi(table->offer_number);
    _stock.open = to_double(table->open);
    _stock.high = to_double(table->high);
    _stock.low = to_double(table->low);
    _stock.last = to_double(table->last);
    _stock.change = to_double(table->change);
    _stock.change_percent = to_double(table->change_percent);
    _stock.volume = (unsigned int)atoi(table->volume);
    _stock.value = to_double(table->value);
    _stock.trades = (unsigned int)atoi(table->trades);

    return _stock;
}
