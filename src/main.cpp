#include <Arduino.h>
#include <ArduinoJson.h>
#include <Base64.h>
#include <Base64.hpp>
#include <arduino_base64.hpp>

void setup()
{
  Serial.begin(115200);
  Serial.println("Test Library.\n");

  static const char *jsonText =
      "{"
      "   \"propInteger\": 100,"
      "   \"propFloat\": 2.345,"
      "   \"propString\": \"abcd\","
      "   \"propStrNum\": \"999\""
      "}";

  auto doc = DynamicJsonDocument(1024);
  auto error = deserializeJson(doc, jsonText);

  if (error)
  {
    Serial.println("Parse error");
  }
  else
  {
    Serial.println("Parse success");
    int valInt = doc["propInteger"];
    float valFloat = doc["propFloat"];
    const char *valStr = doc["propString"];
    const char *valStrNum = doc["propStrNum"];
    int valStrNumInt = doc["propStrNum"];
    int valStrNumStr = doc["propString"];

    auto autoInt = doc["propInteger"];
    auto autoFloat = doc["propFloat"];
    auto autoStr = doc["propString"];
    auto autoStrNum = doc["propStrNum"];

    auto asInt = doc["propInteger"].as<int>();
    auto asFloat = doc["propFloat"].as<float>();
    auto asStr = doc["propString"].as<const char *>();
    auto asStrNum = doc["propStrNum"].as<const char *>();

    int i = 0;
  }
}

void loop()
{
  static int counter = 0;

  Serial.println("Serialize Test");
  auto doc = DynamicJsonDocument(1024);
  doc["name"] = "counter";
  doc["count"] = counter++;

  std::string json;
  auto size = serializeJson(doc, json);
  Serial.println(json.c_str());

  Serial.println("Base64 Test");

  static bool init = false;
  static uint8_t source[1024];
  static char buff[sizeof(source) * 2];

  if (!init)
  {
    for (auto i = 0; i < sizeof(source); i++)
    {
      source[i] = (uint8_t)i;
    }
  }

  uint32_t time1, time2, time3;
  {
    uint32_t begin = micros();
    auto len = Base64.encode(buff, (char *)source, sizeof(source));
    Serial.printf("Base64(1): %s\n", buff);
    time1 = micros() - begin;
  }
  {
    uint32_t begin = micros();
    auto len = encode_base64(source, sizeof(source), (uint8_t *)buff);
    Serial.printf("Base64(2): %s\n", buff);
    time2 = micros() - begin;
  }
  {
    uint32_t begin = micros();
    base64::encode(source, sizeof(source), buff);
    Serial.printf("Base64(3): %s\n", buff);
    time3 = micros() - begin;
  }
  Serial.printf("Time1: %u\n", time1);
  Serial.printf("Time2: %u\n", time2);
  Serial.printf("Time3: %u\n", time3);

  void sub_loop();
  sub_loop();

  delay(2000);
}
