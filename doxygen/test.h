/**
 * @file test.h
 * @brief a test class
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2014-12-26
 */

/*! 
 * @class Test
 * @brief a test class
 * @bug
 */
class Test
{
public:
    /** An enum type.
     * The documentation block cannot be put after the enum!
     */
    enum EnumType
    {
        int EVal1, ///< enum value 1 
        int EVal2 /**< enum value 2 */
    };

    /**
     * @brief member access func
     * @param index: index of member
     * @return value of the index'th member
     * @todo
     */
    int GetMember(int index) const;
protected:
    int value; ///< an integer value 
    int *members; ///< integer array

private:
    int private_value; /**< private count */
};

