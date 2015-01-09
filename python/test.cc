/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-04
 */
#include <string>
#include <boost/python.hpp>
using namespace boost::python;
#pragma comment(lib, "boost_python.lib")
std::string strtmp;
char const* Recognise(const char* url)
{
    strtmp ="从dll中返回的数据... : ";
    strtmp+=url;
    return strtmp.c_str();
}
BOOST_PYTHON_MODULE(hello_ext)
{
    def("Recognise", Recognise);
}
