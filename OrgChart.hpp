#pragma once
namespace ariel{
    class OrgChart{
        private:
        string position;
        public:
        OrgChart();
        OrgChart add_root(string position);
        OrgChart add_sub(string higherPosName, string lowerPosName);
        friend ostream& operator<<(ostream& output, const OrgChart &org);
    public:
    class iterator{
      private:
      string *currentName;
      public:
      iterator(string* ptr = nullptr){
          this->currentName = ptr;
      }
      bool operator!=(const iterator& it) const;
      const iterator operator++(int);
      const iterator operator++();
      string operator*() const; 
      string* operator->() const; 

    };
    iterator begin();
    iterator end();
    iterator begin_level_order();
    iterator end_level_order();
    iterator begin_reverse_order();
    iterator reverse_order();
    iterator begin_preorder();
    iterator end_preorder();
 };
   
}