/* ECP: FILEname=fig10_28.c */
   typedef int DisType;
   #define Infinity IntMax
   #define MaxNodes 3000

   typedef struct              /* Basic Vertex Structure */
   {
       char *NodeName;         /* Name */
       DisType Distance;       /* Distance From Start */
       int PreviousNode;       /* Previous Vertex On Path */
       VarArray Adj;           /* List Of Adjacent Vertices */
   } Vertex;

   int
   AddNode( const char *Name, HashTbl H, Vertex Graph[ ] )
   {
       int NodeNum;
       const Vertex NewVert = { NULL, Infinity, -1, { 0, 0, NULL } };

       if( ( NodeNum = Find( Name, H ) ) < 0 )
       {
           NodeNum = Insert( Name, H );
           if( NodeNum == MaxNodes )
           {
               printf( "Graph is full. Increase MaxNodes\n" );
               exit( -1 );
           }
           Graph[ NodeNum ] = NewVert;
           Graph[ NodeNum ].NodeName = Strdup( Name );
       }
       return NodeNum;
   }


   void
   AddEdge( int Source, int Dest, Vertex Graph[ ] )
   {
       Add( Dest, &Graph[ Source ].Adj );
   }
