#include <windows.h>
int main ( void )
{
 unsigned int frequency [] =
 { 
  392,392,440,392,523,494, 
  392,392,440,392,587,523, 
  392,392,784,659,523,494,440, 
  698,698,659,523,587,523
 };

 unsigned int delay[] = 
 {
  375,125,500,500,500,1000, 
  375,125,500,500,500,1000, 
  375,125,500,500,500,500,1000, 
  375,125,500,500,500,1000,
 }; 

 int   i; 

 for ( i=0; i < 25; i++ ) 
 { 
  Beep ( frequency[i] * 5, delay[i] );

  if ( i == 24 )
  {
   Sleep ( 500 );
   i = 0;
  }
 } 
 return 0;
}

