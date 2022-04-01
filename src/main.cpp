#include <Arduino.h>
#include "NeuralNetwork.h"
#include <cmath>

NeuralNetwork *nn;

void setup()
{
  Serial.begin(115200);
  nn = new NeuralNetwork();
}

void loop()
{
  float number = random(314) / 100.0;
  nn->getInputBuffer()[0] = number;
  
  float result = nn->predict();
  const float exp = sin(number);
  Serial.printf("Number: %.2f, Expected %.2f, Predicted %.2f\n", number, exp, result);

  delay(1000);
}