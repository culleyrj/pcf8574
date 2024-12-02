# pcf8574
## I2C communication with raspberry pi

Commands to use once the i2c interface is started<br>
```
i2cdetect -y 1
```

### Control PCF8574 IO using i2c-tools
PCF8574 is a I2C chip which can expand IO up to 8 and the initial state of IO is HIGH. Different from other I2C chips, the PCF8574 has no register, instead, a byte to specify the address on that chip to write to is always used to control the IO:<br>
```
i2cset -y 1 0x20 0x7F
i2cget -y 1 0x20
```

### Compile commands
```
gcc -Wall pcf8574.c -o pcf8574
sudo ./pcf8574
```

The method used here is called contolled by sysfs.  This was used here because linux command ```hostnamectl``` showed the version of linux to be bookworm where only the lgpio library is available.  Source: https://www.waveshare.com/wiki/Libraries_Installation_for_RPi. 
