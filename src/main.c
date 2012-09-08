#include <stdlib.h>
/*#include <check.h>*/
#include <string.h>
#include <stdio.h>
#include "html_parser.h"
#include "stock.h"
/*START_TEST(addition)
 {
 	fail_unless(1+3 == 4);
    }
    END_TEST
i*/
int main()
{
    int i;
    //const char *paper = "ERIC-B.ST";
    char quotes_url[256] = "wget -q http://localhost:8678/quotes/"; 
    char mbl_url[256] = "wget -q http://localhost:8678/expanded-mbp/";
    int len;
    
    struct stock _stock, prev_period_stock;
    char watchlist[][128] = { "AOI.ST"};
    struct stock prev5;

    int url_len;
        url_len = strlen(quotes_url);
    i = 0;
    while (1)
    {
        unsigned int pos = sizeof(watchlist)/sizeof(watchlist[0]);
        strcat(quotes_url, watchlist[i % pos]); 
        //printf("url: %s\n", quotes_url);
        sleep(1);

        system("clear");
        system(quotes_url);

        _stock = html_parse_file(watchlist[i % pos], &len);

        print_stock(&_stock);

        struct time tm;
        time_get_time_from_stock(&_stock, &tm);
        unsigned int period = 5;
        printf("Time: %02u:%02u:%02u\n", tm.hour, tm.min, tm.sec);
        if (tm.min%period == 0) {
           prev_period_stock = _stock;
           printf("Saved stock\n");
        }
        system("rm *.ST*");
        system("rm *.O*");
        usleep(250 * 1000);       
        *(quotes_url+url_len) = 0;
        i++;
    }    
    
    return 1;
}




