#ifndef HTML_PARSER_H__
#define HTML_PARSER_H__


#include <stdio.h>
enum pt_ret_val {
    PT_RET_OK,
    PT_RET_FAIL,
};

struct order_book
{
    char paper[128];
    unsigned int depth;
};

#define ELEM_SIZE 128
struct html_table
{
    char sequence[ELEM_SIZE];
    char exchange[ELEM_SIZE];
    char board[ELEM_SIZE];
    char time[ELEM_SIZE];
    char paper[ELEM_SIZE];
    char bid[ELEM_SIZE];
    char bid_depth[ELEM_SIZE];
    char bid_depth_total[ELEM_SIZE];
    char bid_number[ELEM_SIZE];
    char offer[ELEM_SIZE];
    char offer_depth[ELEM_SIZE];
    char offer_depth_total[ELEM_SIZE];
    char offer_number[ELEM_SIZE];
    char open[ELEM_SIZE];
    char high[ELEM_SIZE];
    char low[ELEM_SIZE];
    char last[ELEM_SIZE];
    char change[ELEM_SIZE];
    char change_percent[ELEM_SIZE];
    char volume[ELEM_SIZE];
    char value[ELEM_SIZE];
    char trades[ELEM_SIZE];
    char status[ELEM_SIZE];
    char quote_id[ELEM_SIZE];
};

enum pt_ret_val html_open(FILE *fp, const char *file_name, size_t *len);
struct stock html_parse_file(const char *file_name, int *len);
#endif
