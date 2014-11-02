/* Description: Skip List    ********** 
*  Author:      L.J.         **********
*  Date:        Nov.21, 2013 **********
*  Modify:		             **********
*/
#ifndef _SKIP_LIST_H_
#define _SKIP_LIST_H_
template<class E, class K> class SkipList;
template<class E, class K> class SkipNode;

template<class E, class K>
class SkipNode
{
  friend class SkipList<E,K>;
  private:
    SkipNode(int size)
	  {link = new SkipNode*[size];}
	~SkipNode() {delete [] link;}
	E data;
	SkipNode<E,K> **link;
};

template<class E, class K>
class SkipList
{
  public:
    SkipList(K large, int MaxE = 10000, double p = 0.5);
		~SkipList();
		bool Search(const K&k, E&e) const;
		SkipList<E,K>& Insert(const E & e);
		SkipList<E,K>& Delete(const K & k, E & e);
		void PrintSkipList();
  private:
	  int Level();
		SkipNode<E,K> *SaveSearch(const K & k);
		int MaxLevel; 
		int Levels;
		int CutOffs;
		K TailKey;
		SkipNode<E,K> *head;
		SkipNode<E,K> *tail;
		SkipNode<E,K> **last;
};

#endif
