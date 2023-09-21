#define BLYNK_TEMPLATE_ID "TMPL681qmnNCV"
#define BLYNK_TEMPLATE_NAME "test"
#define BLYNK_AUTH_TOKEN "Z_2Bo9AEz_m-YtiubPuBEAh19g4oE2bg"
#define RELAY_PIN D1
#define POMPA_ON LOW

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "Z_2Bo9AEz_m-YtiubPuBEAh19g4oE2bg";
char ssid[] = "@WifiPPL";
char pass[] = "PPLsij@23";

void setup()
{
    Blynk.begin(auth, ssid, pass);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, POMPA_ON); // Matikan pompa saat boot
}

BLYNK_WRITE(V1) { // Widget Blynk yang digunakan untuk mengontrol pompa
    int nilaiTombol = param.asInt();
    if (nilaiTombol == 1) { // Jika tombol diaktifkan di aplikasi Blynk
        digitalWrite(RELAY_PIN, !POMPA_ON); // Aktifkan pompa
    } 
}

void loop()
{
    Blynk.run();
}