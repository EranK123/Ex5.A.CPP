#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
using namespace ariel;

TEST_CASE("Bad"){
     OrgChart organization;
     CHECK_THROWS(organization.add_sub("CEO", "CFO"));
     CHECK_THROWS(organization.add_sub("CTO", "VP_SW"));
     CHECK_THROWS(organization.add_sub("COO", "VP_BI"));
     CHECK_THROWS(organization.add_sub("CFO", "VP_BI"));
    

     organization = organization.add_root("CEO").add_sub("CEO", "CFO");
}


TEST_CASE("Good"){
   OrgChart organization;
     organization.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW"); // Now the VP Software is subordinate to the CTO
    vector<string> s;
     size_t i = 0;
    OrgChart::Iterator it;
    for (it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {

    s.push_back(*it);
  }
   CHECK(s.at(0) == "CEO");
   CHECK(s.at(1) == "CTO");
   CHECK(s.at(2) == "CFO");
   CHECK(s.at(3) == "COO");
   CHECK(s.at(4) == "VP_SW");
  for ( it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
    s.push_back(*it);
  }
   CHECK(s.at(0) == "VP_SW");
   CHECK(s.at(1) == "CTO");
   CHECK(s.at(2) == "CFO");
   CHECK(s.at(3) == "COO");
   CHECK(s.at(4) == "CEO");
   for ( it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
  {
    s.push_back(*it);
  }
   CHECK(s.at(0) == "CEO");
   CHECK(s.at(1) == "CTO");
   CHECK(s.at(2) == "VP_SW");
   CHECK(s.at(3) == "CFO");
   CHECK(s.at(4) == "COO");
   for (auto element : organization)
  { 
    s.push_back(*it);
  }
   CHECK(s.at(0) == "CEO");
   CHECK(s.at(1) == "CTO");
   CHECK(s.at(2) == "CFO");
   CHECK(s.at(3) == "COO");
   CHECK(s.at(4) == "VP_SW"); 
}