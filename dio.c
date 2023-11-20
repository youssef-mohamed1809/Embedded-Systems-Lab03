#include "dio.h"
#include "bitwise_op.h"
#include "tm4c123gh6pm.h"


void Dio_Init(char port){
    switch(port){
        case 'A':
            SYSCTL_RCGCGPIO_R |= 0x00000001;
             while((SYSCTL_PRGPIO_R & 0x00000001) == 0){};
             GPIO_PORTA_LOCK_R = 0x4C4F434B;
             GPIO_PORTA_CR_R = 0x1F;
             GPIO_PORTA_DIR_R = 0x0E;
             //GPIO_PORTA_PUR_R = 0x11;
             GPIO_PORTA_DEN_R = 0x1F;
            break;
        case 'B':
        SYSCTL_RCGCGPIO_R |= 0x00000002;
         while((SYSCTL_PRGPIO_R & 0x00000002) == 0){};
             GPIO_PORTB_LOCK_R = 0x4C4F434B;
             GPIO_PORTB_CR_R = 0x1F;
             GPIO_PORTB_DIR_R = 0x0E;
             GPIO_PORTB_PUR_R = 0x11;
             GPIO_PORTB_DEN_R = 0x1F;
            break;
        case 'C':
        SYSCTL_RCGCGPIO_R |= 0x00000004;
         while((SYSCTL_PRGPIO_R & 0x00000004) == 0){};
             GPIO_PORTC_LOCK_R = 0x4C4F434B;
             GPIO_PORTC_CR_R = 0x1F;
             GPIO_PORTC_DIR_R = 0x0E;
             //GPIO_PORTC_PUR_R = 0x11;
             GPIO_PORTC_DEN_R = 0x1F;
            break;
        case 'D':
        SYSCTL_RCGCGPIO_R |= 0x00000008;
         while((SYSCTL_PRGPIO_R & 0x00000008) == 0){};
             GPIO_PORTD_LOCK_R = 0x4C4F434B;
             GPIO_PORTD_CR_R = 0x1F;
             GPIO_PORTD_DIR_R = 0x0E;
             //GPIO_PORTD_PUR_R = 0x11;
             GPIO_PORTD_DEN_R = 0x1F;
            break;
        case 'E':
        SYSCTL_RCGCGPIO_R |= 0x00000010;
         while((SYSCTL_PRGPIO_R & 0x00000010) == 0){};
             GPIO_PORTE_LOCK_R = 0x4C4F434B;
             GPIO_PORTE_CR_R = 0x1F;
             GPIO_PORTE_DIR_R = 0x0E;
             //GPIO_PORTE_PUR_R = 0x11;
             GPIO_PORTE_DEN_R = 0x1F;
            break;
        case 'F':
            SYSCTL_RCGCGPIO_R |= 0x00000020;
             while((SYSCTL_PRGPIO_R & 0x00000020) == 0){};
             GPIO_PORTF_LOCK_R = 0x4C4F434B;
             GPIO_PORTF_CR_R = 0x1F;
             GPIO_PORTF_DIR_R = 0x0E;
             GPIO_PORTF_PUR_R = 0x11;
             GPIO_PORTF_DEN_R = 0x1F;
            break;
    }    
}

void Dio_WritePin(volatile unsigned long reg, int bit_pos, int bit_value){
    if(bit_value == 1){
        set_bit(reg, bit_pos);
    }else if(bit_value == 0){
        set_bit(reg, bit_pos);
    }
}

void Dio_WritePort(volatile unsigned long reg, unsigned int val){
    int pos = 0;
    while (val > 0){
        if(val & 0x01){
            Dio_WritePin(reg, pos, 1);
        }else{
            Dio_WritePin(reg, pos, 0);
        }
        reg >>= 1;
        pos++;
    }
}

int DIO_ReadPin(volatile unsigned long reg, int bit_pos){
    return get_bit(reg, bit_pos);
}

unsigned long int DIO_ReadPort(volatile unsigned long reg){
    return reg;
}