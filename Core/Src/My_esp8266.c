//
// Created by hslnb on 2024/1/17.
//
#include "My_esp8266.h"
#include "string.h"
#include "usart.h"

void u2_printf(char* fmt);
char esp8266_send_cmd(char *cmd,char *ack,u16 waittime);


void esp8266_test(void)//测试
{
    if(esp8266_send_cmd("AT","OK",50));
}

char esp8266_send_cmd(char *cmd,char *ack,u16 waittime)//发送指令和检查接收
{

    u2_printf(cmd);//cmd为发送

    if(ack&&waittime)
    {
        while(--waittime)
        {
            HAL_Delay(10);
            if(strstr((const char*)RxBuffer,(const char*)ack))//假如在数组中找到
            {
                Uart2_Rx_Cnt=0;
                memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
                return 1;

            }
        }
    }

    return 0;
}


void esp8266_start_trans(void)//ESP8266初始化
{

    esp8266_send_cmd("AT+CWMODE=2","OK",50);//设置为AP模式

    esp8266_send_cmd("AT+RST","ready",20);//重启

    HAL_Delay(1000);
    HAL_Delay(1000);
    HAL_Delay(1000);
    HAL_Delay(1000);

    esp8266_send_cmd("AT+CWSAP=\"esp8266\",\"123456789\",1,4","OK",200);//设置WiFi名称、密码，模式
    esp8266_send_cmd("AT+CIPMUX=1","OK",20);//进入透传模式
    esp8266_send_cmd("AT+CIPSERVER=1,8080","OK",200);//设置端口8080
    esp8266_send_cmd("AT+CIPSEND","OK",50);//开始发送数据
}

uint8_t esp8266_quit_trans(void)//退出透传模式
{
    uint8_t result=1;
    u2_printf("+++");
    HAL_Delay(1000);
    result=esp8266_send_cmd("AT","OK",20);
    return result;

}


void u2_printf(char* fmt)
{

    uint8_t num=0;
    char my_ch[50]={0};
    while(*fmt!=0)
        my_ch[num++]=*fmt++;//将信息储存在一个数组中

    my_ch[num++]='\r';//回车，光标移动到此行最前面
    my_ch[num++]='\n';//换行，光标移动到下一行

    HAL_UART_Transmit(&huart3, (uint8_t *)my_ch,num, 0xffff);//整个函数调用的目的是通过UART3模块发送存储在my_ch数组中的数据
    while(HAL_UART_GetState(&huart3) == HAL_UART_STATE_BUSY_TX);//会一直运行，直到UART传输完成，不再处于忙碌状态。

}


