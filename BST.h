#ifndef BST_H
#define BST_H
#include "Node.h"
#include <string>

namespace ein_jrw_prog4
{
	class Bin_STree
	{
		public:
			// Constructor
			Bin_STree(){ rootPtr = NULL; numElements = 0; }
			// Modification functions
			void insert(std::string s,int lineNum);
			void printTreeInOrder(const Node* nodePtr);
			Node*& getRootPtr() {return this->rootPtr;}
			int getNumElements() {return numElements;}
		private:
			Node *rootPtr;
			int numElements;
	};
}
#endif /*  BST_H */
