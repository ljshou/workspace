/**
 * @file test.cc
 * @brief a test class
 * @author shoulinjun@126.com ljshou.gitcafe.com
 * @version 0.1.00
 * @date 2014-12-26
 */

/*! 
 * @todo
 * @bug
 * A test class */
class Test
{
public:
    /** An enum type.
     * * The documentation block cannot be put after the enum!
     * */
    enum EnumType
    {
        int EVal1, /**< enum value 1 */
        int EVal2 /**< enum value 2 */
    };
    void member(); //!< a member function.
protected:
    int value; /*!< an integer value */
};

