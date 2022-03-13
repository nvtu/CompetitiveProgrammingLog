// set::lower_bound/upper_bound
#include <iostream>
#include <set>
using namespace std;

int main ()
{
  std::set<int> myset;
  std::set<int>::iterator itlow,itup;
  myset.insert(4);
//  myset.insert(1);


  itlow=myset.lower_bound (3);                //       ^
  itup=myset.upper_bound (3);                 //                   ^
  cout << *(--itlow) << " " << *itup <<  endl;

  return 0;
}
