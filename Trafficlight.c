include <xc.h>
void delay(long);
void main(void) 
{
    TRISC = 0x00;
    TRISD = 0x00;
    TRISB = 0x00;
    ADCON1 = 0x0F;
    T0CON = 0x87;
    TMR0IE = TMR0IP = 1;
    GIE = 1;
    RC4 = RB3 = RB2 = RB1 = 0;
    while(1)
    {
       
        RC1 = 0; // sig1 red off
        RC3 = 1; // sig1 green
        RD6 = RC6 = RD2 = 1; // all reds on
        RC0 = 1; // sig1 rt
        delay(500000);
        RC0 = 0; // sig1 rt off
        delay(100000);
        RD2 = 0;
        RD4 = 1; // sig3 on
        delay(500000);
        RC3 = 0; // sig 1 off
        RC2 = 1; // SIG1 yellow
        delay(100000);
        RC2 = 0;
        RC1 = 1; // sig 1 red
        RD1 = 1; // sig 3 rt
        delay(500000);
        RD4 = RD1 = 0;
        RD3 = 1; // SIG2 yellow
        delay(100000);
        RD3 = 0;
        RD2 = 1; // sig 2 red
        delay(100000);
        RD6 = 0;
        RB0 = 1; // sig4 green
        RD5 = 1; // sig4 rt
        delay(500000);
        RD5 = 0; // sig4 rt off
        delay(100000);
        RC6 = 0;
        RD0 = 1; // sig2 on
        delay(500000);
        RB0 = 0; // sig 4 off
        RD7 = 1; // SIG4 yellow
        delay(100000);
        RD7 = 0;
        RD6 = 1; // sig 4 red
        RC5 = 1; // sig 2 rt
        delay(500000);
        RD0 = RC5 = 0;
        RC7 = 1; // SIG2 yellow
        delay(100000);
        RC7 = 0;
        RC6 = 1; // sig 2 red
        delay(100000);
       
    }
    return;
         
    }
void delay(long k)
{
    for(long i=0; i<k;i++);
}

void __interrupt() isr()
{
    TMR0 = 46004;
    RC4 = !RC4;
    RB3 = !RB3;
    RB2 = !RB2;
    RB1 = !RB1;

   
    TMR0IF = 0;
}