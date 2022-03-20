#ifndef NODE_HPP
#define NODE_HPP

template <class T, class alloc>
struct Node
{
	private:
		Node *left;
		Node *right;
		Node *parent;
		int	 balancefac, l_h, r_h;
	public :
		typedef	T	pointer;
		typedef alloc allocator_type;
		typedef typename alloc::reference reference;
		pointer value;
		allocator_type allocator;

		Node() : left(), right(), parent(), balancefac(), l_h(), r_h(), value() {}
		Node(const pointer &val) : left(), right(), parent(), balancefac(), l_h(), r_h(), value(val) {}
		Node(const Node &cp) : left(cp.left) , right(cp.right), parent(cp.parent), balancefac(cp.balancefac), l_h(cp.l_h), r_h(cp.r_h), value(cp.value) {}
		Node	&operator=(const Node &cp)
		{
			left = cp.left;
			right = cp.right;
			parent = cp.parent;
			balancefac = cp.balancefac;
			value = cp.value;
			return *this;
		}
		~Node(){}

		void	set_left(Node* l) { left = l; }
		void	set_right(Node* r) { right = r; }
		void	set_parent(Node* p) { parent = p; }
		void	set_balance(int i) { balancefac = i; }
		void	set_l_h(int i) { l_h = i; }
		void	set_r_h(int i) { r_h = i; }

		Node*	get_left() const { return left; }
		Node*	get_right() const { return right; }
		Node*	get_parent() const { return parent; }
		int		get_balance() const { return balancefac; }
		int		get_l_h() const { return l_h; }
		int		get_r_h() const	{ return r_h;}


		Node& operator++()
		{
			Node	*ret;
			std::cout << "this = " << parent->left << std::endl; 
			if (right)
				ret = most_left(right);
			else if (parent && parent->left == this)
				ret = parent;
			else if (parent && parent->parent)
				ret = parent->parent;
			else
				ret = NULL;
			return *ret;
		}
};

#endif