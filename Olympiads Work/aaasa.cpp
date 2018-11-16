#include <Arduino.h>

const int out[6] = {3,4,5,6,7,8};

long interval = 250;
long prevMS = 0;

int Counter = 0

void setup(){
    Serial.begin (9600);
    pinMode(2, INPUT);

    for(int i = 0; i < 6; i++){
        pinMode(out[i], OUTPUT);
    }
}

void loop(){
    unsigned long long curMS = millis();
    input = digitalRead(2)

    digitalWrite(out[Counter], HIGH);

        if(curMS - prevMS > interval){
              prevMS = curMS;
            Counter++;
            if (Counter > 5){
                Counter = 0
            }
        }
}
