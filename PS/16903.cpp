#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

#define ioset() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

class BinaryTreeNode {
public:
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    int cnt; // 자신을 포함한 모든 자식 노드의 개수

    BinaryTreeNode(int val) : value(val), left(nullptr), right(nullptr), cnt(0) {}
};

class BinaryTree {
public:
    BinaryTreeNode* root;

    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        if (root == nullptr) {
            root = new BinaryTreeNode(value);
        }
        insertRecursive(root, value);
    }

    void insertRecursive(BinaryTreeNode* currentNode, int value) {
        for (int i = 29; i >= 0; --i) {
            int bit = (value >> i) & 1;
            currentNode->cnt++; // cnt 업데이트

            if (bit == 0) {
                if (currentNode->left == nullptr) {
                    currentNode->left = new BinaryTreeNode(0);
                }
                currentNode = currentNode->left;
            } else {
                if (currentNode->right == nullptr) {
                    currentNode->right = new BinaryTreeNode(1);
                }
                currentNode = currentNode->right;
            }
        }
        currentNode->value = value; // 최종 노드에 값 삽입
        currentNode->cnt++;
    }

    void remove(int value) {
        removeRecursive(root, value);
    }

    void removeRecursive(BinaryTreeNode* currentNode, int value) {
        // 이진수로 변환하여 삭제
        for (int i = 29; i >= 0; --i) {
            int bit = (value >> i) & 1;
            currentNode->cnt--; // cnt 업데이트

            if (bit == 0) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }
        currentNode->cnt--;
    }

    int find(int value) {
        return findRecursive(root, value);
    }

    int findRecursive(BinaryTreeNode* currentNode, int value) {
        int check = 0;
        for (int i = 29; i >= 0; --i) {
            int bit = (value >> i) & 1;
            if (check == 0 && bit == 0 && currentNode->right != nullptr && currentNode->right->cnt==0){
              currentNode = currentNode->left;
              continue;
            }
            else{
              check=1;
            }

            if (bit == 1) {
                if(currentNode->left != nullptr && currentNode->left->cnt>0)
                  currentNode = currentNode->left;
                else
                  currentNode = currentNode->right;
            } else {
                if(currentNode->right != nullptr && currentNode->right->cnt>0)
                  currentNode = currentNode->right;
                else
                  currentNode = currentNode->left;
            }
        }
        return currentNode->value;
    }
};

int main() {
    ioset();
    BinaryTree binaryTree;
    binaryTree.insert(0);

    int m, x, y;

    cin >> m;
    while(m--){
        cin >> x >> y;
        if(x==1) binaryTree.insert(y);
        else if(x==2) binaryTree.remove(y);
        else cout << (y ^ binaryTree.find(y)) << '\n';
    }

    return 0;
}
