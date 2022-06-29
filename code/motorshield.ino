#include<AFMotor.h>
#define ki1 12
#define ki2 13
AF_DCMotor leftf(1);
AF_DCMotor leftb(2);
AF_DCMotor rightf(3);
AF_DCMotor rightb(4);

int mov=1;
char value=NULL;  
void setup(){
  pinMode(ki1,OUTPUT);   //kick 1
  pinMode(ki2,OUTPUT);   //kick 2
  
  Serial.begin(9600);
}

void loop()
 {
//  Serial.println(RELEASE);
if(Serial.available()>0)
  {
    value = Serial.read();   
//////////////////////////////////////////////front is front
 //--------------------FORWARD------------------------------
     if(value=='F')
     {
          mv(1,1,255,255);   
      }
//--------------------FORWARD LEFT------------------------------
    else if(value=='G')
    {
         mv(1,1,0,255);
    }
//--------------------FORWARD RIGHT------------------------------
    else if(value=='I')
    {
         mv(1,1,255,0);
     }
//--------------------BACKWARD------------------------------
     else if(value=='B')
     {
         mv(2,2,255,255);
      }

//--------------------BACKWARD LEFT------------------------------

      else if(value=='H')
      {
         mv(2,2,255,0);   
       }
//--------------------BACKWARD RIGHT------------------------------
      else if(value=='J')
      {
         mv(2,2,0,255);
      }
 //----------------------RIGHT-----------------------------------
     else if(value=='R')
     {  
          mv(1,2,255,255);
       }
 //--------------------LEFT------------------------------
     else if(value=='L')
      {
          mv(2,1,255,255);
       }
      else if(value=='W')
      {
         digitalWrite(ki1,1);
         digitalWrite(ki2,0);
       }
       else if(value=='w')
      {
         digitalWrite(ki1,0);
         digitalWrite(ki2,0);
       }
     else if(value=='S' || value==NULL){
          mv(4,4,0,0);
      }
 }
 
 }
///////functions///////////////////////////
 void mv(int c1,int c2,int s1,int s2){  ///c1:control 1 and etc...s1:speed 1 and etc.. 
         leftf.run(c1);
         leftb.run(c1);
         rightf.run(c2);
         rightb.run(c2);     
         leftf.setSpeed(s1);
         leftb.setSpeed(s1);
         rightf.setSpeed(s2); 
         rightb.setSpeed(s2); 
  }
