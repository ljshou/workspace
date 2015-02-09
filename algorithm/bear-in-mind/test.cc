/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-27
 */


int GetNextPrime(vector<bool> &flags, int prime)
{
    int i = prime + 1;
    while(i < flags.size() && !flags[i]) {
        ++i;
    }
    return i;
}
void CrossOff(vector<bool> &flags, int prime)
{
    for(int i = prime*prime; i<flags.size(); i += prime)
        flags[i] = false;
}
void GeneratePrime(int max) 
{
    assert(max > 1);
    vector<bool> flags(max+1, true);
    flags[0] = flags[1] = false;

    int prime = 2;
    while(prime <= max) {
        CrossOff(flags, prime);
        prime = GetNextPrime(flags, prime);
        if(prime == max) break;
    }

    for(int i=2; i<=max; ++i) {
        if(flags[i]) cout << i << " ";
    }
    cout << endl;
}
