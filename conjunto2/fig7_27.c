/* ECP: FILEname=fig7_27.c */
   /* Read An Umlimited Number Of Ints */
   /* With No Attempts At Error Recovery */
   /* Returns #Items Read */
   /* Will Fail Because Array Is A Copy Of NumArray And So */
   /* Changes In Where It Points Are Not Seen in NumArray */

   int
   GetIntsWrong( int *Array )
   {
       int NumRead = 0;
       int ArraySize = 5;
       int InputVal;
       
       Array = malloc( sizeof( int ) * ArraySize );
       if( Array == NULL )
           Error( "Out of memory" );

       printf( "Enter any number of integers: " );
       while( scanf( "%d", &InputVal ) == 1 )
       {
           if( NumRead == ArraySize )
           {	/* Array Doubling Code */
               ArraySize *= 2;
               Array = realloc( Array, sizeof( int ) * ArraySize );
               if( Array == NULL )
                   Error( "Out of memory" );
           }
           Array[ NumRead++ ] = InputVal;
       }

       return NumRead;
   }
