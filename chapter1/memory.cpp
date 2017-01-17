#include "grader.h"
#include "memory.h"

void play() {
  int seen[25][2];
   int i;
   for(i=0;i<=24;i++)
   {
     seen[i][0] = 0; seen[i][1] = 0;
   }
   char a, b;
   for (i=1; i<=50; ++i) {
      a = faceup(i);
      if(seen[a - 'A'][0] != 0)
        seen[a-'A'][1] = i;
      else
        seen[a-'A'][0] = i;
   }
   for(i=0;i<25;i++)
   {
     a = faceup(seen[i][0]);
     b = faceup(seen[i][1]);
   }
   return;
}
