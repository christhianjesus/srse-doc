/* ECP: FILEname=fig12_7.c */
   /* Read A Bunch Of Integers */
   /* Wrong Way To Check for Errors */

   #include <stdio.h>

   main( void )
   {
       int X, ArgsMatched;

       for( ; ; )
       {
           printf( "Enter an integer: " );
           ArgsMatched = scanf( "%d", &X );
           if( ArgsMatched == 0 )
           {
               printf( "You did not enter an integer... \n" );
               continue;    /* Wrong: No Digestion Of Input */
           }
           else
           if( ArgsMatched == 1 )
               printf( "Read %d\n", X );
           else
               break;		/* EOF */
       }
       return 0;
   }
