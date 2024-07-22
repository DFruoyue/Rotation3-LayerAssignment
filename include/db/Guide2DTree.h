#pragma once
#include <fstream>
#include "Gcell.h"
#include <vector>
namespace XZA{
    struct TreeNode{

        bool isPin = false;
        std::vector<int> pinIdx;

        Location loc;
        std::vector<TreeNode*> childs;
        TreeNode* parent = nullptr;

        TreeNode(): loc(0, 0, 0){};
        TreeNode(const int &x, const int &y, const int&l = 0): loc(l, x, y){};
        TreeNode(const Location& loc): loc(loc){};
    };
    class Guide2DTree{
        
        private:
            TreeNode* root = nullptr;
            void _output(TreeNode* node, int depth) const;
            void freeTree(TreeNode* node);

        public:
            Guide2DTree()
                :root(nullptr){}
            ~Guide2DTree(){freeTree(root);}
            
            void load(std::ifstream& file);
            void output() const;
            bool targetPin(const int& pinIdx, const Location& loc);
    };
}