#include "checkStrings.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void trim(char dest[], const char scr[])
{
   const char *pWSleading = scr;
   const char *pWStrailing = scr + strlen(scr) - 1;
   int i = 0;

   while (isspace(*pWSleading))
   {
      pWSleading++;
   }
   while (isspace(*pWStrailing) && (pWStrailing >= scr))
   {
      pWStrailing--;
   }
   while (pWSleading <= pWStrailing)
   {
      dest[i++] = *pWSleading++;
   }
   dest[i] = '\0';
}

/* Only checks integers without + or - sign */
bool isInteger(const char str[])
{
   bool isOK = true;
   size_t i = 0;

   for(i = 0; i < strlen(str); i++)
   {
      if (!isdigit(str[i]))
      {
         isOK = false;
         break;
      }
   }
   return isOK;
}

bool isMACaddress(const char str[])
{
   if (strlen(str) != 17) {
      return false;
   }
   int s;
   int nOK = sscanf(str, "%02x:%02x:%02x:%02x:%02x:%02x",
                    &s, &s, &s, &s, &s, &s);
   return (nOK == 6);
}
