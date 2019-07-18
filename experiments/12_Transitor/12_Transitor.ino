//transitor y Relay
const int transitor = 9;
char state = '0';

void setup()

{
    pinMode(transitor, OUTPUT);
    Serial.begin(9600);
}
void loop()
{
    // digitalWrite(transitor, HIGH);
    // delay(2000);
    // digitalWrite(transitor, LOW);
    // delay(2000);
    // for (int i = 0; i < 255; i++)
    // {
    //     analogWrite(transitor, i);
    //     delay(15);
    // }
    state =  Serial.read();
    if (state == '1')
    {
        digitalWrite(transitor, HIGH);
    }
    else
    {
        digitalWrite(transitor, LOW);
    }
    Serial.print(state);  
    delay(250);  
}