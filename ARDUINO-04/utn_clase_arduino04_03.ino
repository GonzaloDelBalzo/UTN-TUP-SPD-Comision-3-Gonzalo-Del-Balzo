// Variables de Luz 
int Led1_Pin = 3; 
int Led2_Pin = 5; 
int Fot_Pin = A0; 
int Int_Pin = 2; 
int sensorValue = 0; 
int inputValue = 0;

// Variables de Temperatura
int readValue = 0; 
int lastValue = 1; 
int tempPin = A1; 
float voltsValue; 
float tempValue; 
int counter = 0; 
int start = 0; 
int stop = 0; 

// Limites Invierno 
int start1 = 18; 
int stop1 = 24; 

// Limites Verano 
int start2 = 20; 
int stop2 = 1; 

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(Led1_Pin, OUTPUT); 
  pinMode(Int_Pin, INPUT); 
  pinMode(Led2_Pin, OUTPUT); 
}
void loop() 
{ 
  // Lectura Digital 
  inputValue = digitalRead(Int_Pin);
  if (inputValue == HIGH) 
  { 
    Serial.println("Led: Encendido"); 
    digitalWrite(Led1_Pin, 1); 
    digitalWrite(Led2_Pin, 1);
  } 
  else 
  { 
    // Lectura Temperatura 
    readValue = analogRead(tempPin);
    lastValue = readValue; 
    voltsValue = 5.0 / 1024 * readValue;
    tempValue = voltsValue * 100 - 50; 
    
    if( tempValue < 20 )
    { 
      start = start1; 
      stop = stop1; 
      
    } 
    else 
    { 
      start = start2; 
      stop = stop2; 
    } 
    // // Lectura Luz
    if(counter >= start)
    { 
      // Lectura Analógica 
      sensorValue = analogRead(Fot_Pin); 
      if(sensorValue < 500) 
      { 
        Serial.println("Led: Encendido");
        digitalWrite(Led1_Pin, 1); 
        digitalWrite(Led2_Pin, 0);
      } 
      else 
      { 
       Serial.println("Led: Apagado");
       digitalWrite(Led1_Pin, 0);
       digitalWrite(Led2_Pin, 1);
      } 
    } 
    else 
    { 
      Serial.println("Led: Apagado");
      digitalWrite(Led1_Pin, 0); 
      digitalWrite(Led2_Pin, 0);
    } 
  } 
  counter++;
  Serial.print("Hora: "); 
  Serial.println(counter); 
  if (counter == 24) 
  { 
    counter =0; 
  } 
  delay(1000); 
}