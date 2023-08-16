#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C l1(0x27, 4, 20);

byte customChar[] = {
  B00010,
  B00110,
  B01110,
  B11110,
  B11110,
  B01110,
  B00110,
  B00010
};
byte customChar1[] = {
  B00000,
  B00110,
  B01111,
  B01110,
  B00100,
  B00100,
  B01100,
  B00100
};
int m,n,x,y,X,Y,h,c,i=400;
byte z=0,k,b,counter=0;
int v=19;
void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  l1.init();
  l1.backlight();
  l1.createChar(0, customChar);
l1.createChar(1, customChar1);
l1.clear();
l1.home();
l1.write(1);
randomSeed(0);
l1.setCursor(19,h);
l1.write(0);
Serial.begin(9600);


}

void loop() { 
x=analogRead(A1);
y=analogRead(A0);
X=map(x,0,1023,1,-1);
Y=map(y,0,1023,1,-1);
if (i%6==1){
h=random(4);
}
//1.rightToLeft();

l1.setCursor(v,h);
l1.write(0);
l1.setCursor(v+1,h);
l1.print(" ");
delay(100);

if(X) 
{if(X==1){m++; l1.setCursor(m-1,n); l1.print(" "); l1.setCursor(m,n);  l1.write(1); delay(500); if(m>=19) m=19; }
 else if  (X==-1){m--;  l1.setCursor(m+1,n); l1.print(" "); l1.setCursor(m,n);  l1.write(1); delay(500); if(m<=0) m=0;}
}
if(Y) 
{if(Y==1){n++; l1.setCursor(m,n-1); l1.print(" "); l1.setCursor(m,n);  l1.write(1); delay(500); if(n>=3) n=3;}
 else if  (Y==-1){n--;  l1.setCursor(m,n+1); l1.print(" "); l1.setCursor(m,n);  l1.write(1); delay(500);if(n<=0) n=0; }
}
i++;
v=v-1;
delay(100);
//Serial.println(v);
if (v==1)
{ 
  
l1.setCursor(v,h);

b=h;

l1.write(0);
z=1;

}
if(z){
if(m==1&&n==b)
{
  counter=counter+1;
  Serial.println(counter);
delay(100); 
z=0;}

}
  if( m==v&&n==h )
{
 counter =0;
Serial.println("Game over");}

if(!v) v=19;
}
