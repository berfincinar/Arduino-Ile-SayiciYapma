int digit[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b11111111, 0b1101111}; 

int buton1 = A0;
int buton2 = A1;
int buton3 = A2;
int potdeger = 0;
int sonpotdeger = 0;
int anahtar = 2;

int i=0;
int sure;
int podPin1= A3;
int podDeger2;

void setup() {
  //Serial.begin(9600); 
  		
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  
   for(int i=0; i<14; i++){
  	pinMode(i,OUTPUT);
  }
  yaz(0);
}

void loop() {
 
  podDeger2=analogRead(podPin1);
  sure=map(podDeger2,1,123,10,100);
  
potdeger = analogRead(A4);

if(digitalRead(buton1) == HIGH) {anahtar = 0;}
if(digitalRead(buton2) == HIGH) {anahtar = 1;}
if(digitalRead(buton3) == HIGH) {anahtar = 2;}
if(potdeger != sonpotdeger && potdeger<sonpotdeger) {anahtar = 3;}
else if(potdeger != sonpotdeger && potdeger>sonpotdeger) {anahtar = 4;}


  switch (anahtar) {
    
    case 0:    // your hand is on the sensor
      Serial.println("ileri");
     if (i>=99){      
      i=0;
    }else{        
      i=i+1;       
    }
    
    yaz(i);
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("geri");
     if (i==0){ 
      i=99;
    }else{  
      i=i-1;     
    }
    
    yaz(i);   
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("dur");
      break;
    case 3:    // your hand is nowhere near the sensor
      Serial.println("potla ileri");
     if (i>=99){      
      i=0;
    }else{        
      i=i+1;       
    }
    
    yaz(i);
      break;
    case 4:    // your hand is nowhere near the sensor
      Serial.println("potla geri");
     if (i==0){ 
      i=99;
    }else{  
      i=i-1;     
    }
    
    yaz(i);   
      break;
  }

sonpotdeger = potdeger;

}



void yaz(int i){
  int a,b;
  
  a=i/10;//Sayacağımız sayının onlar basamağı    
  b=i%10;//Sayacağımız sayının birler basamağı
  
  birler(b);  // b degeri birler fonksıyonuna gonderılıyor
  onlar(a);   //a degeri onlar fonksıyonuna gonderılıyor
  
  delay(sure);
}
           

void birler(int sayi){ //bırler fonksiyonunda 0-7 bacaklarının baglı oldugu 7 segment displayin ledleri aldığı degere gore yanıyor
  for (int i = 0,b=0; i <7; i++,b++){ 
       digitalWrite(i, bitRead(digit[sayi], b));
  }
}
void onlar(int sayi){ //onlar fonksiyonunda 8-13 bacaklarının baglı oldugu 7 segment displayin ledleri aldığı degere gore yanıyor
      for (int i = 7,b=0; i <14; i++,b++) { 
          digitalWrite(i, bitRead(digit[sayi], b));
  }
}