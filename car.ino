#include <VirtualWire.h>
// Incluimos esta biblioteca para los módulos de RF

void setup()

{ //Configuración básicaf
  
  Serial.begin(9600);


    vw_set_ptt_inverted(true);
    vw_set_rx_pin(13); // Pin para el receptor
    vw_setup(4000);  // Bits por segundo
    pinMode(3, OUTPUT); // 
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

    vw_rx_start();       // Start the receiver PLL running
}
    void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

 
    if (vw_get_message(buf, &buflen)) 

    {  
            
    // Cuando recibe la señal '0'
    // los motores permañnecen parados
    if(buf[0]=='0'){
    digitalWrite(3,0);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(9,0);
    }
    // Cuando recibe la señal 'A'
    // los motores avanzan
    
    if(buf[0]=='A'){
    digitalWrite(3,1);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(9,1);

    }
    // Cuando recibe la señal '3'
    // los motores avanzan 75ms y se paran 25ms repetidamente
    // Velocidad mas lenta
        
  if(buf[0]=='3'){
  digitalWrite(3,1);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,1);
  delay(75);  
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,0);
  delay(25);   

    }
    // Cuando recibe la señal '2'
    // los motores avanzan 50ms y se paran 50ms repetidamente
    // Velocidad mas lenta
    
    if(buf[0]=='2'){
  digitalWrite(3,1);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,1);
  delay(50);  
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,0);
  delay(50); 

    }
    // Cuando recibe la señal '1'
    // los motores avanzan 25ms y se paran 75ms repetidamente
    // Velocidad mas lenta
    
    if(buf[0]=='1'){
  digitalWrite(3,1);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,1);
  delay(25);  
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,0);
  delay(75); 

    }   
    // Cuando recibe la señal 'B'
    // los motores avanzan 50ms y solo uno paran 50 ms repetidamente
    // Giro
    
    if(buf[0]=='B'){
  digitalWrite(3,1);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,1);
  delay(50);  
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,1);
  delay(50); 
 
    }
    // Cuando recibe la señal 'C'
    // un motor avanzan 50ms y se paran 50ms repetidamente
    // Giro   
    if(buf[0]=='C'){
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,1);
  delay(50);  
  digitalWrite(3,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(9,0);
  delay(50); 
 
    }
    // Cuando recibe la señal 'D'
    // un motor avanzan 50ms y se paran 50ms repetidamente
    // Giro   
   if(buf[0]=='D'){
  digitalWrite(3,0);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(9,0);
  delay(50);  
  digitalWrite(3,0);
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(9,0);
  delay(50); 
 
    }
    // Cuando recibe la señal 'E'
    // los motores retroceden 50ms y se paran 50ms repetidamente
    // Retroceso lento
       if(buf[0]=='E'){
  digitalWrite(3,0);
  digitalWrite(5,1);
  digitalWrite(6,1);
digitalWrite(9,0);
delay(50);  
 digitalWrite(3,0);
digitalWrite(5,0);
digitalWrite(6,0);
digitalWrite(9,0);
 delay(50); 
 
    }
    // Cuando recibe la señal 'F'
    // Giro  
 if(buf[0]=='F'){
digitalWrite(3,0);
digitalWrite(5,1);
digitalWrite(6,1);
digitalWrite(9,0);
delay(50);  
 digitalWrite(3,0);
digitalWrite(5,0);
digitalWrite(6,1);
digitalWrite(9,0);
 delay(50); 
 
    }
    // Cuando recibe la señal 'G'
    // Giro      
 if(buf[0]=='G'){
digitalWrite(3,1);
digitalWrite(5,0);
digitalWrite(6,0);
digitalWrite(9,0);
delay(50);  
 digitalWrite(3,0);
digitalWrite(5,0);
digitalWrite(6,0);
digitalWrite(9,0);
 delay(50); 
 
    }
    // Cuando recibe la señal 'H'
    // Giro  
 if(buf[0]=='H'){
digitalWrite(3,1);
digitalWrite(5,0);
digitalWrite(6,0);
digitalWrite(9,1);
delay(50);  
 digitalWrite(3,1);
digitalWrite(5,0);
digitalWrite(6,0);
digitalWrite(9,0);
 delay(50); 
 
    }

if(buf[0]=='L'){
digitalWrite(10,1);
digitalWrite(11,1);
digitalWrite(12,1);
delay(50);
digitalWrite(10,0);
digitalWrite(11,0);
digitalWrite(12,0);
 delay(50);    
    }

delay(50);   
    }
}
