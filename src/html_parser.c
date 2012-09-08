#include "html_parser.h"
#include "stdlib.h"
#include "string.h"
#include "stock.h"

#define BUF_SIZE 4096 
#define SIZE 1
#define COLS 24
#define EMPTY_FILE_SIZE 705

static int get_tag_len(char *data)
{
    char *end;
    char tmp;
    int len;
    
    end = strstr(data, "</"); 
    if (end != NULL) {
        tmp = *end;
        *end = 0;
        len = strlen(data);
        *end = tmp;
    } else {
        len = 0;
    }
    return len;
}

static struct html_table html_fill_data(char *data, size_t len)
{
    struct html_table parsed_data = {0};
    char *curr_td;
    int i;

    if(data != NULL)
    {
        data = strstr(data, "</tr>");
        curr_td = strstr(data, "<td>");
        if (curr_td != NULL) {
            for (i = 0; i < 24; i++) {
                curr_td = strstr(curr_td, "<td>") + strlen("<td>");
                memcpy(parsed_data.sequence + i*ELEM_SIZE,curr_td, get_tag_len(curr_td));
            }
        }
    } else {
        printf("fail!\n");
    }
    
    return parsed_data;
}

void print_stock(struct stock *_stock)
{
        printf("Paper: %s\n", _stock->paper);
        printf("Sequence: %u\n", _stock->sequence);
        printf("Exchange: %s\n", _stock->exchange);
        printf("Board: %s\n", _stock->board);
        printf("Time: %s\n", _stock->time);
        printf("Bid d: %u\n", _stock->bid_depth);
        printf("Bid dt: %u\n", _stock->bid_depth_total);
        printf("Bid n: %u\n", _stock->bid_number);
        printf("Bid: %f\n", _stock->bid);
        printf("Offer: %f\n", _stock->offer);
        printf("Offer d: %u\n", _stock->offer_depth);
        printf("Offer dt: %u\n", _stock->offer_depth_total);
        printf("Offer n: %u\n", _stock->offer_number);
        printf("Open: %f\n", _stock->open);
        printf("High: %f\n", _stock->high);
        printf("Low: %f\n", _stock->low);
        printf("Last: %f\n", _stock->last);
        printf("Change: %f\n", _stock->change);
        printf("Change %%: %f\n", _stock->change_percent);
        printf("Volume: %u\n", _stock->volume);
        printf("Value: %f SEK\n", _stock->value);
        printf("Trades: %u\n", _stock->trades);
}

struct stock html_parse_file(const char *file_name, int *len)
{
    char buf[BUF_SIZE] = {0};
    struct html_table html_table_stock;
    FILE *fp = fopen(file_name, "r");
    struct stock _stock;
    
    if(fp == NULL) {
        printf("parameter error!\n");
        printf("%s\n", file_name);
    }
    
    *len = fread(buf, SIZE, BUF_SIZE, fp);
    printf("file len: %d\n", *len);
    if (*len == BUF_SIZE || *len <= EMPTY_FILE_SIZE) {
        printf("File is too large for buffer\n");
        goto exit;
    } else { /* The complete file was read successfully */
        html_table_stock = html_fill_data(buf, *len);
    }
    _stock = convert_to_stock(&html_table_stock);

exit:
    if (fclose(fp) != EOF) {
        fp = NULL;
    } else { 
        printf("Could not close file!\n");
    }
    return _stock; 
}
