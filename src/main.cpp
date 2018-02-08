#include <mbed.h>
#include <C12832.h>
#include <FXOS8700Q.h>

I2C i2c(PTE25, PTE24);
FXOS8700QAccelerometer acc(i2c, FXOS8700CQ_SLAVE_ADDR1);
FXOS8700QMagnetometer  mag(i2c, FXOS8700CQ_SLAVE_ADDR1);

Serial pc(USBTX, USBRX);

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);

int main()
{
    motion_data_units_t acc_data;

    acc.enable();

    while(true) {
      acc.getAxis(acc_data);

      lcd.locate(0, 0);
      lcd.printf("ACC: X=%+1.3f Y=%+1.3f Z=%+1.3f \t",
                acc_data.x, acc_data.y, acc_data.z);
      lcd.locate(0,20);
      if (acc_data.y>0){
        lcd.printf("Up  ");
        }
        else{
          lcd.printf("Down");
        }
    }
}
