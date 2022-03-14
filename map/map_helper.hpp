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
template<class T, class alloc>
void	init_heights(Node<T, alloc> *node)
{
	node->set_balance(0);
	node->set_l_h(0);
	node->set_r_h(0);
	node->get_left()->set_balance(0);
	node->get_left()->set_l_h(0);
	node->get_left()->set_r_h(0);
	node->get_right()->set_balance(0);
	node->get_right()->set_l_h(0);
	node->get_right()->set_r_h(0);
}

template<class T, class alloc>
void	left_rotate(Node<T, alloc> **node)
{
	Node<T, alloc> *tmp = *node;
	Node<T, alloc> *tmp1 = tmp->get_right();
	if (!tmp->get_parent())
	{
		tmp->set_parent(tmp1);
		tmp1->set_parent(nullptr);	
		tmp1->set_left(tmp);
		*node = tmp1;
	}
	else
	{
		tmp1->set_parent(tmp->get_parent());
		tmp->set_parent(tmp1);
		tmp1->set_left(tmp);
		*node = tmp1;
	}
	init_heights(*node);
}

template<class T, class alloc>
void	right_rotate(Node<T, alloc> **node)
{
	Node<T, alloc> *tmp = *node;
	Node<T, alloc> *tmp1 = tmp->get_left();
	if (!tmp->get_parent())
	{
		tmp->set_parent(tmp1);
		tmp1->set_parent(nullptr);	
		tmp1->set_right(tmp);
		*node = tmp1;
	}
	else
	{
		std::cout << "tmp1 = " << tmp1->value->first << std::endl;
		std::cout << "tmp parent = " << tmp->get_parent()->value->first << std::endl;
		tmp1->set_parent(tmp->get_parent());
		tmp->set_parent(tmp1);
		tmp1->set_right(tmp);
		*node = tmp1;
	}
	init_heights(*node);
}


template<class T, class alloc>
void	rotate(Node<T, alloc> **node , std::string &rot)
{
	std::string LL("LL"), RR("RR"), LR("LR"), RL("RL");
	// node = nullptr;
	std::cout << rot << std::endl;
	if (rot.empty())
	{
		std::cout << "Rot empty" << std::endl;
		return ;
	}
	if (rot == LL)
		left_rotate(node);
	else if (rot == RR)
		right_rotate(node);
	else if (rot == LR)
		std::cout << "Left right rotation" << std::endl;
	else if (rot == RL)
		std::cout << "Right Left rotation" << std::endl;
	rot.clear();
}

template < class T, class alloc>
void	calc_height(Node <T, alloc >** root, Node <T, alloc >** node)
{
	Node<T, alloc> *tmp, *tmp1;
	std::string Rotation;
	int i = 0;

	tmp = (*node)->get_parent();
	tmp1 = (*node)->get_parent();
	while (tmp)
	{
		i++;
		if (*node == tmp->get_left())
		{
			tmp->set_l_h(i);
			if (Rotation.length() != 2)
				Rotation += "R";
		}
		else
		{
			tmp->set_r_h(i);
			if (Rotation.length() != 2)
				Rotation += "L";
		}
		tmp->set_balance(ft::balance(tmp->get_l_h() , tmp->get_r_h()));
		// std::cout << "key = " << tmp->value->first << " and lh " << tmp->get_l_h() << " and r_h " << tmp->get_r_h() << " Rot = " << Rotation << std::endl;
		// if (tmp->get_balance() > 1 || tmp->get_balance() < -1)
		// {
		// 	std::cout << " key = " << tmp->value->first << " balance = " << tmp->get_balance() << std::endl;
		// 	if (*root == tmp)
		// 		rotate(root, Rotation);
		// 	else
		// 		rotate(&tmp, Rotation);
		// }
		// else
		*node = tmp;
		tmp = tmp->get_parent();
	}
	while (tmp1)
	{
		if (tmp1->get_balance() > 1 || tmp1->get_balance() < -1)
		{
			// std::cout << "key = " << tmp1->value->first << " balance = " << tmp1->get_balance() << std::endl;
			if (*root == tmp1)
				rotate(root, Rotation);
			else
				rotate(&tmp1, Rotation);
		}
		tmp1 = tmp1->get_parent();
	}
}


#endif