// Last Update:2014-03-23 17:24:16
/**
 * @file item.h
 * @brief item class
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-19
 */

#ifndef ITEM_H
#define ITEM_H

class Item_base{
public:
    virtual Item_base* clone() const{
        return new Item_base(*this);
    }
};

class BulkItem : public Item_base{
public:
    virtual BulkItem* clone() const{
        return new BulkItem(*this);
    }
};


#endif  /*ITEM_H*/
