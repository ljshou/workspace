#include <ctime>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <hash_map>
#include <map>
#include <bitset>

#include <boost/dynamic_bitset.hpp>

using namespace std;

const int kNum = 0x7ffff;
const int kMaxSequenceLength = 100;

class MyDNA
{
public:
  MyDNA(int n):length(n){}
  MyDNA(const MyDNA& DNA):length(DNA.length)
  {
	for(int i=0; i<length/8; ++i)
	  this->dna[i] = DNA.dna[i];
  }
  MyDNA(const string& DNA):length(2*DNA.size())
  {
    for(size_t i=0; i<DNA.size(); ++i)
    {
      switch( DNA[i] )
      {
	   case 'A': {dna[2*i]=dna[2*i+1]=0;break;}
	   case 'T': {dna[2*i]=0;dna[2*i+1]=1;break;}
	   case 'C': {dna[2*i]=1;dna[2*i+1]=0;break;}
	   case 'G': {dna[2*i]=dna[2*i+1]=1;}
	  }
    }
  }
  MyDNA& operator=(const MyDNA& DNA)
  {
    this->length = DNA.length;
	for(int i=0; i<length; ++i)
	  this->dna[i] = DNA.dna[i];
	return *this;
  }
  bool operator<(const MyDNA& rhs)const
  {
    int i(0), j(0);
	while(i<this->length && j<rhs.length && this->dna[i]==rhs.dna[j])
	{
	  ++i; ++j;
	}
	if(i==this->length || j==rhs.length)
	{
	  return (this->dna[i-1] < rhs.dna[i-1]);
	}
	return (this->dna[i] < rhs.dna[i]);
  }
  int length;
  char dna[25];
};

int main()
{
  int length;
  string dna;
  map< string, int> seq1;
  map<MyDNA, int> seq2;

  ifstream infile1("dnasequence.dat");
  ifstream infile2("dnasequence_binary.dat");
  int k(0);
  while(infile1 >> dna)
  {
	seq1[dna] = k;
    ++k; 
  }
  k = 0;
  while(infile2 >> dna)
  {
    MyDNA dna_binary(dna.size());
	for(size_t i=0; i<dna.size(); ++i)
	  if(dna[i] == '1')
	    dna_binary.dna[i] = 1;
	  else
	    dna_binary.dna[i] = 0;
	seq2[dna_binary] = k;
	++ k;
  }
  infile1.close();
  infile2.close();

  srand(time(0));

  /*
  for(int i(0); i<kNum; ++i)
  {
    length = rand() % kMaxSequenceLength + 1;
	for(int j(0); j<length; ++j)
	{
	  switch( rand() % 4)
	  {
	    case 0: { dna[j] = 'A'; break;}
	    case 1: { dna[j] = 'T'; break;}
	    case 2: { dna[j] = 'C'; break;}
	    case 3: { dna[j] = 'G'; }
	  }
	}
    vector<bitset<1>> dna_binary(2*length);
	for(size_t i=0; i<dna.size(); ++i)
	{
	  switch( dna[i] )
	  {
	   case 'A': {dna_binary[2*i]=dna_binary[2*i+1]=false;break;}
	   case 'T': {dna_binary[2*i]=false;dna_binary[2*i+1]=true;break;}
	   case 'C': {dna_binary[2*i]=true;dna_binary[2*i+1]=false;break;}
	   case 'G': {dna_binary[2*i]=dna_binary[2*i+1]=true;}
	  }
	}
	cout << seq1[dna] << " " << seq2[dna_binary] << endl; 
  }
  */

  dna = string("TGGCCTCGATCAACTCTTGTCTTAAGGGGCATTG");
  MyDNA dna_binary(dna);

  cout << "************** Start testing ***********************" << endl;

  clock_t start = clock();
  for(int i(0); i<kNum; ++i)
    seq1[dna];
  clock_t finish = clock();
  cout << "Old method takes: " << static_cast<double>(finish-start)/CLOCKS_PER_SEC << " seconds." << endl;

  start = clock();
  for(int i(0); i<kNum; ++i)
    seq2[dna_binary];
  finish = clock();
  cout << "New Method takes: " << static_cast<double>(finish-start)/CLOCKS_PER_SEC << " seconds." << endl;

  cout << "**************** End ***********************" << endl;

  return 0;
}

