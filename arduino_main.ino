#include<Servo.h>
#define ACTIVATED LOW
Servo s1,s2,s3,s4,s5,s6;
Servo d1,d2,d3,d4,d5,d6;
String receivedString,receivedCommand;
int move[3];
bool counterStart=false;
int counter=0,stringLength=6;
int button=4;
int i=1;
void setup() {
  // put your setup code here, to run once:

  //for alphabets
  s1.attach(A0);
  s2.attach(A1);
  s3.attach(A2);
  s4.attach(A3);
  s5.attach(A4);
  s6.attach(A5);
  //for 2nd braille
  d1.attach(3);
  d2.attach(5);
  d3.attach(6);
  d4.attach(9);
  d5.attach(10);
  d6.attach(11);
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
//  digitalWrite(button,LOW);
}

void receieveData(){
  while(Serial.available())
  {
    char c = Serial.read();
    Serial.print(c);

    if (c=='$'){
      counterStart = true;
    }
    if(counterStart)
      if(counter<stringLength)
      {
        receivedString = String(receivedString+c);
        counter++;
      }
  }
}

void receieveMovement(){
  while(Serial.available())
  {
    char c2 = Serial.read();
    Serial.print(c2);

    if (c2=='$'){
      counterStart = true;
    }
    if(counterStart)
      if(counter<4)
      {
        receivedCommand = String(receivedCommand+c2);
        counter++;
      }
      if(counter>=4)
      {
        move[0]=receivedCommand.substring(1,1).toInt();
        move[1]=receivedCommand.substring(2,2).toInt();
        move[2]=receivedCommand.substring(3,3).toInt();
        receivedCommand="";
        counter=0;
        counterStart=false;
      }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //receieveData();
  receieveMovement();
  String word = receivedString;

   if(move[1]==1 && move[2]==0)
   {
      Lsec();
   }
   if(move[1]==0 && move[2]==1)
   {
     Rsec();
   }
  delay(800);
     if(word[i]=='A' || word[i]=='a')
     {
         A();
         Serial.print("Called A");
     }
     if(word[i]=='B' || word[i]=='b')
     {
         B();
     }
     if(word[i]=='C' || word[i]=='c')
     {
         C();
     }
     if(word[i]=='D' || word[i]=='d')
     {
         D();
     }
     if(word[i]=='E' || word[i]=='e')
     {
         E();
         Serial.print("Called E");
     }
     if(word[i]=='F' || word[i]=='f')
     {
         Flet();
     }
     if(word[i]=='G' || word[i]=='g')
     {
         G();
     }
     if(word[i]=='H' || word[i]=='h')
     {
         H();
     }
     if(word[i]=='I' || word[i]=='i')
     {
         I();
     }
     if(word[i]=='J' || word[i]=='j')
     {
         J();
     }
     if(word[i]=='K' || word[i]=='k')
     {
         K();
     }
     if(word[i]=='L' || word[i]=='l')
     {
         L();
         Serial.print("Called L");
     }
     if(word[i]=='M' || word[i]=='m')
     {
         M();
     }
     if(word[i]=='N' || word[i]=='n')
     {
         N();
     }
     if(word[i]=='O' || word[i]=='o')
     {
         O();
     }
     if(word[i]=='P' || word[i]=='p')
     {
         P();
         Serial.print("Called P");
     }
     if(word[i]=='Q' || word[i]=='q')
     {
         Q();
     }
     if(word[i]=='R' || word[i]=='r')
     {
         R();
     }
     if(word[i]=='S' || word[i]=='s')
     {
         S();
     }
     if(word[i]=='T' || word[i]=='t')
     {
         T();
     }
     if(word[i]=='U' || word[i]=='u')
     {
         U();
     }
     if(word[i]=='V' || word[i]=='v')
     {
         V();
     }
     if(word[i]=='W' || word[i]=='w')
     {
         W();
     }
     if(word[i]=='X' || word[i]=='x')
     {
         X();
     }
     if(word[i]=='Y' || word[i]=='y')
     {
         Y();
     }
     if(word[i]=='Z' || word[i]=='z')
     {
         Z();
     }
     byte btn = digitalRead(button);
     if(btn == LOW)
     {
      Serial.print("button pressed");
        i++;
     }
}

//Alphabet functionw
void A(){
  s1.write(40);
  s2.write(0);
  s3.write(0);
  s4.write(180);
  s5.write(180);
  s6.write(180);
}

void Asec(){
  d1.write(40);
  d2.write(0);
  d3.write(0);
  d4.write(180);
  d5.write(180);
  d6.write(180);
}

void B(){
  s1.write(40);
  s2.write(40);
  s3.write(0);
  s4.write(180);
  s5.write(180);
  s6.write(180);
}

void Bsec(){
  d1.write(40);
  d2.write(40);
  d3.write(0);
  d4.write(180);
  d5.write(180);
  d6.write(180);
}

void C(){
  s1.write(90);
  s2.write(0);
  s3.write(0);
  s4.write(180-40);
  s5.write(180);
  s6.write(180);
}

void Csec(){
  d1.write(90);
  d2.write(0);
  d3.write(0);
  d4.write(180-40);
  d5.write(180);
  d6.write(180);
}

void D(){
  s1.write(40);
  s2.write(0);
  s3.write(0);
  s4.write(180-40);
  s5.write(180-40);
  s6.write(180);
}

void Dsec(){
  d1.write(40);
  d2.write(0);
  d3.write(0);
  d4.write(180-40);
  d5.write(180-40);
  d6.write(180);
}

void E(){
  s1.write(40);
  s2.write(0);
  s3.write(0);
  s4.write(180);
  s5.write(180-40);
  s6.write(180);
}

void Esec(){
  d1.write(40);
  d2.write(0);
  d3.write(0);
  d4.write(180);
  d5.write(180-40);
  d6.write(180);
}

void Flet(){
  s1.write(40);
  s2.write(40);
  s3.write(0);
  s4.write(180-40);
  s5.write(180);
  s6.write(180);
}

void Fsec(){
  d1.write(40);
  d2.write(40);
  d3.write(0);
  d4.write(180-40);
  d5.write(180);
  d6.write(180);
}

void G(){
  s1.write(40);
  s2.write(40);
  s3.write(0);
  s4.write(180-40);
  s5.write(180-40);
  s6.write(180);
}

void Gsec(){
  d1.write(40);
  d2.write(40);
  d3.write(0);
  d4.write(180-40);
  d5.write(180-40);
  d6.write(180);
}

void H(){
  s1.write(40);
  s2.write(40);
  s3.write(0);
  s4.write(180);
  s5.write(180-40);
  s6.write(180);
}

void Hsec(){
  d1.write(40);
  d2.write(40);
  d3.write(0);
  d4.write(180);
  d5.write(180-40);
  d6.write(180);
}

void I(){
  s1.write(0);
  s2.write(40);
  s3.write(40);
  s4.write(180-40);
  s5.write(180);
  s6.write(180);
}

void Isec(){
  d1.write(0);
  d2.write(40);
  d3.write(40);
  d4.write(180-40);
  d5.write(180);
  d6.write(180);
}

void J(){
  s1.write(0);
  s2.write(40);
  s3.write(0);
  s4.write(180-40);
  s5.write(180-40);
  s6.write(180);
}

void Jsec(){
  d1.write(0);
  d2.write(40);
  d3.write(0);
  d4.write(180-40);
  d5.write(180-40);
  d6.write(180);
}

void K(){
  s1.write(40);
  s2.write(0);
  s3.write(40);
  s4.write(180);
  s5.write(180);
  s6.write(180);
}

void Ksec(){
  d1.write(40);
  d2.write(0);
  d3.write(40);
  d4.write(180);
  d5.write(180);
  d6.write(180);
}

void L(){
  s1.write(40);
  s2.write(40);
  s3.write(40);
  s4.write(180);
  s5.write(180);
  s6.write(180);
}

void Lsec(){
  d1.write(40);
  d2.write(40);
  d3.write(40);
  d4.write(180);
  d5.write(180);
  d6.write(180);
}

void M(){
  s1.write(40);
  s2.write(0);
  s3.write(40);
  s4.write(180-40);
  s5.write(180);
  s6.write(180);
}

void Msec(){
  d1.write(40);
  d2.write(0);
  d3.write(40);
  d4.write(180-40);
  d5.write(180);
  d6.write(180);
}

void N(){
  s1.write(40);
  s2.write(0);
  s3.write(40);
  s4.write(180-40);
  s5.write(180-40);
  s6.write(180);
}

void Nsec(){
  d1.write(40);
  d2.write(0);
  d3.write(40);
  d4.write(180-40);
  d5.write(180-40);
  d6.write(180);
}

void O(){
  s1.write(40);
  s2.write(0);
  s3.write(40);
  s4.write(180);
  s5.write(180-40);
  s6.write(180);
}

void Osec(){
  d1.write(40);
  d2.write(0);
  d3.write(40);
  d4.write(180);
  d5.write(180-40);
  d6.write(180);
}

void P(){
  s1.write(40);
  s2.write(40);
  s3.write(40);
  s4.write(180-40);
  s5.write(180);
  s6.write(180);
}

void Psec(){
  d1.write(40);
  d2.write(40);
  d3.write(40);
  d4.write(180-40);
  d5.write(180);
  d6.write(180);
}

void Q(){
  s1.write(40);
  s2.write(40);
  s3.write(40);
  s4.write(180-40);
  s5.write(180-40);
  s6.write(180);
}

void Qsec(){
  d1.write(40);
  d2.write(40);
  d3.write(40);
  d4.write(180-40);
  d5.write(180-40);
  d6.write(180);
}

void R(){
  s1.write(40);
  s2.write(40);
  s3.write(40);
  s4.write(180);
  s5.write(180-40);
  s6.write(180);
}

void Rsec(){
  d1.write(40);
  d2.write(40);
  d3.write(40);
  d4.write(180);
  d5.write(180-40);
  d6.write(180);
}


void S(){
  s1.write(0);
  s2.write(40);
  s3.write(40);
  s4.write(180-40);
  s5.write(180);
  s6.write(180);
}

void Ssec(){
  d1.write(0);
  d2.write(40);
  d3.write(40);
  d4.write(180-40);
  d5.write(180);
  d6.write(180);
}

void T(){
  s1.write(0);
  s2.write(40);
  s3.write(40);
  s4.write(180-40);
  s5.write(180-40);
  s6.write(180);
}

void Tsec(){
  d1.write(0);
  d2.write(40);
  d3.write(40);
  d4.write(180-40);
  d5.write(180-40);
  d6.write(180);
}

void U(){
  s1.write(40);
  s2.write(0);
  s3.write(40);
  s4.write(180);
  s5.write(180);
  s6.write(180-40);
}

void Usec(){
  d1.write(40);
  d2.write(0);
  d3.write(40);
  d4.write(180);
  d5.write(180);
  d6.write(180-40);
}

void V(){
  s1.write(40);
  s2.write(40);
  s3.write(40);
  s4.write(180);
  s5.write(180);
  s6.write(180-40);
}

void Vsec(){
  d1.write(40);
  d2.write(40);
  d3.write(40);
  d4.write(180);
  d5.write(180);
  d6.write(180-40);
}

void W(){
  s1.write(0);
  s2.write(40);
  s3.write(0);
  s4.write(180-40);
  s5.write(180-40);
  s6.write(180-40);
}

void Wsec(){
  d1.write(0);
  d2.write(40);
  d3.write(0);
  d4.write(180-40);
  d5.write(180-40);
  d6.write(180-40);
}

void X(){
  s1.write(40);
  s2.write(0);
  s3.write(40);
  s4.write(180-40);
  s5.write(180);
  s6.write(180-40);
}

void Xsec(){
  d1.write(40);
  d2.write(0);
  d3.write(40);
  d4.write(180-40);
  d5.write(180);
  d6.write(180-40);
}

void Y(){
  s1.write(40);
  s2.write(0);
  s3.write(40);
  s4.write(180-40);
  s5.write(180-40);
  s6.write(180-40);
}

void Ysec(){
  d1.write(40);
  d2.write(0);
  d3.write(40);
  d4.write(180-40);
  d5.write(180-40);
  d6.write(180-40);
}

void Z(){
  s1.write(40);
  s2.write(0);
  s3.write(40);
  s4.write(180);
  s5.write(180-40);
  s6.write(180-40);
}

void Zsec(){
  d1.write(40);
  d2.write(0);
  d3.write(40);
  d4.write(180);
  d5.write(180-40);
  d6.write(180-40);
}
