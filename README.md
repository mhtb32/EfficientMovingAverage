# Efficient Moving Average
This is an efficient implementation of moving average filter intended to be used for micro-controllers, Tested on STM32 series.

# Example code
This is a pseudo-code showing how one can use this library for his/her desired target platform.
```c
volatile uint32_t ADCValue = 0;
uint32_t ADCValueFiltered = 0;
FilterTypeDef filterStruct;

int main(void)
{

    Moving_Average_Init(&filterStruct);

    while(1)
    {
        ADCValue = ADC_Get_Value(adc);
        ADCValueFiltered = Moving_Average_Compute(ADCValue, &filterStruct);
    }

    return 0;
}
```
You can change length of filter window by changing `#define WindowLength 10` in header file.

# Acknowledgement
I would like to thank [Sepehr Hashtroudi](https://github.com/sepehrhashtroudi) for all the improvements he suggested to my original implementation of algorithm.
