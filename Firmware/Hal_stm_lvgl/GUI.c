#include "lcd.h"
#include "string.h"
//#include "font.h"
#include "spi.h"
#include "GUI.h"
#include "dma.h"
#include "lvgl.h"

void GUI_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,lv_color_t *color)
{
    u32 num;
    num=(xend-xsta+1)*(yend-ysta+1)*sizeof(lv_color_t);
    LCD_Address_Set(xsta,ysta,xend,yend);//������ʾ����
    LCD_CS_CLR;
    LCD_RS_SET;
    HAL_SPI_Transmit_DMA(&hspi1,(uint8_t*)color,num);

}

extern lv_disp_drv_t * disp_drv_p;		//��Ļ�����ṹ���ַ����lv_port_disp.c�ж��壬disp_flush()�����б���ֵ
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi->Instance == SPI1){
        LCD_CS_SET;
        lv_disp_flush_ready(disp_drv_p);
    }

}

