#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Emprendedores";
const char* password = "AxtVvm13";


void connectToNetwork() 
{
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Tratando de establecer conexión...");
    }
    Serial.println("Conexión establecida :D");
}


void setup()
{
    Serial.begin(115200);
    delay(1000);
    //WiFi.begin(ssid,password) ;  Procedimiento de conexión
    connectToNetwork();  
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;
        http.begin("https://iot-course-a2bfd.firebaseio.com/data");
        //http.addHeader("Content-Type", "text/plain");
        int httpCode = http.GET();

        if (httpCode >=200 && httpCode <206)
        {
            String payload = http.getString();
            Serial.println(httpCode);
            Serial.println(payload);
        }
        else
        {
            Serial.println(httpCode);
            Serial.println("Error en la petición");
        }
        
        http.end();
    }
    delay(10000);
}

