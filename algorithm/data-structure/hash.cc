#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <bitset>
using namespace std;

const int kSeqHash = 100000;
const int kNum = 100000;
struct Seq
{
  bitset<100> seq;
  int value;
  Seq *link;
};

struct Seq *g_seq_hash_table[kSeqHash];

int HashSeq(bitset<100> seq)
{
  unsigned long long s = seq.to_ulong();
  return s%kSeqHash;
}

void Init()
{
  for(int i=0; i<kSeqHash; ++i)
    g_seq_hash_table[i] = NULL;
}

void DestroyHashTable()
{
  for(int i=0; i<kSeqHash; ++i)
  {
    struct Seq *s, *temp;
    for(s=g_seq_hash_table[i]; s!=NULL;)
	{
	  temp = s->link;
	  delete s;
	  s = temp;
	}
	g_seq_hash_table[i] = NULL;
  }
}

int FindSeq(bitset<100> s)
{
  int hash_value = HashSeq(s);
  struct Seq *p;
  for(p=g_seq_hash_table[hash_value]; p!=NULL; p=p->link)
  {
    if(s == p->seq)
	  return hash_value;
  }
  p = new struct Seq;
  p->seq = s;
  p->value = s[0];
  p->link = g_seq_hash_table[hash_value];
  g_seq_hash_table[hash_value] = p;
  return hash_value;
}

void PrintHashTable()
{
  for(int i=0; i<kSeqHash; ++i)
  {
    int length(0);
    if(g_seq_hash_table[i] != NULL)
	{
	  cout << i << ": ";
      for(struct Seq *p=g_seq_hash_table[i]; p!=NULL; p=p->link)
	    ++ length;
	    //cout << p->seq << "(" << p->value << ") ";
	  cout << length << endl;
	}
  }
}

int main()
{
  string str, dna_input("10001001001101001111011010011110001000011001000010011011101100111101110000110101100010000101100100010110101011011001110111011111010010010101001001111100011100111000011100001111110001000011010001111000");
  map< string, int > seq;
  ifstream infile_binary("dnasequence_binary.dat");
  ifstream infile("dnasequence.dat");

  Init();
  //bianry
  while(infile_binary >> str)
  {
  	bitset<100> s(str);
    FindSeq(s);
  }
  while(infile >> str)
  {
	seq[str] = str[0];//key
  }
  infile.close();
  infile_binary.close();
  PrintHashTable();

  srand(time(0));

  bitset<100> dna(dna_input);

  cout << "************** Start testing ***********************" << endl;
  clock_t start = clock();
  for(int i(0); i<kNum; ++i)
    seq[dna_input];
  clock_t finish = clock();
  cout << "Old method takes: " << static_cast<double>(finish-start)/CLOCKS_PER_SEC << " seconds." << endl;

  cout << "************** Start testing ***********************" << endl;
  start = clock();
  for(int i(0); i<kNum; ++i)
    FindSeq(dna);
  finish = clock();
  cout << "New method takes: " << static_cast<double>(finish-start)/CLOCKS_PER_SEC << " seconds." << endl;

  DestroyHashTable();

  return 0;
}


