#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <string>
#include <vector>


namespace ein_jrw_prog4
{
	class Node
	{
		public:
			// Constructor
			Node(std::string init_word,int init_lineNum, Node* left_init = NULL, Node* right_init = NULL)
			{
				word = init_word;
				leftNode = left_init;
				rightNode = right_init;
				count = 1;
				linenums.push_back(init_lineNum);
			}
			// Modification functions
			void addLineNum(int lineNum) {if (linenums.back() != lineNum) linenums.push_back(lineNum);}
			Node*& left() {return leftNode;}
			Node*& right() {return rightNode;}
			void incrementWordCount(int line){count++; addLineNum(line);}
			// Constant member function
			const int getWordCount() const {return count;}
			const std::string getWord() const {return word;}
			const Node* left() const {return leftNode;}
			const Node* right() const {return rightNode;}
			const std::vector<int> getLineNums() const {return linenums;}
		private:
			std::string word;
			int count;
			std::vector<int> linenums;
			Node *leftNode;
			Node *rightNode;
	};
}
#endif /*  NODE_H */
