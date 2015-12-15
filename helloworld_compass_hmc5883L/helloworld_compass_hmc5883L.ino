#include <Wire.h>
#include <HMC5883L.h>
 
HMC5883L compass;
 
int previousDegree;
 
void setup()
{
  Serial.begin(115200);
 
  // Initialize HMC5883L
  Serial.println();
  Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    Serial.println ("not found HMC5883L, check the connection");
    delay(500);
  }
 
  // Set the measuring range
  compass.setRange(HMC5883L_RANGE_1_3GA);
 
  // Set the mode of operation
  compass.setMeasurementMode(HMC5883L_CONTINOUS);
 
  // Set the frequency of measurements
  compass.setDataRate(HMC5883L_DATARATE_15HZ);
 
  // Liczba usrednionych probek
  compass.setSamples(HMC5883L_SAMPLES_4);
}
 
void loop()
{
  // Get the normalized vectors
  Vector norm = compass.readNormalize();
 
  // Calculate the (councils)
  float heading = atan2(norm.YAxis, norm.XAxis);
 
  // Set the angle of declination for Bytom 4'26E (positive)
  // Formula: (you + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (-10.0 + (49.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;
 
  // The correction of angles
  if (heading < 0)
  {
    heading += 2 * PI;
  }
 
  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }
 
  // Conversion of radians to degrees
  float headingDegrees = heading * 180/M_PI;
 
  // Output
  Serial.print(" Heading = ");
  Serial.print(heading);
  Serial.print ( "Degress =" ) ;
  Serial.print(headingDegrees);
  Serial.println ( ) ;
 
 
  delay(100);
}
