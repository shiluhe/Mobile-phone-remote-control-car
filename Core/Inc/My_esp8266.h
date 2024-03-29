//
// Created by hslnb on 2024/1/17.
//

#ifndef RC2_MY_ESP8266_H
#define RC2_MY_ESP8266_H
#include "main.h"

typedef uint16_t u16  ;


extern void esp8266_test(void);
extern void u2_printf(char* fmt);
extern char esp8266_send_cmd(char *cmd,char *ack,u16 waittime);
extern void esp8266_start_trans(void);

#endif //RC2_MY_ESP8266_H
