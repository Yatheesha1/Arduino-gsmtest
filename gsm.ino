//#include <AltSoftSerial.h>

#include <SoftwareSerial.h>

String pilih;

 //AltSoftSerial mySerial;//(Rx,Tx)
 
 SoftwareSerial mySerial(9,10);
 String num="+919496282711";

void setup()

{

mySerial.begin(9600); // Setting the baud rate of GSM Module

Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)

RecieveMessage();

delay(100);

}

void loop()

{

if (Serial.available()>0)

switch(Serial.read())

{

case 's':

SendMessage();

break;

case 'r':

RecieveMessage();

break;

}

if (mySerial.available()>0)

{ 
  Serial.println(mySerial.readString());

  pilih = mySerial.read();}

}

void SendMessage()

{

mySerial.println("AT+CMGF=1\r\n"); //Sets the GSM Module in Text Mode

delay(1000); // Delay of 1000 milli seconds or 1 second

mySerial.println("AT+CMGS=\"+919496282711\"\r\n"); // Replace x with mobile number

delay(1000);

mySerial.println("Message Send :)");// The SMS text you want to send

mySerial.println(pilih);

delay(100);

mySerial.println((char)26);// ASCII code of CTRL+Z

delay(1000);

}

void RecieveMessage()

{

mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS

delay(1000);

//There are different AT commands for different tasks. If you want to read

//all SMS’s stored in your SIM card, send the following AT Command

//to gsm module – “AT+CMGL=\”ALL\”\r”

}

