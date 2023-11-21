#include <climits>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class BinaryTree {
   public:
    int value;
    BinaryTree* lChild;
    BinaryTree* rChild;
    BinaryTree() : lChild(nullptr), rChild(nullptr) {}
};

// 非递归遍历
// 先序遍历
void preOrderUnRecursion(BinaryTree* root) {
    if (root == nullptr) {
        return;
    }

    stack<BinaryTree*> stackOfNode;

    stackOfNode.push(root);

    while (!stackOfNode.empty()) {
        root = stackOfNode.top();
        stackOfNode.pop();
        cout << root->value << " ";

        if (root->lChild != nullptr) {
            stackOfNode.push(root->lChild);
        }

        if (root->rChild != nullptr) {
            stackOfNode.push(root->rChild);
        }
    }

    cout << endl;
}

// 中序遍历
void inOrderUnRecursion(BinaryTree* root) {
    if (root == nullptr) {
        return;
    }

    stack<BinaryTree*> stackOfNode;

    while (root != nullptr || !stackOfNode.empty()) {
        if (root != nullptr) {
            stackOfNode.push(root);
            root = root->lChild;
        } else {
            root = stackOfNode.top();
            cout << root->value << " ";
            stackOfNode.pop();
            root = root->rChild;
        }
    }

    cout << endl;
}

// 后序遍历
void postOrderUnRecursion(BinaryTree* root) {
    if (root == nullptr) {
        return;
    }

    stack<BinaryTree*> stackOfNode1;
    stack<BinaryTree*> stackOfNode2;

    stackOfNode1.push(root);

    while (!stackOfNode1.empty()) {
        root = stackOfNode1.top();
        stackOfNode1.pop();
        stackOfNode2.push(root);

        if (root->lChild != nullptr) {
            stackOfNode1.push(root->lChild);
        }

        if (root->rChild != nullptr) {
            stackOfNode1.push(root->rChild);
        }
    }

    while (!stackOfNode2.empty()) {
        cout << stackOfNode2.top()->value << " ";
        stackOfNode2.pop();
    }

    cout << endl;
}

// 判断是否为搜索二叉树
// 中序遍历
bool isBST_1(const BinaryTree* root) {
    if (root == nullptr) {
        return true;
    }

    stack<const BinaryTree*> stackOfNode;
    long preValue = LONG_MIN;

    while (root != nullptr || !stackOfNode.empty()) {
        if (root != nullptr) {
            stackOfNode.push(root);
            root = root->lChild;
        } else {
            root = stackOfNode.top();
            stackOfNode.pop();

            if (preValue < root->value) {
                preValue = root->value;
            } else {
                return false;
            }

            root = root->rChild;
        }
    }

    return true;
}

// 递归
bool do_isBST(const BinaryTree* root, long min, long max) {
    if (root == nullptr) {
        return true;
    }

    if (root->value <= min || root->value >= max) {
        return false;
    }

    return do_isBST(root->lChild, min, root->value) &&
           do_isBST(root->rChild, root->value, max);
}

bool isBST(const BinaryTree* root) {
    return do_isBST(root, LONG_MIN, LONG_MAX);
}

// 判断是否为完全二叉树
bool isCBT(const BinaryTree* root) {
    if (root == nullptr) {
        return true;
    }

    queue<const BinaryTree*> queueOfNode;
    bool flag = false;  // 是否遇到叶节点

    queueOfNode.push(root);

    while (!queueOfNode.empty()) {
        root = queueOfNode.front();
        queueOfNode.pop();

        if (root == nullptr) {
            flag = true;
        } else {
            if (flag) {
                return false;
            }

            queueOfNode.push(root->lChild);
            queueOfNode.push(root->rChild);
        }
    }

    return true;
}

// 判断是否为满二叉树

/*
判断一个树是否为满二叉树通常需要满足以下两个条件：
1. 每个节点要么是叶子节点，要么有两个子节点。
2. 所有叶子节点都在同一层。
*/

int heightOfBT(const BinaryTree* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(heightOfBT(root->lChild), heightOfBT(root->rChild));
}

