#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

#ifndef CONSUMER
#define CONSUMER    "Consumer"
#endif

int main(void) {
    struct gpiod_chip *chip;
    struct gpiod_line *line;
    unsigned int line_num = 23; //GPIO Pin 23
    int ret;

    chip = gpiod_chip_open("/dev/gpiochip0");
    if(!chip) {
        perror("Open chip failed!\n");
        exit(-1);
    }

    line = gpiod_chip_get_line(chip, line_num);
    if(!line) {
        perror("Get line failed!\n");
        gpiod_chip_close(chip);
        exit(-1);
    }

    ret = gpiod_line_request_output(line, CONSUMER, 0);
    if(ret < 0) {
        perror("Request line as output failed!\n");
        gpiod_chip_close(chip);
        exit(-1);
    }

    int val = 0;
    for(int i = 0; i<20; ++i) {
        ret = gpiod_line_set_value(line, val);
        if(ret < 0) {
            perror("Set line output failed!\n");
            gpiod_line_release(line);
            gpiod_chip_close(chip);
            exit(-1);
        }
        printf("Output %u on line #%u\n", val, line_num);
        sleep(1);
        val = !val;
    }
    gpiod_line_set_value(line, 0);
    gpiod_line_release(line);
    gpiod_chip_close(chip);
    return 0;
}