unsigned okunan,
int ledler;

void kurulum(){
         GPIO_Digital_Output(GPIO_BASE,_GPIO_PINMASK_12|_GPIO_PINMASK_13|_GPIO_PINMASK_13|_GPIO_PINMASK_14|_GPIO_PINMASK_15);
         ADC1_Init();
         ADC_Set_Input_Channel(_ADC_CHANNEL_1);
}

void main() {
           kurulum();
           while(1){
           okunan=ADC1_Get_Sample(1);
           if(okunan>=0&&okunan<2048){GPIOD_ODR=0x1000;}
           else if (okunan>=2048&&okunan<3072){GPIOD_ODR=0x2000;}
           else if (okunan>=3072&&okunan<4096){GPIOD_ODR=0x3000;}
           else if (okunan>4096){GPIOD_ODR=0x4000;}
           }
           else
           {
           GPIOD_ODR.B12=0;
           delay_ms(150);}
}
