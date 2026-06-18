#include <iostream>

constexpr float operator""_Kelvin(unsigned long long k) {
    return static_cast<float>(k - 273.15);
}

constexpr float operator""_Kelvin(long double k) {
    return static_cast<float>(k - 273.15);
}

constexpr float operator""_Fahrenheit(unsigned long long f) {
    return static_cast<float>((f - 32.0) * 5.0 / 9.0);
}

constexpr float operator""_Fahrenheit(long double f) {
    return static_cast<float>((f - 32.0) * 5.0 / 9.0);
}

template <typename T>
class TreeNode {
public:
    T value;
    TreeNode** children;
    int children_count;
    int capacity;
    TreeNode* parent;

    TreeNode(T val, TreeNode* p = nullptr)
        : value(val), children(nullptr), children_count(0), capacity(0), parent(p) {
    }

    ~TreeNode() {
        delete[] children;
    }

    void add_child(TreeNode* child) {
        if (children_count == capacity) {
            capacity = (capacity == 0) ? 2 : capacity * 2;
            TreeNode** new_children = new TreeNode * [capacity];
            for (int i = 0; i < children_count; i++) {
                new_children[i] = children[i];
            }
            delete[] children;
            children = new_children;
        }
        children[children_count++] = child;
        child->parent = this;
    }

    void insert_child(int index, TreeNode* child) {
        if (index < 0 || index > children_count) return;
        if (children_count == capacity) {
            capacity = (capacity == 0) ? 2 : capacity * 2;
            TreeNode** new_children = new TreeNode * [capacity];
            for (int i = 0; i < children_count; i++) {
                new_children[i] = children[i];
            }
            delete[] children;
            children = new_children;
        }
        for (int i = children_count; i > index; i--) {
            children[i] = children[i - 1];
        }
        children[index] = child;
        children_count++;
        child->parent = this;
    }

    void remove_child(TreeNode* child) {
        int index = -1;
        for (int i = 0; i < children_count; i++) {
            if (children[i] == child) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < children_count - 1; i++) {
                children[i] = children[i + 1];
            }
            children_count--;
        }
    }
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;

    TreeNode<T>* find_recursive(TreeNode<T>* current, T value, bool (*cmp)(const T&, const T&)) {
        if (current == nullptr) return nullptr;
        if (cmp(current->value, value)) return current;

        for (int i = 0; i < current->children_count; i++) {
            TreeNode<T>* result = find_recursive(current->children[i], value, cmp);
            if (result != nullptr) return result;
        }
        return nullptr;
    }

    int count_recursive(TreeNode<T>* node) {
        if (node == nullptr) return 0;
        int total = node->children_count;
        for (int i = 0; i < node->children_count; i++) {
            total += count_recursive(node->children[i]);
        }
        return total;
    }

public:
    Tree() : root(nullptr) {}

    TreeNode<T>* add_node(TreeNode<T>* parent, T value) {
        TreeNode<T>* new_node = new TreeNode<T>(value, parent);
        if (parent == nullptr) {
            root = new_node;
        }
        else {
            parent->add_child(new_node);
        }
        return new_node;
    }

    TreeNode<T>* get_node(TreeNode<T>* parent, int index = 0) {
        if (parent == nullptr) {
            return root;
        }
        if (index >= 0 && index < parent->children_count) {
            return parent->children[index];
        }
        return nullptr;
    }

    void delete_node(TreeNode<T>* node) {
        if (node == nullptr) return;

        for (int i = node->children_count - 1; i >= 0; i--) {
            delete_node(node->children[i]);
        }

        if (node->parent != nullptr) {
            node->parent->remove_child(node);
        }
        else if (node == root) {
            root = nullptr;
        }

        delete node;
    }

    TreeNode<T>* find(T value, bool (*cmp)(const T&, const T&)) {
        return find_recursive(root, value, cmp);
    }

    TreeNode<T>* insert(TreeNode<T>* parent, int index, T value) {
        if (parent == nullptr) return nullptr;
        TreeNode<T>* new_node = new TreeNode<T>(value, parent);
        parent->insert_child(index, new_node);
        return new_node;
    }

    void sort(TreeNode<T>* node, bool (*cmp)(const T&, const T&) = nullptr) {
        if (node == nullptr || node->children_count <= 1) return;

        for (int i = 0; i < node->children_count - 1; i++) {
            for (int j = 0; j < node->children_count - i - 1; j++) {
                bool should_swap = false;

                if (cmp != nullptr) {
                    if (cmp(node->children[j + 1]->value, node->children[j]->value)) {
                        should_swap = true;
                    }
                }
                else {
                    if (node->children[j + 1]->value < node->children[j]->value) {
                        should_swap = true;
                    }
                }

                if (should_swap) {
                    TreeNode<T>* temp = node->children[j];
                    node->children[j] = node->children[j + 1];
                    node->children[j + 1] = temp;
                }
            }
        }
    }

    int count(TreeNode<T>* node) {
        if (node == nullptr) {
            return count_recursive(root);
        }
        return count_recursive(node);
    }
};

bool compare_ints(const int& a, const int& b) {
    return a == b;
}

bool sort_descending(const int& a, const int& b) {
    return a > b;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << "\n";
    std::cout << "120 Fahrenheit in Celsius: " << b << "\n\n";

    Tree<int> myTree;

    TreeNode<int>* root = myTree.add_node(nullptr, 10);
    TreeNode<int>* c1 = myTree.add_node(root, 30);
    TreeNode<int>* c2 = myTree.add_node(root, 20);
    TreeNode<int>* c3 = myTree.add_node(root, 40);

    myTree.add_node(c1, 100);
    myTree.add_node(c1, 200);

    std::cout << "Total children from root (nullptr): " << myTree.count(nullptr) << "\n";
    std::cout << "Total children of node c1 (30): " << myTree.count(c1) << "\n";

    TreeNode<int>* fetched = myTree.get_node(root, 1);
    if (fetched) {
        std::cout << "Node at index 1 of root is: " << fetched->value << "\n";
    }

    std::cout << "Inserting 25 at index 1 of root...\n";
    myTree.insert(root, 1, 25);
    std::cout << "New node at index 1 of root is: " << myTree.get_node(root, 1)->value << "\n";

    std::cout << "Sorting children of root (default ascending)...\n";
    myTree.sort(root);
    for (int i = 0; i < root->children_count; i++) {
        std::cout << root->children[i]->value << " ";
    }
    std::cout << "\n";

    std::cout << "Sorting children of root (custom descending)...\n";
    myTree.sort(root, sort_descending);
    for (int i = 0; i < root->children_count; i++) {
        std::cout << root->children[i]->value << " ";
    }
    std::cout << "\n";

    std::cout << "Finding node with value 200...\n";
    TreeNode<int>* found = myTree.find(200, compare_ints);
    if (found) {
        std::cout << "Node found! Value: " << found->value << "\n";
    }

    std::cout << "Deleting node 30 and its children...\n";
    myTree.delete_node(c1);
    std::cout << "Total children from root remaining: " << myTree.count(nullptr) << "\n";

    return 0;
}