// Last Update:2014-05-25 23:21:39
/**
 * @file immutable_queue_test.cpp
 * @brief  
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-24
 */
#include "immutable_queue.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <ctime>
#include <cstdlib>
using namespace std;

class immutable_queue_test
{
public:
  static void test_immutable_queue() {
    immutable_queue<int> p; 

    assert(p.size() ==  0);
    p = p.enqueue(2);
    assert(p.size() ==  1);
    p = p.enqueue(9);
    assert(p.size() ==  2);
    p = p.dequeue();
    assert(p.peek() == 9);
    p = p.enqueue(10);
    assert(p.peek() ==  9);
    p = p.dequeue();
    assert(p.peek() ==  10);
    p = p.dequeue();
    assert(p.size() == 0);
    //p.peek();
  }

static void test_immutable_queuePerformance() {
	immutable_queue<int> p;
	int num = 0;
	int max = 1000000;
    /*
    int *value = new int[max];

    cout << "start inputing" << endl;
    //generate_random_data(max, "random.dat");
    input_data(value, "randome.dat");
    cout << "end inputing" << endl;
    //generate_random_data(max, "random.dat");

    */
    clock_t start = clock();
    for(int i=0; i<max; ++i)
    {
		//p = p.enqueue(value[i]);
        p = p.enqueue(rand() % 100);
    }

    clock_t finish = clock();
    cout << "enqueue time: " << static_cast<double>(finish - start) / CLOCKS_PER_SEC << endl;
    finish = clock();

    for(int i=0; i<max; ++i) {
		p = p.dequeue();
	}

    clock_t end = clock();
    cout << "dequeue time: " << static_cast<double>(end - finish) / CLOCKS_PER_SEC << endl;
    cout << "all time: " << static_cast<double>(end - start) / CLOCKS_PER_SEC << endl;
    //delete [] value;
}

private:
static void generate_random_data(int num, const string &file)
{
  ofstream ofile(file.c_str());
  ofile << num << endl;
  for(int i=0; i<num; ++i)
  {
    ofile << rand() % 100 << endl;
  }
  ofile.close();
}

static void input_data(int *&p, const string &file)
{
  ifstream  ifile(file.c_str());
  string line;
  int num(0);
  getline(ifile, line);
  istringstream stream(line);
  stream >> num;

  for(int i=0; i<num; ++i)
  {
    getline(ifile, line);
    stream.str(line); stream.clear();
    stream >> p[i];
    cout << p[i] << endl;
  }

  ifile.close();
}

};

int main(void)
{
  immutable_queue_test::test_immutable_queue();
  immutable_queue_test::test_immutable_queuePerformance();
  
  return 0;
}
