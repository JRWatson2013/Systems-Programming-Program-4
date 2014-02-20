#include "BST.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>

namespace ein_jrw_prog4
{
	void Bin_STree::insert(std::string s,int lineNum)
	{
		Node *cursor = rootPtr;
		bool isDone = false;
		// If this is the first word inserted
		if( rootPtr == NULL)
		{
			rootPtr = new Node(s,1);
			//std::cout << "INITIALIZED!" << std::endl;
			isDone = true;
		}
		while(!isDone)
		{

			// If  the word being insertred goes before the cursor
			//std::cout << "Is " << s << " before " << cursor->getWord() << std::endl;
			if(s < cursor->getWord() )
			{
				//std::cout << "Yes" << std::endl;
				if( cursor->left() == NULL)
				{
					cursor->left() = new Node(s,lineNum);
					isDone = true;
					numElements++;
				}
				else
					cursor = cursor->left();
			}
			//std::cout << "Is " << s << " after " << cursor->getWord() << std::endl;
			// If he word being inserted goes after the cursor word
			if( s > cursor->getWord() )
			{
				if( cursor->right() == NULL)
				{
					cursor->right() = new Node(s,lineNum);
					numElements++;
					isDone = true;
				}
				else
					cursor = cursor->right();
			}
			//std::cout << "Is " << s << " the same as " << cursor->getWord() << std::endl;
			// If the cursor is pointing to a Node, it must be a duplicate
			if( s == cursor->getWord() )
			{
				cursor ->incrementWordCount(lineNum);
				isDone = true;
			}
		}
	}
	void Bin_STree::printTreeInOrder(const Node* nodePtr)
	{
		if(nodePtr != NULL)
		{
			printTreeInOrder( nodePtr->left() );
 			//printf("|%21s |%18d |",nodePtr->getWord(),nodePtr->getWordCount());
 			std::cout << "|" << std::setw(21) << nodePtr->getWord();
 			std::cout << " |" << std::setw(19) << nodePtr->getWordCount() << " | ";
			for( int i = 0; i < nodePtr->getLineNums().size(); ++i)
			{
				if(i < nodePtr->getLineNums().size() - 1 )
					std::cout << nodePtr->getLineNums()[i] << ", ";
				else
					std::cout << nodePtr->getLineNums()[i];
				if(i != 0)
				{
					if( i % 10 == 0)
					{
						if( i != nodePtr->getLineNums().size() - 1)
						{
							std::cout << std::endl << "|" << std::setw(22) << " ";
							std::cout << "|" << std::setw(22) << " | ";
						}
					}
				}

			}
			std::cout << std::endl;
			printTreeInOrder( nodePtr->right() );
		}
	}
}
