#include <linux/i2c-dev.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define I2C_ADDR 0x20
#define LED_ON  0xEF
#define LED_OFF 0xFF
int main (void) {
    int value;
    int fd; 
   
    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }   
    if (ioctl(fd, I2C_SLAVE, I2C_ADDR) < 0) {
        printf("ioctl error: %s\n", strerror(errno));
        return 1;
    }   
    while(1)
    {   
        if(value == LED_ON)value = LED_OFF;
        else value = LED_ON;
        if( write( fd , &value, 1 ) != 1) {
            printf("Error writing file: %s\n", strerror(errno));
        }    
        usleep(1000000); 
    }
    return 0;
}
