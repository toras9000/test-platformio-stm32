#include <Arduino.h>
#include <ArduinoJson.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("Test ArduinoJson.\n");

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

  delay(2000);
}
