#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;
#include <string>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


void ULListStr::push_back(const std::string& val){
  if(this->tail_ == nullptr && head_==nullptr){
    Item* newItem = new Item;
    newItem->first = 0;
    newItem->val[newItem->first] = val;
    newItem->last = 1;
    tail_ = newItem;
    head_ = newItem;
    size_++;
    // if(head_!=nullptr){
    //   head_->next = tail_;
    //   tail_->prev = head_;
    // }

  }else if(this->tail_->last > 9){
    Item* newItem = new Item;
    newItem->first = 0;
    newItem->val[newItem->first] = val;
    newItem->last = 1;
    Item* temp = tail_;
    tail_->next = newItem;
    newItem->prev = temp;
    newItem->next = nullptr;
    tail_=newItem;
    // if(head_==nullptr){
    //   head_=temp;
    // }
    size_++;
  }
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
}
void ULListStr::push_front(const std::string& val){
  if(this->head_ == nullptr && tail_ == nullptr){
    Item* newItem = new Item;
    newItem->first = 9;
    newItem->val[newItem->first] = val;
    newItem->last = 10;
    head_ = newItem;
    tail_= newItem;
    size_++;

  }else if(head_->first == 0){
    Item* newItem = new Item;
    newItem->first =9;
    newItem->val[newItem->first] = val;
    newItem->last = 10;
    Item* temp = head_;
    head_->prev = newItem;
    head_ = newItem;
    head_->next = temp;
    temp->prev = head_;
    head_->prev = nullptr;
    size_++;
    if(tail_==nullptr){
      tail_ =temp;
    }
  }
  else{
    head_->val[head_->first-1] = val;
    head_->first--;
    size_++;
  }
}
void ULListStr::pop_back(){
  if(tail_==head_ && size_>0){
    head_->val[head_->last-1] = "";
    head_->last--;
    size_--;
    if(head_->last <=0){
      head_=NULL;
    }
  }else{
    tail_->val[tail_->last-1] = "";
    tail_->last--;
    size_--;
    if(tail_->last<=0){
      Item* temp = tail_;
      tail_ = tail_->prev;
      delete temp;
    }
  }
/*
  if(tail_==nullptr && head_!=nullptr){
    head_->val[head_->last-1] = "";
    head_->last--;
    size_--;
    if(size_<=0){
      delete head_;
    }
  }else if(tail_!=nullptr){
    tail_->val[tail_->last-1] = "";
    tail_->last--;
    size_--;
  
    if(tail_->last<=0){
      if(tail_->prev!=nullptr){
        Item* temp = tail_;
        tail_ = tail_->prev;
        delete temp;
      }else{
        if(head_!=NULL){
          head_=NULL;
        }
        
      }
    }
  }
  */
}
void ULListStr::pop_front(){
  if(tail_==head_ && size_>0){
    head_->val[head_->first] = "";
    head_->first++;
    size_--;
  }else{
    head_->val[head_->first] = "";
    head_->first++;
    size_--;
    if(head_->first>9){
      Item* temp = head_;
      head_ = head_->next;
      delete temp;
    }
  }

  /*
  if(head_==nullptr && tail_!=nullptr){
    tail_->val[tail_->first] = "";
    tail_->first++;
    size_--;
    if(size_<=0){
      delete tail_;
    }
  }else if(head_!=nullptr){
    head_->val[head_->first] = "";
    head_->first++;
    size_--;

    if(head_->first>9){
      Item* temp = head_;
      head_ = head_->next;
      delete temp;
    }
  }*/
  
}

std::string const & ULListStr::back() const{
//assume list is not empty
  if(tail_==nullptr && head_!=nullptr){
    return head_->val[head_->last-1];
  }else{
    return tail_->val[tail_->last-1];
  }
}
std::string const & ULListStr::front() const{
//assume list is not empty  
  if(head_==nullptr && tail_!=nullptr){
    return tail_->val[tail_->first];
  }else{
    return head_->val[head_->first];
  }

}

std::string* ULListStr::getValAtLoc(size_t loc) const{
//returns a pointer to the i-th value in the entire list
  if(loc>=size_ || loc<0){
    return NULL;
  }
  //need to fix
  Item* cur;
  if(head_ !=nullptr){
    cur = head_;
  }else if(head_ == nullptr && tail_ != nullptr){
    cur = tail_;
  }else if(head_==nullptr && tail_== nullptr){
    return NULL;
  }

  size_t total =0;
  size_t search = loc;

  // std::cout << "Loc: " << loc << std::endl;
  while(cur!=nullptr){
    if(search>=(cur->last - cur->first)){
      search -= cur->last - cur->first;
      cur = cur->next;
    }else{

      return &cur->val[search + cur->first];
    }
  }

  return NULL;
}

