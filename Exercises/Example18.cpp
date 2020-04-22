#include <iostream> 
#include <fstream> 
using namespace std;
int main() { 
fstream file; 
file.open( "file18.txt", ios::in | ios::out ); 
if( file.good() == true ) { 
cout << "File access granted!" << endl;
file.close();
} 
else cout << "File access forbidden " << endl;
return( 0 );
}

