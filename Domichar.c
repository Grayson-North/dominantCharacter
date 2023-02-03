//-----------------------------
// Grayson North
// COP3502
// Spring 2020
// gr967419
//-----------------------------
#include "Domichar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv)
{
  int i;
  for (i = 1; i < argc; i++)
  {
    printDomichar(argv[i]);
  }
  return 0;
}

void printDomichar(char *str)
{
  // variable initialization
  int n = strlen(str);
  int i;
  int vSum = 0;
  int cSum = 0;
  int nonSum = 0;
  double percent = 0;
  // stepping through characters of *str
  // checking for character type
  for (i = 0; i < n; i++)
  {
    // checking for non-alpha chars first so there's no need to
    // check if vowel or consonant.
    if ((isNonalphabetic(str[i])) == 1)
    {
      nonSum++;
    }
    // testing for consonants second
    // isConsonant calls isVowel in its function
    // so if below statement is false then the char must be a vowel
    else if ((isConsonant(str[i])) == 1)
    {
      cSum++;
    }
    else
    {
      vSum++;
    }
  }
  // checks if vSum is largest and finds the percentage of vowels in str
  if ((vSum > cSum) && (vSum > nonSum))
  {
    percent = (double) vSum / n;
    if (percent > 0.50)
    {
      printf("%s (m:v)\n", str);
    }
    else if (percent == 0.50)
    {
      printf("%s (p:v)\n", str);
    }
  }
  // checks if cSum is largest and finds the percentage of consonants in str
  else if ((cSum > vSum) && (cSum > nonSum))
  {
    percent = (double) cSum / n;
    if (percent > 0.50)
    {
      printf("%s (m:c)\n", str);
    }
    else if (percent == 0.50)
    {
      printf("%s (p:c)\n", str);
    }
  }
  // checks if nonSum is largest and finds the percentage of non alphas in str
  else if ((nonSum > vSum) && (nonSum > cSum))
  {
    percent = (double) nonSum / n;
    if (percent > 0.50)
    {
      printf("%s (m:~)\n", str);
    }
    else if (percent == 0.50)
    {
      printf("%s (p:~)\n", str);
    }
  }
  // checks if the sums are equal (a = b) && (b = c) therefore (a = c)
  else if ((vSum == cSum) && (cSum == nonSum))
  {
    printf("%s (vc~)\n", str);
  }
  // checks if vSum and cSum are equal and the majority
  else if ((vSum == cSum) && (vSum > nonSum) && (cSum > nonSum))
  {
    printf("%s (vc)\n", str);
  }
  // checks if vSum and nonSum are equal and the majority
  else if ((vSum == nonSum) && (vSum > cSum) && (nonSum > cSum))
  {
    printf("%s (v~)\n", str);
  }
  // checks if cSum and nonSum are equal and the majority
  else if ((cSum == nonSum) && (cSum > vSum) && (nonSum > vSum))
  {
    printf("%s (c~)\n", str);
  }
}


int isVowel(char c)
{
  // i force the value of letter to lowercase so I don't need to check for uppercase values :P
  char letter = tolower(c);
  // long logical or statement
  if ((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u'))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isConsonant(char c)
{
  // by calling isVowel and isNonalphabetic this function only returns 1
  // if char c is not a vowel or a non alpha character
  if (((isNonalphabetic(c)) == 0) && ((isVowel(c)) == 0))
  {
      return 1;
  }
  else
  {
      return 0;
  }
}

int isNonalphabetic(char c)
{
  // checks to see if charc is a non-Alpha (thank you ctype)
  if ((isalpha(c)) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

double difficultyRating(void)
{
  return 2.0;
}

double hoursSpent(void)
{
  return 5.5;
}
