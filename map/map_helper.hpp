#ifndef	MAP_HELPER_HPP
# define MAP_HELPER_HPP

#include "Node.hpp"
int		balance(int l_h, int r_h) {	return l_h - r_h; }

template< class T, class alloc >
Node<T, alloc >	*most_left(Node<T, alloc>* root)
{
	while (root)
	{
		if (!root->left)
			break ;
		root = root->left;
	}
	return root;
}

template < class T, class alloc>
void	calc_height(Node <T, alloc >* node)
{
	Node<T, alloc> *tmp;
	int i = 0;
	tmp = node->get_parent();
	while (tmp)
	{
		i++;
		if (node == tmp->get_left())
			tmp->set_l_h(i);
		else
			tmp->set_r_h(i);
		// std::cout << "key = " << tmp->value->first << " and lh " << tmp->get_l_h() << " and r_h " << tmp->get_r_h() << std::endl;
		tmp->set_balance(ft::balance(tmp->get_l_h() , tmp->get_r_h()));
		node = tmp;
		tmp = tmp->get_parent();
	}
}


#endif