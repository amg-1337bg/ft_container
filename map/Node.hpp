#ifndef NODE_HPP
#define NODE_HPP

template <class T, class alloc>
struct Node
{
	private:
		Node *left;
		Node *right;
		Node *parent;
		int	 balancefac;
	public :
		typedef	T	pointer;
		typedef alloc allocator_type;
		typedef typename alloc::reference reference;
		pointer value;
		allocator_type allocator;

		Node() : left(), right(), parent(), balancefac(), value() {}
		Node(const pointer &val) : left(), right(), parent(), balancefac(), value(val) {}
		Node(const Node &cp) : left(cp.left) , right(cp.right), parent(cp.parent), balancefac(cp.balancefac), value(cp.value) {}
		Node	&operator=(const Node &cp)
		{
			left = cp.left;
			right = cp.right;
			parent = cp.parent;
			balancefac = cp.balancefac;
			value = cp.value;
			return *this;
		}

		void	set_left(const Node* l) { left = l; }
		void	set_right(const Node* r) { right = r; }
		void	set_parent(const Node* p) { parent = p; }
		void	set_balance(const Node* b) { balancefac = b; }

		Node*	get_left() const { return left; }
		Node*	get_right() const { return right; }
		Node*	get_parent() const { return parent; }
		int		get_balance() const { return balancefac; }
};

#endif