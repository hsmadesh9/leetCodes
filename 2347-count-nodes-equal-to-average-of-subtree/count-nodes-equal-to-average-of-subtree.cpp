class Solution {
public:
    struct P {
        int s{}, c{};
        inline void add(P x) {
            s += x.s;
            c += x.c;
        }
    };
    int averageOfSubtree(TreeNode* x) {
        int r = 0;
        [&r](this auto&& f, TreeNode* x) -> P {
            P p{};
            if (x) {
                p.add(P{x->val, 1});
                p.add(f(x->left));
                p.add(f(x->right));
                r += ((p.s / p.c) == x->val);
            }
            return p;
        }(x);
        return r;
    }
};