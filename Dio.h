

#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

#include "std_types.h"
#include "Bitwise_Operations.h"
#include "Tiva_Registers.h"

typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;

#define GPIO_PORTA_BASE_CHANNEL     0
#define GPIO_PORTB_BASE_CHANNEL     8
#define GPIO_PORTC_BASE_CHANNEL     16
#define GPIO_PORTD_BASE_CHANNEL     24
#define GPIO_PORTE_BASE_CHANNEL     32
#define GPIO_PORTF_BASE_CHANNEL     38

#define GPIO_PORTA_END_CHANNEL          7
#define GPIO_PORTB_END_CHANNEL         15
#define GPIO_PORTC_END_CHANNEL         23
#define GPIO_PORTD_END_CHANNEL         31
#define GPIO_PORTE_END_CHANNEL         37
#define GPIO_PORTF_END_CHANNEL         45


Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);
void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level);
void Port_init(void);
#endif /* DIO_DRIVER_H_ */
