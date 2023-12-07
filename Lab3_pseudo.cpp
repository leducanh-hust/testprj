#include<iostream>

int main()
{
    //After initialization
    int changeSwitch = 0, breatheswitch = 0;
    while(1) // loop
    {
        //read data from port E at PE0 ( read Change Switch )
        R0 = GPIO_PORTE_DATA_R;
        R0 = R0 & 0x01; // bit mask to check

        if(changeSwitch ==0) // change switch is not pressed
        {
            R0 = GPIO_PORTE_DATA_R;
            R0 = R0 & 0x08; // bit mask to check PE3( breath switch )

            if(breatheswitch == 0)
            {
                //......
            }
            if(breatheswitch == 1)
            {
                //read data from port E at PE0 ( read Change Switch )
                //if breath is still pressed, breatheswitch = held
                //if breath is released, breatheswitch = 0
                if(breatheswitch == 0)
                {
                    //default state: toggle at 2Hz, duty cucle = 30
                }
                if(breatheswitch == 1)
                {
                    //breathing LED
                }
            }
        }
        if(changeSwitch == 1) // change switch is pressed
        {
            //read data from port E at PE0 ( read Change Switch )
            //if change is still pressed, changeSwitch = held
            //if change is released, changeSwitch = 0
            if(changeSwitch == 0)
            {
                //increase duty cycle by 20%
                // if(duty cycle > 90)
                // {
                //     //duty cycle = 10
                // }
            }
            if(changeSwitch == 1) // held
            {
                //default state: toggle at 2Hz, duty cucle = 30
            }
        }
        
    }
}