#include "mbed.h"
#include <string>

#include "LAN9252.h"
#include "LAN925X_SPI.h"


//DigitalOut myled(LED1);
Serial serial(USBTX, USBRX);

 void UART_TX_Stringth(char S1[])
{
    serial.printf(S1);
}


int main() {
    uint32_t rdata;
    //uint32_t rdata_buff[100];
    //int cnt=0;
    uint32_t wdata;
    char  S1[100];
    uint16_t addr=0;
    
    serial.baud(115200);
    UART_TX_Stringth("================================================== \n\r");
    UART_TX_Stringth("   EtherCAT TEST   \n\r");
    UART_TX_Stringth("================================================== \n\r");
    
    LAN925X_SPI_Init();
    // RESET
    //LAN9252_RESET();

    addr = ID_REV;
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"ID_REV[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    addr = BYTE_TEST;
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"BYTE_TEST[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    addr = FREE_RUN;
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"FREE_RUN[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

        
    addr = Type_Register;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Type_Register[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    addr = Product_ID;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Product_ID[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

    addr = Vendor_ID;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Vendor_ID[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

    addr = Process_Data_RAM;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Process_Data_RAM[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    addr = RUN_LED_Override;    // Definition: 0x0138
    LAN9252_EtherCAT_CSR_WRITE(CSR_SIZE_32bit,addr,1<<4 | 0x0D);
    
    while(1) {
        // Definition: Process_Data_RAM = 0x1000
        addr = Process_Data_RAM;
        rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr); //LAN9252.cppで定義された関数を使って指定されたアドレスのデータを変数に格納 
        sprintf(S1,"Process_Data_RAM[0x%04X]: 0x%08lX \n\r",addr,rdata); // 16進法で表示
        //sprintf(S1,"Process_Data_RAM[0x%04X]: %d \n\r",addr,rdata); // 10進法で表示
        UART_TX_Stringth(S1);
        
        // Read Digital I/O Output data
        // SOEMのIOmap[1], IOmap[0]が読める！
        addr = Digital_IO_Output_Data;
        rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
        sprintf(S1,"Digital Output[0x%04X]: 0x%08lX \n\r",addr,rdata); // 16進法で表示
        UART_TX_Stringth(S1);
        
        UART_TX_Stringth("\r\n");
        wait_ms(2000);
    }
}
