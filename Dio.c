#include "Dio.h"
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_LevelType ChannelValue=0;
//    unsigned long * DataReg= NULL;
    if (ChannelId>=GPIO_PORTA_BASE_CHANNEL && ChannelId<=GPIO_PORTA_END_CHANNEL)
    {
        ChannelValue=(GPIO_PORTA_DATA_R>>ChannelId);
    }
    else if (ChannelId>=GPIO_PORTB_BASE_CHANNEL && ChannelId<=GPIO_PORTB_END_CHANNEL) {
        ChannelValue=(GPIO_PORTB_DATA_R>>(ChannelId-GPIO_PORTB_BASE_CHANNEL));
    }
    else if (ChannelId>=GPIO_PORTC_BASE_CHANNEL && ChannelId<=GPIO_PORTC_END_CHANNEL) {
        ChannelValue=(GPIO_PORTB_DATA_R>>(ChannelId-GPIO_PORTC_BASE_CHANNEL));
    }
    else if (ChannelId>=GPIO_PORTD_BASE_CHANNEL && ChannelId<=GPIO_PORTD_END_CHANNEL) {
        ChannelValue=(GPIO_PORTD_DATA_R>>(ChannelId-GPIO_PORTD_BASE_CHANNEL));
    }
    else if (ChannelId>=GPIO_PORTE_BASE_CHANNEL && ChannelId<=GPIO_PORTE_END_CHANNEL) {
        ChannelValue=(GPIO_PORTE_DATA_R>>(ChannelId-GPIO_PORTE_BASE_CHANNEL));
    }
    else if (ChannelId>=GPIO_PORTF_BASE_CHANNEL && ChannelId<=GPIO_PORTF_END_CHANNEL) {
        ChannelValue=(GPIO_PORTF_DATA_R>>(ChannelId-GPIO_PORTF_BASE_CHANNEL));
    }
    return ChannelValue;
}
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    volatile unsigned long * DataReg= NULL;
    uint8 channel_num_in_port=0;
    if (ChannelId>=GPIO_PORTA_BASE_CHANNEL && ChannelId<=GPIO_PORTA_END_CHANNEL)
    {
        DataReg=&GPIO_PORTA_DATA_R;
        channel_num_in_port=ChannelId;
    }
    else if (ChannelId>=GPIO_PORTB_BASE_CHANNEL && ChannelId<=GPIO_PORTB_END_CHANNEL) {
        DataReg=&GPIO_PORTA_DATA_R;
        channel_num_in_port=ChannelId-GPIO_PORTB_BASE_CHANNEL;
    }
    else if (ChannelId>=GPIO_PORTC_BASE_CHANNEL && ChannelId<=GPIO_PORTC_END_CHANNEL) {
        DataReg=&GPIO_PORTC_DATA_R;
        channel_num_in_port=ChannelId-GPIO_PORTC_BASE_CHANNEL;
    }
    else if (ChannelId>=GPIO_PORTD_BASE_CHANNEL && ChannelId<=GPIO_PORTD_END_CHANNEL) {
        DataReg=&GPIO_PORTD_DATA_R;
        channel_num_in_port=ChannelId-GPIO_PORTD_BASE_CHANNEL;
    }
    else if (ChannelId>=GPIO_PORTE_BASE_CHANNEL && ChannelId<=GPIO_PORTE_END_CHANNEL) {
        DataReg=&GPIO_PORTE_DATA_R;
        channel_num_in_port=ChannelId-GPIO_PORTE_BASE_CHANNEL;
    }
    else if (ChannelId>=GPIO_PORTF_BASE_CHANNEL && ChannelId<=GPIO_PORTF_END_CHANNEL) {
        DataReg=&GPIO_PORTF_DATA_R;
        channel_num_in_port=ChannelId-GPIO_PORTF_BASE_CHANNEL;
    }
    if(GET_BIT(*DataReg,channel_num_in_port)==1)
    {
        SET_BIT(*DataReg,channel_num_in_port);
    }
    else
    {
        SET_BIT(*DataReg,channel_num_in_port);
    }
}
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    Dio_PortLevelType port_level=0;

    switch (PortId) {
        case 0:
            port_level=GPIO_PORTA_DATA_R;
            break;
        case 1:
            port_level=GPIO_PORTB_DATA_R;
            break;
        case 2:
            port_level=GPIO_PORTC_DATA_R;
            break;
        case 3:
            port_level=GPIO_PORTD_DATA_R;
            break;

        case 4:
            port_level=GPIO_PORTE_DATA_R;
            break;
        case 5:
            port_level=GPIO_PORTF_DATA_R;
            break;
        default:
            break;
    }

      return port_level;
}
void Dio_WritePort (Dio_PortType PortId,Dio_PortLevelType Level)

{
    switch (PortId) {
        case 0:
            GPIO_PORTA_DATA_R=Level;
            break;
        case 1:
            GPIO_PORTB_DATA_R=Level;
            break;
        case 2:
            GPIO_PORTC_DATA_R=Level;
            break;
        case 3:
            GPIO_PORTD_DATA_R=Level;
            break;

        case 4:
            GPIO_PORTE_DATA_R=Level;
            break;
        case 5:
            GPIO_PORTF_DATA_R=Level;;
            break;
        default:
            break;
    }
}
void portF_init()
{
    SYSCTL_RCGCGPIO_R  |= (1<<5);
    while(SYSCTL_RCGCGPIO_R&(1<<5)  ==0  ){}
    GPIO_PORTF_LOCK_R =0x4c4f434b;
    GPIO_PORTF_CR_R  =0x1f;
}

void configure_leds_switches() {
    GPIO_PORTF_DIR_R = 0x0E;
    GPIO_PORTF_PUR_R=0x11;
    GPIO_PORTF_DEN_R = 0x1f;
}
void Port_init(void){
    portF_init();
    configure_leds_switches();
}
