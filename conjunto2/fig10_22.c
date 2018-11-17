/* ECP: FILEname=fig10_22.c */
   #include <stdio.h>
   #include <stdlib.h>

   #define NotFound  (-1)

   typedef struct HashEntry
   {
       char *Word;
       int Num;
   } Cell;

   typedef struct HashStr
   {
       Cell *Array;      /* The Array Of Cells */
       int Size;         /* Current Number Of Elements in Table */
       int MaxSize;      /* Maximum Table Size */
   } *HashTbl;

   static const HaInitSize = 17;


   unsigned int
   Hash( const char *Key, const unsigned int TableSize )
   {
       unsigned int HashVal = 0;

       while( *Key != '\0' )
           HashVal = HashVal * 37 + *Key++;

       return HashVal % TableSize;
   }
