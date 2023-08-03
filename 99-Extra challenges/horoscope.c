#include <stdio.h>
#include<stdbool.h>
#define HOROSCOPE_LENGTH 12

typedef struct Date 
{
  int month;
  int day;
} date;

typedef struct Horoscope 
{
  char name[50];
  date min;
  date max;
} horoscope;

const int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const horoscope Horoscopes[HOROSCOPE_LENGTH] = {
  {"Aries", {3,21}, {4,19}}, // Aries	21 de marzo	19 de abril
  {"Tauro", {4, 20}, {5, 20}}, // Tauro	20 de abril	20 de mayo
  {"Geminis", {5, 21}, {6, 20}}, // Géminis	21 de mayo	20 de junio
  {"Cancer", {6, 21}, {7, 22}}, // Cáncer	21 de junio	22 de julio
  {"Leo", {7,23}, {8, 22}}, // Leo	23 de julio	22 de agosto
  {"Virgo", {8, 23}, {9, 22}}, // Virgo	23 de agosto	22 de septiembre
  {"Libra", {9, 23}, {10, 22}},// Libra	23 de septiembre	22 de octubre
  {"Escorpio", {10, 23}, {11, 21}}, // Escorpio	23 de octubre	21 de noviembre
  {"Sagitario", {11, 22}, {12, 21}}, // Sagitario	22 de noviembre	21 de diciembre
  {"Capricornio", {12, 22}, {1, 19}}, // Capricornio	22 de diciembre	19 de enero
  {"Acuario", {1, 20}, {2, 18}}, // Acuario	20 de enero	18 de febrero
  {"Piscis", {2, 19}, {3, 20}}, // Piscis	19 de febrero	20 de marzo  
};

horoscope searchHoroscope(int month, int day);
bool isDateValid(int month, int day);

int main(void)
{
  int monthInput;
  int dayInput;
  bool isValid;

  do {
    printf("Ingrese su mes de nacimiento (1 - 12): ");
    scanf("%i", &monthInput);
    if(monthInput < 1 || monthInput > 12) printf("El mes ingresado es incorrecto.\n");
  } while(!(monthInput >= 1) || !(monthInput <= 12));

  do {
    printf("Ingrese su día de nacimiento (1 - 31): ");
    scanf("%i", &dayInput);
    isValid = isDateValid(monthInput, dayInput);
    if(dayInput < 1 || dayInput > 31 || !isValid) printf("El día ingresado es incorrecto.\n");
  } while(!(dayInput >= 1) || !(dayInput <= 31) || !isValid);
  
  horoscope selectedHoroscope = searchHoroscope(monthInput, dayInput);
  printf("Su horoscopo es %s\n", selectedHoroscope.name);

  return 0;
}

bool isDateValid(int month, int day)
{
  return (daysInMonth[month - 1] >= day);
}

horoscope searchHoroscope(int month, int day)
{
  for (int i = 0; i < HOROSCOPE_LENGTH; i++)
  {
    if(month != Horoscopes[i].min.month && month != Horoscopes[i].max.month) continue;
    if(month == Horoscopes[i].min.month && day >= Horoscopes[i].min.day) return Horoscopes[i];
    if(month == Horoscopes[i].max.month && day <= Horoscopes[i].max.day) return Horoscopes[i];
  }
  horoscope nullHoroscope = {"", {0, 0}, {0, 0}};
  return nullHoroscope;