bool isFBT(const BinaryTree* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = heightOfBT(root->lChild);
    int rightHeight = heightOfBT(root->rChild);

    return (leftHeight == rightHeight) && isFBT(root->lChild) &&
           isFBT(root->rChild);
}

// 自己的一点想法
bool my_isFBT_2(const BinaryTree* root) {
    if (root == nullptr) {
        return true;
    }

    queue<const BinaryTree*> queueOfNode;
    double preWidth;  // 上一层宽度
    bool flag;        // 检查队列中是否全是空指针

    queueOfNode.push(root);
    preWidth = 0.5;
    flag = false;

    while (!flag) {
        int levelWidth = queueOfNode.size();  // 当前层宽度
        int realWidth = 0;                    // 当前层节点数

        for (int i = 0; i < levelWidth; ++i) {
            root = queueOfNode.front();
            queueOfNode.pop();

            if (root != nullptr) {
                ++realWidth;
                queueOfNode.push(root->lChild);
                queueOfNode.push(root->rChild);
            } else {
                queueOfNode.push(nullptr);
                queueOfNode.push(nullptr);
            }
        }

        if (realWidth != preWidth * 2) {
            return false;
        }

        preWidth = levelWidth;

        queue<const BinaryTree*> temp;

        for (int i = 0; i < levelWidth * 2; ++i) {
            temp.push(nullptr);
        }

        if (temp == queueOfNode) {
            flag = true;
        }
    }

    return true;
}

// 判断是否是平衡二叉树
// 从上向下递归：时间复杂度O(n^2)，因为heightOfBT被反复调用
bool isBBT_1(const BinaryTree* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = heightOfBT(root->lChild);
    int rightHeight = heightOfBT(root->rChild);

    return (abs(leftHeight - rightHeight) <= 1) && isBBT_1(root->lChild) &&
           isBBT_1(root->rChild);
}

// 从下向上递归：时间复杂度O(n)
int height(const BinaryTree* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->lChild);
    int rightHeight = height(root->rChild);

    if (leftHeight == -1 || rightHeight == -1 ||
        abs(leftHeight - rightHeight) > 1) {
        return -1;
    } else {
        return 1 + max(leftHeight, rightHeight);
    }
}

bool isBBT_2(const BinaryTree* root) {
    return height(root) >= 0;
}

// 返回树上两节点的最低公共祖先节点
BinaryTree* LCA(BinaryTree* root,
                const BinaryTree* node1,
                const BinaryTree* node2) {
    if (root == nullptr || root == node1 || root == node2) {
        return root;
    }

    BinaryTree* leftResult = LCA(root->lChild, node1, node2);
    BinaryTree* rightResult = LCA(root->rChild, node1, node2);

    if (leftResult != nullptr && rightResult != nullptr) {
        return root;
    } else if (leftResult != nullptr) {
        return leftResult;
    } else {
        return rightResult;
    }
}

// 返回给定节点的后继节点（中序遍历二叉树中一个节点的下一个节点）
// 已知树的根节点
BinaryTree* successor(BinaryTree* root, const BinaryTree* node) {
    if (root == nullptr) {
        return nullptr;
    }

    stack<BinaryTree*> stackOfNode;
    bool flag = false;  // 是否遇到给定节点

    while (root != nullptr || !stackOfNode.empty()) {
        if (root != nullptr) {
            stackOfNode.push(root);
            root = root->lChild;
        } else {
            root = stackOfNode.top();
            stackOfNode.pop();

            if (flag) {
                return root;
            }

            if (root == node) {
                flag = true;
            }

            root = root->rChild;
        }
    }
    return nullptr;
}

// 不知树的根节点
class TreeNode {
   public:
    int value;
    TreeNode* lChild;
    TreeNode* rChild;
    TreeNode* parent;
    TreeNode(int x)
        : value(x), lChild(nullptr), rChild(nullptr), parent(nullptr) {}
};

TreeNode* findSuccessor(TreeNode* node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->rChild != nullptr) {
        node = node->rChild;

        while (node->lChild != nullptr) {
            node = node->lChild;
        }

        return node;
    }

    while (node->parent != nullptr && node->parent->lChild != node) {
        node = node->parent;
    }

    return node->parent;
}

int main() {
    return 0;
}