#include "mbed.h"

DigitalOut myled(LED1), bpin(PTB0), upP(PTD4), dnP(PTD3);
DigitalIn apin(PTE30);
Timer Talwayson;
Timer DebounceTimer;
int lastbtn, btnval, up, dn, reportime;

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
    bool SWflag;
    bool Tflag = false;

    while (1)
    {

        SWflag = false;

        btnval = apin;         // read the button input
        if (btnval != lastbtn) // watch for changes
        {
            if (Tflag == false)
            {
                if (btnval == 1)
                { // found a rising edge
                    DebounceTimer.start();
                    Tflag = true;
                }
            }
            else
            {
                SWflag = false;
            }
        }
        else
        {
            if (DebounceTimer.read_us() > 2000)
            {
                btnval = apin;
                if (btnval == 1)
                {
                    SWflag = true;
                }
                else
                {
                    SWflag = false;
                }
                Tflag = false;
            }
        }
        if (SWflag == true)
        {
            bpin = btnval;
        }
    }
    if (reportime < Talwayson.read_us()) // wait till time passed
    {                                    // make report to serial output, reset counts
        reportime = Talwayson.read_us() + reporttinterval;
        printf(" report up, dn: %i %i %i\n\r", reportime, up, dn);
        up = 0;
        dn = 0;
    }
    lastbtn = btnval; // keep track of history
    myled = !lastbtn; // keep the red led right
}