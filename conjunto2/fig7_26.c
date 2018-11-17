/* ECP: FILEname=fig7_26.c */
   /* Read An Unlimited Number Of Ints */
   /* With No Attempts At Error Recovery */
   /* Correct Implementation */
   /* Returns A Pointer To The Data */
   /* ItemsRead Is Set By Reference To #Items Read */

   int *
   GetInts( int * const ItemsRead )
   {
       int NumRead = 0;
       int ArraySize = 5;
       int InputVal, *Array;
       
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

       *ItemsRead = NumRead;
       return realloc( Array, sizeof( int ) * NumRead );
   }

   main( void )
   {
       int *NumArray;
       int ItemsRead;

       NumArray = GetInts( &ItemsRead );
       PrintNondup( NumArray, ItemsRead );
       return !ItemsRead;
   }
