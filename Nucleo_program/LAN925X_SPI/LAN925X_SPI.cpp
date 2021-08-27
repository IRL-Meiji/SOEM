#include "LAN925X_SPI.h"
#include <stdint.h>

#include "mbed.h"
//********************************************************************//
// HardWare Interface
//********************************************************************//

#define     SPI_CS_LOW()    cs = 0;
#define     SPI_CS_HIGH()   cs = 1;

SPI spi(PA_7, PA_6, PA_5); // mosi, miso, sclk
DigitalOut cs(PB_6);

void LAN925X_SPI_Init(void)
{   
   SPI_CS_HIGH();
    // Setup the spi for 8 bit data, high steady state clock,
    // second edge capture, with a 1MHz clock rate
    spi.format(8,3);
    spi.frequency(20000000);
}
uint8_t SPI_8bit_Read(void)
{
    return spi.write(0x00);
}
void SPI_8bit_Write(uint8_t wdata)
{
    spi.write(wdata);
}

void SQI_RESET(void)
{
    //SS2_SetDigitalInput();
    //while(SS2_GetValue()!=1);
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_LOW();
    SPI_8bit_Write(0xFF);
    SPI_CS_HIGH();
}




uint32_t LAN925X_SPI_READ(uint16_t addr)
{
    uint32_t rdata;
    SPI_CS_LOW();
    SPI_8bit_Write(0x03); //Instruction
    SPI_8bit_Write( 0xFF&(addr>>8) ); //Address
    SPI_8bit_Write( 0xFF&(addr>>0) ); //Address
    rdata =  (uint32_t)SPI_8bit_Read();
    rdata |= (uint32_t)SPI_8bit_Read()<<8;
    rdata |= (uint32_t)SPI_8bit_Read()<<16;
    rdata |= (uint32_t)SPI_8bit_Read()<<24;
    SPI_CS_HIGH();
    return rdata;
}

uint32_t LAN925X_SPI_WRITE(uint16_t addr,uint32_t data)
{
    uint32_t rdata;
    SPI_CS_LOW();
    SPI_8bit_Write(0x02); //Instruction
    SPI_8bit_Write( 0xFF&(addr>>8) ); //Address
    SPI_8bit_Write( 0xFF&(addr>>0) ); //Address
    SPI_8bit_Write( 0xFF&(data>>0) );
    SPI_8bit_Write( 0xFF&(data>>8) );
    SPI_8bit_Write( 0xFF&(data>>16) );
    SPI_8bit_Write( 0xFF&(data>>24) );
    SPI_CS_HIGH();
    return rdata;
}

