#include <Arduino.h>
#include <ModbusRTUSlave.h>

// put function declarations here:
#define MODBUS_SERIAL Serial
#define MODBUS_BAUD 9600
#define MODBUS_CONFIG SERIAL_8N1
#define MODBUS_UNIT_ID 1
ModbusRTUSlave modbus(MODBUS_SERIAL);
const uint8_t numCoils = 4;
bool coils[numCoils];
const int8_t relaysPins[numCoils] = {2, 5, 11, 13};
void setup()
{
  // put your setup code here, to run once:
  pinMode(relaysPins[0], OUTPUT);
  pinMode(relaysPins[1], OUTPUT);
  pinMode(relaysPins[2], OUTPUT);
  pinMode(relaysPins[3], OUTPUT);

  modbus.configureCoils(coils, numCoils);
  MODBUS_SERIAL.begin(MODBUS_BAUD, MODBUS_CONFIG);
  modbus.begin(MODBUS_UNIT_ID, MODBUS_BAUD, MODBUS_CONFIG);
}

void loop()
{
  // put your main code here, to run repeatedly:
  modbus.poll();
  digitalWrite(relaysPins[0], coils[0]);
  digitalWrite(relaysPins[1], coils[1]);
  digitalWrite(relaysPins[2], coils[2]);
  digitalWrite(relaysPins[3], coils[3]);
}
