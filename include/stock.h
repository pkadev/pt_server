#ifndef STOCK_H__
#define STOCK_H__

#include "html_parser.h"

struct stock
{
    unsigned int sequence;
    char exchange[ELEM_SIZE];
    char board[ELEM_SIZE];
    char time[ELEM_SIZE]; /* TODO time struct? */
    char paper[ELEM_SIZE];
    double bid;
    unsigned int bid_depth;
    unsigned int bid_depth_total;
    unsigned int bid_number;
    double offer;
    unsigned int offer_depth;
    unsigned int offer_depth_total;
    unsigned int offer_number;
    double open;
    double high;
    double low;
    double last;
    double change;
    double change_percent;
    unsigned int volume;
    double value;
    unsigned int trades;
    char status[ELEM_SIZE];
    char quote_id[ELEM_SIZE];
};

struct stock convert_to_stock(struct html_table *table);

void print_stock(struct stock *_stock);
#endif
