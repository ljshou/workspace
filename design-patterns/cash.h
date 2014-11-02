// Last Update:2014-03-19 21:32:45
/**
 * @file cash.h
 * @brief Strategy Pattern
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-17
 */

#ifndef CASH_H
#define CASH_H

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cassert>

/* abstract base class
 * define interface
 */
class CashSuper
{
public:
    virtual ~CashSuper() {}
    virtual double acceptCash(double money) = 0;
};

class CashNormal : public CashSuper
{
public:
    double acceptCash(double money){
        return money;
    }
};

class CashRebate : public CashSuper{
public:
    CashRebate(std::string moneyRate = "0.0"){
        std::stringstream s(moneyRate);
        s >> this->moneyRate_;
    }

    double acceptCash(double money){
        return money * moneyRate_; 
    }
private:
    double moneyRate_;
};

class CashReturn : public CashSuper{
public:
    CashReturn(std::string moneyCondition, std::string moneyReturn){
        std::stringstream s(moneyCondition);
        s >> this->moneyCondition_;
        std::stringstream s2(moneyReturn);
        s2 >> this->moneyReturn_;
    }


    double acceptCash(double money){
        if(money >= moneyCondition_){
            money -= std::floor(money / moneyCondition_) * moneyReturn_;
        }
        return money;
    }
private:
    double moneyCondition_, moneyReturn_;
};

/* handler class
 * smart pointer
 */
class CashContext{
public:
    CashContext(std::string type)
    : pCashSuper_(NULL), use(new std::size_t(1))
    {
        if(type == "正常收费"){
            pCashSuper_ = new CashNormal;
        }
        else if(type == "满300减100"){ 
            pCashSuper_ = new CashReturn("300", "100");
        }
        else if(type == "打8折"){ 
            pCashSuper_ = new CashRebate("0.8");
        }
        // else
    }

    // copy control
    CashContext(const CashContext &rhs)
    : pCashSuper_(rhs.pCashSuper_), use(rhs.use)
    {
      ++ *use;
    }
    // deal with self-assignment
    CashContext& operator=(const CashContext &rhs){
      ++ *(rhs.use);
      if(-- *use == 0){ 
        delete pCashSuper_;
        delete use;
      }
      pCashSuper_ = rhs.pCashSuper_;
      use = rhs.use;
      return *this;
    }

    ~CashContext(){
      if(-- *use == 0){
        delete pCashSuper_;
        delete use;
      }
    }
    
    double GetResult(double money){
        assert(pCashSuper_ != NULL); 
        return pCashSuper_->acceptCash(money);
    }
private:
    CashSuper *pCashSuper_;
    std::size_t *use;
};


/* factory class
 */
class CashFactory{
public:
    static CashSuper* createCashSuper(std::string type)
    {
        CashSuper *pCashSuper(NULL);

        if(type == "正常收费"){
            pCashSuper = new CashNormal();
        }
        else if(type == "满300减100"){ 
            pCashSuper = new CashReturn("300", "100");
        }
        else if(type == "打8折"){ 
            pCashSuper = new CashRebate("0.8");
        }
        else{
            return NULL;
        }
        return pCashSuper;
    }
};

#endif  /*CASH_H*/
