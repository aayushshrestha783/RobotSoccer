  
#define lm1 7
#define lm2 8
#define rm1 4
#define rm2 9
#define ki1 12
#define ki2 13
#define PWM1 5
#define PWM2 6
int mov=1;
char value=NULL;  
void setup(){
  pinMode(lm1,OUTPUT);   //left motors 1
  pinMode(lm2,OUTPUT);   //left motors 2
  pinMode(rm1,OUTPUT);   //right motors 1
  pinMode(rm2,OUTPUT);   //right motors 2
  pinMode(ki1,OUTPUT);   //kick 1
  pinMode(ki2,OUTPUT);   //kick 2
  pinMode(PWM1,OUTPUT);   //PWM LEFT motor speed
  pinMode(PWM2,OUTPUT);   //PWM RIGHT motor speed
  
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
  Serial.begin(9600);
}

void loop()
 {
if(Serial.available()>0)
  {
    value = Serial.read();   
//////////////////////////////////////////////front is front
 //--------------------FORWARD------------------------------
     if(value=='F')
     {
          mv(0,1,0,1,255,255);   
      }
//--------------------FORWARD LEFT------------------------------
    else if(value=='G')
    {
         mv(0,1,0,1,0,255);
    }
//--------------------FORWARD RIGHT------------------------------
    else if(value=='I')
    {
         mv(0,1,0,1,255,0);
     }
//--------------------BACKWARD------------------------------
     else if(value=='B')
     {
         mv(1,0,1,0,255,255);
      }

//--------------------BACKWARD LEFT------------------------------

      else if(value=='H')
      {
         mv(1,0,1,0,255,0);   
       }
//--------------------BACKWARD RIGHT------------------------------
      else if(value=='J')
      {
         mv(1,0,1,0,0,255);
      }
 //----------------------RIGHT-----------------------------------
     else if(value=='R')
     {  
          mv(1,0,0,1,255,255);
       }
 //--------------------LEFT------------------------------
     else if(value=='L')
      {
          mv(0,1,1,0,255,255);
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
          mv(0,1,0,0,0,0);
      }
 }
 
 }
///////functions///////////////////////////
 void mv(int c1,int c2,int c3,int c4,int s1,int s2){  ///c1:control 1 and etc...s1:speed 1 and etc.. 
         digitalWrite(lm1,c1);
         digitalWrite(lm2,c2);
         digitalWrite(rm1,c3);
         digitalWrite(rm2,c4);      
         analogWrite(PWM1,s1);
         analogWrite(PWM2,s2); 
  }
