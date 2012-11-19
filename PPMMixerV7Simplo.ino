/*
PPM Mixer V7 Simplo
 ferrara [ar] libero.it
 */
#define MAXCHANIN 5

/** RX Section **/
//***********************************************************************************************************************
int rawIn[MAXCHANIN];

void setupRx()
{
  pinMode(2, INPUT); // 3 is used for esc
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  // interrupt on pin change PCINT
  PCICR |= (1 << PCIE2);

  PCMSK2 = (1 << PCINT18) | // pin2
  (1 << PCINT20) | // pin4
  (1 << PCINT21) | // pin5
  (1 << PCINT22) | // pin6
  (1 << PCINT23) ; // pin7 // not need if you don't use RXDIRECT
}

#define MASKPCINT0 (1<<2)
#define MASKPCINT1 (1<<4)
#define MASKPCINT2 (1<<5)
#define MASKPCINT3 (1<<6)
#define MASKPCINT4 (1<<7)
  
ISR(PCINT2_vect)
{
  static byte newbit,oldbit,changed;
  static unsigned long startIn[MAXCHANIN];
  static unsigned long time;
  time=micros(); 

  newbit=PIND;

  // This is a new VERY VERY VERY fast method 
  // 1 xor operation 


  changed=newbit^oldbit;

  if (changed&MASKPCINT0)
    if (newbit&MASKPCINT0) startIn[0]=time;
    else rawIn[0]=time-startIn[0];

  if (changed&MASKPCINT1)
    if (newbit&MASKPCINT1) startIn[1]=time;
    else rawIn[1]=time-startIn[1];

  if (changed&MASKPCINT2)
    if (newbit&MASKPCINT2) startIn[2]=time;
    else rawIn[2]=time-startIn[2];

  if (changed&MASKPCINT3)
    if (newbit&MASKPCINT3) startIn[3]=time;
    else rawIn[3]=time-startIn[3];

  if (changed&MASKPCINT4)
    if (newbit&MASKPCINT4) startIn[4]=time;
    else rawIn[4]=time-startIn[4];

  oldbit=newbit;
}

void print()
{
  Serial.print(rawIn[0]);
  for(int i=1;i<MAXCHANIN;i++) {
    Serial.print(",");
    Serial.print(rawIn[i]);
  }
  Serial.println();
}
   
int limit(int mn,int in,int mx) 
{
  int out;

  if (in<mn) out=mn;
  else if (in>mx) out=mx;
  else out=in;

  return out;
}

void clear()
{
  for(byte i=0; i < MAXCHANIN; i++) {
    rawIn[i] = 0;
  }
}

/**************************************************************************************************/

void setup()
{
  setupRx();
  Serial.begin(115200);
}

void loop()
{
  print();
  clear();
  delay(20);
}

