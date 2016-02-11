//*****************************************************************************
//RobotAnt V1.0
//阿布拉機的3D列印與機器人
//http://arbu00.blogspot.tw/
//
//2016/02/11 Writen By Ashing Tsai
//******************************************************************************
#include <Servo.h> 
Servo servo1;  //pin D2
Servo servo2;  //pin D3
Servo servo3;  //pin D4

const int ledA=6;
const int speaker=5;
int angle;
//================================
char toneName[]="CDEFGAB";
unsigned int frequency[7]={523,587,659,694,784,880,988};
char beeTone[]="GEEFDDCDEFGGGGEEFDDCEGGEDDDDDEFEEEEEFGGEEFDDCEGGC";
char starTone[]="CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";
byte beeBeat[]={1,1,2,1,1,2,1,1,1,1,1,1,2,
              1,1,2,1,1,2,1,1,1,1,4,
              1,1,1,1,1,1,2,1,1,1,1,1,1,2,
              1,1,2,1,1,2,1,1,1,1,4}; 
byte starBeat[]={1,1,1,1,1,1,2,1,1,1,1,1,1,2,
              1,1,1,1,1,1,2,1,1,1,1,1,1,2,
              1,1,1,1,1,1,2,1,1,1,1,1,1,2};
unsigned long tempo=200;   
const int beeLen=sizeof(beeTone);
const int starLen=sizeof(starTone);
int len=0;
int num;
//===============================
void setup() 
{ 
  pinMode(ledA,OUTPUT);
  
  //=============================
//	 len=starLen;
//	while( len>0) 
 // {
 //   playTone(starTone[num],starBeat[num]); 
 //   num++;
//    len--;
//  }   
  //============================
   servo1.attach(2,500,2500);
   servo1.write(90);
   servo2.attach(3,500,2500);
   servo2.write(90); 
   servo3.attach(4,500,2500);
   servo3.write(90);
   delay(500);
} 
void loop() 
{
   
  frontward();
 // backward();
//rightward();
//leftward(); 


} 
//LedA blink 
void LedABlink()
{
  digitalWrite(ledA,HIGH);
  delay(50);
  digitalWrite(ledA,LOW);
  delay(50);
 
}
void Speakersound() 
{
  for(int i=0;i<5;i++)
  {
    tone(speaker,1000);
    delay(25);
    tone(speaker,500);
    delay(25);
  }
  noTone(speaker);
 // delay(500);    
}
void playTone(char toneNo,byte beatNo)
{
  unsigned long duration=beatNo*60000/tempo;
  int i;
  for(i=0;i<7;i++)
  {
    if(toneNo==toneName[i])
    {
      tone(speaker,frequency[i]);
      delay(duration);
      noTone(speaker);
    } 
  } 
} 


void frontward() 
{


  //----------------------------------------------
    digitalWrite(ledA,HIGH);
    servo3.attach(4,500,2500);
    servo3.write(120);                         //right low  ,left high  d4
    Speakersound();  //delay(250);
    delay(250);
	
	  digitalWrite(ledA,LOW);

    servo1.attach(2,500,2500);
    servo1.write(110);                          //left  leg back  big value to back  d2

    servo2.attach(3,500,2500);
    servo2.write(110);                         // right leg front  big value to front  d3
    delay(500);
   
    //=======================================================
	 digitalWrite(ledA,HIGH);
    servo3.attach(4,500,2500);
    servo3.write(60);                         //right high  ,left low
    Speakersound();  //delay(250);
	  delay(250);
    
   	digitalWrite(ledA,LOW);
    servo2.attach(3,500,2500);
    servo2.write(75);                           // right leg back  small value to back 

    
   
    servo1.attach(2,500,2500);
    servo1.write(70);                           //left  leg front   small value to front 

    delay(500);
    
} 


void backward() 
{
  //----------------------------------------------
    servo3.attach(4,500,2500);
    servo3.write(120);                         //right low  ,left high
    Speakersound();  //delay(250);
    delay(250);
	  digitalWrite(ledA,HIGH);
    servo1.attach(2,500,2500);
    servo1.write(75);                           //left  leg front   small value to front 
   
	
	  digitalWrite(ledA,LOW);
    servo2.attach(3,500,2500);
    servo2.write(70);                           // right leg back  small value to back 
    delay(500);
	


    //=======================================================
    servo3.attach(4,500,2500);
    servo3.write(60);                         //right high  ,left low
    Speakersound();  //delay(250);
   	delay(250);
    
	  digitalWrite(ledA,HIGH);
    servo2.attach(3,500,2500);
    servo2.write(105);                         // right leg front  big value to front 
  
    
    
    digitalWrite(ledA,LOW);
    servo1.attach(2,500,2500);
    servo1.write(110);                          //left  leg back  big value to back 
    delay(500);

} 

void rightward() 
{
  //----------------------------------------------
    servo3.attach(4,500,2500);
    servo3.write(120);                         //right low  ,left high
    Speakersound();  //delay(250);
    delay(250);
    
    digitalWrite(ledA,HIGH);
    servo1.attach(2,500,2500);
    servo1.write(102);                          //left  leg back  big value to back 
   
	
	
    digitalWrite(ledA,LOW);
    servo2.attach(3,500,2500);
    servo2.write(78);                           // right leg back  small value to back 
    delay(300);
	


    //=======================================================
    servo3.attach(4,500,2500);
    servo3.write(60);                         //right high  ,left low
    Speakersound();  //delay(250);
    

    
    digitalWrite(ledA,HIGH);
    servo1.attach(2,500,2500);
    servo1.write(68);                           //left  leg front   small value to front 

    
	  digitalWrite(ledA,LOW);
    servo2.attach(3,500,2500);
    servo2.write(118);                         // right leg front  big value to front 
    delay(300);
} 

void leftward() 
{
  //----------------------------------------------
    servo3.attach(4,500,2500);
    servo3.write(120);                         //right low  ,left high
    Speakersound();  //delay(250);
    
	   digitalWrite(ledA,HIGH);
    servo1.attach(2,500,2500);
    servo1.write(68);                           //left  leg front   small value to front 
   
 

    digitalWrite(ledA,LOW);
    servo2.attach(3,500,2500);
    servo2.write(118);                         // right leg front  big value to front 
    delay(300);

    //=======================================================
    servo3.attach(4,500,2500);
    servo3.write(60);                         //right high  ,left low
    Speakersound();  //delay(250);
    
  	digitalWrite(ledA,HIGH);
    servo1.attach(2,500,2500);
    servo1.write(102);                          //left  leg back  big value to back 

	
    digitalWrite(ledA,LOW);
    servo2.attach(3,500,2500);
    servo2.write(78);                           // right leg back  small value to back 
    delay(300);
    
 
    
} 
