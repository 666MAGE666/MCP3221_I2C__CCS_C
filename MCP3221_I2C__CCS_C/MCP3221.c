#include <MCP3221.h>
unsigned int16 adc_deger =0 ;


unsigned int16 mcp_okuma()
{
   unsigned int16 okunan_deger=0;
   unsigned int msb =0 , lsb=0;
   i2c_start();
   i2c_write(0x9B); // 0x9B cihaz adresi
//!   delay_us(10);
   msb = i2c_read(); // 4 bit 
   lsb = i2c_read(0);  // 8 bit 
   i2c_stop();
   okunan_deger =  make16(msb,lsb); // make16 ile birlestirildi .
   return(okunan_deger);
}

void main()
{



   while(TRUE)
   {

      delay_ms(100);
    adc_deger =  mcp_okuma();
    printf("Okunan 12Bit Adc : %lu\n\r",adc_deger);

      //TODO: User Code
   }

}
