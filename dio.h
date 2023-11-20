void Dio_Init(char port);
void Dio_WritePin(volatile unsigned long reg, int bit_pos, int bit_value);
void Dio_WritePort(volatile unsigned long reg, unsigned int val);
void DIO_ReadPin(volatile unsigned long reg, int bit_pos);


