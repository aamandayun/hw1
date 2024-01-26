#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

ULListStr * makeList(std::vector<std::string> const & values, bool pushBack)
{
	// circular list is not copyable so we have to pass it by pointer
	ULListStr * list = new ULListStr();

	if(pushBack)
	{
		for(std::vector<std::string>::const_iterator valuesIter = values.cbegin(); valuesIter != values.cend(); ++valuesIter)
		{
			list->push_back(*valuesIter);
		}
	}
	else
	{
		// push values in reverse from the front
		for(std::vector<std::string>::const_reverse_iterator valuesIter = values.crbegin(); valuesIter != values.crend(); ++valuesIter)
		{
			list->push_front(*valuesIter);
		}
	}

	return list;
}

void printAll(ULListStr list) {
  size_t size = list.size();
  for(size_t i = 0; i < size; i++) {
    cout << i << endl;
    cout << list.get(i) << " -> ";
  }
  cout << endl;
}

int main(int argc, char* argv[])
{

  ULListStr list;

  for(int i = 0; i<50; i++){
    list.push_back(to_string(i));
  }


  for(int i = 0; i<50; i++){
    list.pop_front();
  }


  



}
