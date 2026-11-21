// C++

class NumArray {
public:

    struct Node {
        int sum;
        Node* left;
        Node* right;

        Node() : sum(0), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int n;

    NumArray(vector<int>& nums) : root(nullptr), n(nums.size()) {
        if (n > 0) {
            root = buildST(nums, 0, n - 1);
        }
    }

    // Build the segment tree
    Node* buildST(vector<int>& nums, int s, int e) {
        Node* newNode = new Node();

        // Leaf node
        if (s == e) {
            newNode->sum = nums[s];
            return newNode;
        }

        int mid = s + (e - s) / 2;

        newNode->left = buildST(nums, s, mid);
        newNode->right = buildST(nums, mid + 1, e);

        newNode->sum = newNode->left->sum + newNode->right->sum;
        return newNode;
    }

    // Update an element
    void update(int index, int val) {
        updateUtil(index, val, 0, n - 1, root);
    }

    void updateUtil(int index, int val, int s, int e, Node* currNode) {
        if (s == e) {
            currNode->sum = val;
            return;
        }

        int mid = s + (e - s) / 2;

        if (index <= mid) {
            updateUtil(index, val, s, mid, currNode->left);
        } else {
            updateUtil(index, val, mid + 1, e, currNode->right);
        }

        // Recalculate parent sum
        currNode->sum = currNode->left->sum + currNode->right->sum;
    }

    // Query the sum of [left, right]
    int sumRange(int left, int right) {
        return sumUtil(left, right, 0, n - 1, root);
    }

    int sumUtil(int qs, int qe, int s, int e, Node* currNode) {
        // No overlap
        if (e < qs || s > qe) {
            return 0;
        }

        // Complete overlap
        if (qs <= s && e <= qe) {
            return currNode->sum;
        }

        // Partial overlap
        int mid = s + (e - s) / 2;

        int leftSum = sumUtil(qs, qe, s, mid, currNode->left);
        int rightSum = sumUtil(qs, qe, mid + 1, e, currNode->right);

        return leftSum + rightSum;
    }

    // Free dynamically allocated nodes
    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    ~NumArray() {
        destroy(root);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */