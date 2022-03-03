#include "mbed.h"

DigitalOut myled(LED1), bpin(PTB0), upP(PTD4), dnP(PTD3);
DigitalIn apin(PTE30);
Timer Talwayson;

Int lastbtn, btnval, up, dn, reportime;

int main()
{
    Talwayson.start();
    int reporttinterval = 2000000;
    reportime = reporttinterval;
    printf("Starting button timer \n");

    lastbtn = apin;
    bpin = lastbtn;
    up = 0;
    dn = 0;
    dnP = 0;
    upP = 0;
    while (1)
    {
        btnval = apin; // read the button input
        bpin = btnval;

        if (btnval != lastbtn) // watch for changes
        {
            if (btnval == 1)
            { // found a rising edge
                up++;
                upP = up & 1; // send signal to GPIO
            }
            else
            {
                // falling edge
                dn++;
                dnP = dn & 1; // send down signal to GPIO
            }
        }

        if (reportime < Talwayson.read_us()) // wait till time passed
        {
            // make report to serial output, reset counts
            reportime = Talwayson.read_us() + reporttinterval;
            printf(" report up, dn: %i %i %i\n", reportime, up, dn);
            up = 0;
            dn = 0;
        }

        lastbtn = btnval; // keep track of history
        myled = !lastbtn; // keep the red led right
    }
}