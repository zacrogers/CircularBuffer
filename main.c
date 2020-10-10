#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "circ_buffer.h"


#define BUFF_SIZE 10

int main(void)
{
    uint16_t buff[BUFF_SIZE];

    cbuff_handle c_buf = cbuff_init(buff, BUFF_SIZE);
    size_t buff_s = 0;

    printf("Filling buffer\n");

    for(int i = 0; i < 20; ++i)
    {
        buff_s = cbuff_size(c_buf);
        cbuff_put(c_buf, (i+1));
        printf("i = %d, size =  %d, full:%d\n", i, buff_s, cbuff_full(c_buf));
    }

    printf("\nEmptying buffer\n");
    uint16_t val = 0;
    for(int i = 0; i < BUFF_SIZE*2; ++i)
    {
        buff_s = cbuff_size(c_buf);
        cbuff_get(c_buf, &val);
        printf("val = %d, size =  %d, full:%d\n", val, buff_s, cbuff_full(c_buf));
    }

    cbuff_free(c_buf);
    return 0;
}