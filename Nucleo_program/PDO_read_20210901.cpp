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
    
    // show information of slave
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
    
    addr = PDI_Control;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_8bit,addr);
    sprintf(S1,"PDI_Control[0x%04X]: 0x%02lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    
    // プロセスデータRAMにアクセス可能な状態かどうかを確認
    // (0x0110~0x0111の16ビットの0バイト目が立っているか？）
    // addr = ESC_DL_Status;
    // uint8_t esc_dl_state = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_8bit, addr);
    // sprintf(S1,"ESC_DL_Status[0x%04X]: 0x%04lX \n\r",addr,esc_dl_state);
    // UART_TX_Stringth(S1);
    
    // debug
    /*
    uint32_t cmd;
    uint16_t pdo_addr = 0x1000;
    cmd = (1<<31)|(1<<30)|(CSR_SIZE_32bit<<16)|(pdo_addr);
    sprintf(S1,"ECAT_CSR_CMD: 0x%08lX \n\r",cmd);
    UART_TX_Stringth(S1);
    */
    
    uint32_t buffer[5];
    while(1) {
        // ECAT_PRAM_RD_ADDR_LEN
        // read 12byte for example
        
        // read first 4byte
        buffer[0] = LAN9252_EtherCAT_PRAM_READ(4, 0x1000);
        buffer[1] = LAN9252_EtherCAT_PRAM_READ(4, 0x1004);
        buffer[2] = LAN9252_EtherCAT_PRAM_READ(4, 0x1008);
        buffer[3] = LAN9252_EtherCAT_PRAM_READ(4, 0x100C);
        buffer[4] = LAN9252_EtherCAT_PRAM_READ(4, 0x1010);
        
        printf("Process_Data[0x%04X]: 0x%08lX \n\r",0x1000,buffer[0]);  // show first byte
        printf("Process_Data[0x%04X]: 0x%08lX \n\r",0x1004,buffer[1]);  // show next byte
        printf("Process_Data[0x%04X]: 0x%08lX \n\r",0x1008,buffer[2]);  // show last byte
        printf("Process_Data[0x%04X]: 0x%08lX \n\r",0x100C,buffer[3]);  // show last byte
        printf("Process_Data[0x%04X]: 0x%08lX \n\r",0x1010,buffer[4]);  // show last byte
        printf("\r\n");
        wait_ms(2000);
    }
}
