#include<Servo.h>
#define ACTIVATED LOW
Servo s1,s2,s3,s4,s5,s6;
String receivedString;
bool counterStart;
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

void loop() {
  // put your main code here, to run repeatedly:
  receieveData();
  String word = receivedString;

  
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
  s1.write(90);
  s2.write(0);
  s3.write(0);
  s4.write(0);
  s5.write(0);
  s6.write(0);
}

void B(){
  s1.write(90);
  s2.write(90);
  s3.write(0);
  s4.write(0);
  s5.write(0);
  s6.write(0);
}

void C(){
  s1.write(90);
  s2.write(0);
  s3.write(0);
  s4.write(90);
  s5.write(0);
  s6.write(0);
}

void D(){
  s1.write(90);
  s2.write(0);
  s3.write(0);
  s4.write(90);
  s5.write(90);
  s6.write(0);
}

void E(){
  s1.write(90);
  s2.write(0);
  s3.write(0);
  s4.write(0);
  s5.write(90);
  s6.write(0);
}

void Flet(){
  s1.write(90);
  s2.write(90);
  s3.write(0);
  s4.write(90);
  s5.write(0);
  s6.write(0);
}

void G(){
  s1.write(90);
  s2.write(90);
  s3.write(0);
  s4.write(90);
  s5.write(90);
  s6.write(0);
}

void H(){
  s1.write(90);
  s2.write(90);
  s3.write(0);
  s4.write(0);
  s5.write(90);
  s6.write(0);
}

void I(){
  s1.write(0);
  s2.write(90);
  s3.write(0);
  s4.write(90);
  s5.write(0);
  s6.write(0);
}

void J(){
  s1.write(0);
  s2.write(90);
  s3.write(0);
  s4.write(90);
  s5.write(90);
  s6.write(0);
}

void K(){
  s1.write(90);
  s2.write(0);
  s3.write(90);
  s4.write(0);
  s5.write(0);
  s6.write(0);
}

void L(){
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(0);
  s5.write(0);
  s6.write(0);
}

void M(){
  s1.write(90);
  s2.write(0);
  s3.write(90);
  s4.write(90);
  s5.write(0);
  s6.write(0);
}

void N(){
  s1.write(90);
  s2.write(0);
  s3.write(90);
  s4.write(90);
  s5.write(90);
  s6.write(0);
}

void O(){
  s1.write(90);
  s2.write(0);
  s3.write(90);
  s4.write(0);
  s5.write(90);
  s6.write(0);
}

void P(){
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
  s5.write(0);
  s6.write(0);
}

void Q(){
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
  s5.write(90);
  s6.write(0);
}

void R(){
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(0);
  s5.write(90);
  s6.write(0);
}

void S(){
  s1.write(0);
  s2.write(90);
  s3.write(90);
  s4.write(90);
  s5.write(0);
  s6.write(0);
}

void T(){
  s1.write(0);
  s2.write(90);
  s3.write(90);
  s4.write(90);
  s5.write(90);
  s6.write(0);
}

void U(){
  s1.write(90);
  s2.write(0);
  s3.write(90);
  s4.write(0);
  s5.write(0);
  s6.write(90);
}

void V(){
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(0);
  s5.write(0);
  s6.write(90);
}

void W(){
  s1.write(0);
  s2.write(90);
  s3.write(0);
  s4.write(90);
  s5.write(90);
  s6.write(90);
}

void X(){
  s1.write(90);
  s2.write(0);
  s3.write(90);
  s4.write(90);
  s5.write(0);
  s6.write(90);
}

void Y(){
  s1.write(90);
  s2.write(0);
  s3.write(90);
  s4.write(90);
  s5.write(90);
  s6.write(90);
}

void Z(){
  s1.write(90);
  s2.write(0);
  s3.write(90);
  s4.write(0);
  s5.write(90);
  s6.write(90);
}
