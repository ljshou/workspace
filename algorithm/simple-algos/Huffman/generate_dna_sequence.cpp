/* randomly generate DNA sequence by L.J. in Nov.01, 2013 */
#include <ctime>

#include <iostream>
#include <fstream>
#include <string>
#include<bitset>

using namespace std;

const int kNum = 100000;
const int kMaxSequenceLength = 50;

int main()
{
  int length;
  ofstream outfile_char, outfile_binary;
  outfile_char.open("dnasequence_binary.dat");
  //outfile_binary.open("dnasequence.bin", ios::binary);
  outfile_binary.open("dnasequence.dat");

  srand(time(0));

  for(int i(0); i<kNum; ++i)
  {
    length = kMaxSequenceLength;
	bitset<100> seq;

	for(int j(0); j<length; ++j)
	{
      switch( rand() % 4 )
      {
        case 0: { 
		  seq[2*j+0] = 0;
		  seq[2*j+1] = 0;
		  outfile_binary << 'A';  
		  break;
		  //outfile_binary <<'0'<<'0'; break; 
		}
        case 1: { 
		  seq[2*j+0] = 0;
		  seq[2*j+1] = 1;
		  outfile_binary << 'T';  
		  break;
		  //outfile_char << 'T';  
		  //outfile_binary <<'0'<<'1'; break; 
		}
        case 2: { 
		  seq[2*j+0] = 1;
		  seq[2*j+1] = 0;
		  outfile_binary << 'C';
		  break;
		  //outfile_char << 'C';  
		  //outfile_binary <<'1'<<'0'; break; 
		}
	    default:{
		  seq[2*j+0] = 1;
		  seq[2*j+1] = 1;
		  outfile_binary << 'G';
		  break;
		  //outfile_char << 'G';  
		  //outfile_binary <<'1'<<'1'; 
		}
      }
	}
	outfile_char << seq << endl;
	outfile_binary << endl;
  }

  outfile_char.close();
  outfile_binary.close();
  return 0;
}

