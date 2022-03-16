#ifndef	MAP_HELPER_HPP
# define MAP_HELPER_HPP

#include "Node.hpp"


int		balance(int l_h, int r_h) {	return l_h - r_h; }

template< class T, class alloc >
Node<T, alloc >	*most_left(Node<T, alloc>* root)
{
	while (root)
	{
		if (!root->get_left())
			break ;
		root = root->get_left();
	}
	return root;
}

template< class T, class alloc >
Node<T, alloc >	*most_right(Node<T, alloc>* root)
{
	while (root)
	{
		if (!root->get_right())
			break ;
		root = root->get_right();
	}
	return root;
}

template<class T, class alloc>
void	init_heights(Node<T, alloc> *node)
{
	node->set_balance(0);
	node->set_l_h(0);
	node->set_r_h(0);
	// node->get_left()->set_balance(0);
	// node->get_left()->set_l_h(0);
	// node->get_left()->set_r_h(0);
	// node->get_right()->set_balance(0);
	// node->get_right()->set_l_h(0);
	// node->get_right()->set_r_h(0);
}

template<class T, class alloc>
void	left_rotate(Node<T, alloc> **node)
{
	Node<T, alloc> *tmp = *node;
	Node<T, alloc> *tmp1 = tmp->get_right();
	if (!tmp->get_parent())
	{
		tmp->set_parent(tmp1);
		tmp->set_right(NULL);
		tmp1->set_parent(NULL);	
		tmp1->set_left(tmp);
		tmp = *node;
		*node = tmp1;
	}
	else
	{
		if (tmp->get_parent()->get_right() == tmp)
			tmp->get_parent()->set_right(tmp1);
		else
			tmp->get_parent()->set_left(tmp1);
		tmp1->set_parent(tmp->get_parent());
		tmp->set_parent(tmp1);
		tmp->set_right(NULL);
		tmp1->set_left(tmp);
		tmp = *node;
		*node = tmp1;
	}
	(*node)->set_l_h((*node)->get_l_h() + 1);
	init_heights(tmp);
}

template<class T, class alloc>
void	right_rotate(Node<T, alloc> **node)
{
	Node<T, alloc> *tmp = *node;
	Node<T, alloc> *tmp1 = tmp->get_left();
	if (!tmp->get_parent())
	{
		tmp->set_parent(tmp1);
		tmp->set_left(NULL);
		tmp1->set_parent(NULL);	
		tmp1->set_right(tmp);
		init_heights(tmp);
		*node = tmp1;
	}
	else
	{
		if (tmp->get_parent()->get_left() == tmp)
			tmp->get_parent()->set_left(tmp1);
		else
			tmp->get_parent()->set_right(tmp1);
		tmp1->set_parent(tmp->get_parent());
		tmp->set_parent(tmp1);
		tmp->set_left(NULL);
		tmp1->set_right(tmp);
		init_heights(tmp);
		*node = tmp1;
	}
	(*node)->set_r_h((*node)->get_r_h() + 1);
}

template<class T, class alloc>
void	right_left_rotate(Node<T, alloc> **node)
{
	Node<T, alloc> *tmp = *node;
	Node<T, alloc> *tmp1 = tmp->get_right()->get_left();
	Node<T, alloc> *tmp2 = tmp->get_right();

	/*
		tmp -> (A)
				 \
		tmp2->	  (B)
				  /
		tmp1->	(C)
	*/
	if (tmp->get_parent())
	{
		// std::cout << "here" << std::endl;
		if (tmp == tmp->get_parent()->get_left())
			tmp->get_parent()->set_left(tmp1);
		else
			tmp->get_parent()->set_right(tmp1);
	}
	if (tmp1->get_left())
	{
		tmp2->set_left(tmp1->get_left());
		tmp1->get_left()->set_parent(tmp2);
	}
	else if (tmp1->get_right())
	{
		tmp2->set_left(tmp1->get_right());
		tmp1->get_right()->set_parent(tmp2);
	}
	else
	{
		tmp2->set_right(NULL);
		tmp2->set_parent(tmp1);
	}
	tmp1->set_parent(tmp->get_parent());
	tmp2->set_parent(tmp1);
	tmp->set_parent(tmp1);
	tmp1->set_right(tmp2);
	tmp1->set_left(tmp);
	tmp->set_right(NULL);
	// tmp1->get_right()->set_left(NULL);
	init_heights(tmp1->get_right());
	tmp1->get_left()->set_r_h(0);
	tmp1->set_l_h(1);
	tmp1->set_r_h(1);
	*node = tmp1;
}

template<class T, class alloc>
void	left_right_rotate(Node<T, alloc> **node) 
{
	Node<T, alloc> *tmp = *node;
	Node<T, alloc> *tmp1 = tmp->get_left()->get_right();
	Node<T, alloc> *tmp2 = tmp->get_left();

	/*
		tmp ->	 (A) ==> *node
				 /
		tmp2->(B)
				\
		tmp1->	(C)
	*/
	if (tmp->get_parent())
	{
		if (tmp == tmp->get_parent()->get_left())
			tmp->get_parent()->set_left(tmp1);
		else
			tmp->get_parent()->set_right(tmp1);
		tmp1->set_parent(tmp->get_parent());
	}
	if (tmp1->get_left())
	{
		tmp2->set_parent(tmp1->get_left());
		tmp1->get_left()->set_left(tmp2);
	}
	else if (tmp1->get_right())
	{
		tmp1->set_right(tmp);
		tmp->set_left(tmp1->get_right());
		tmp1->get_right()->set_parent(tmp);
		tmp->set_parent(tmp1->get_right());
		tmp2->set_right(NULL);
	}
	else
	{
		tmp2->set_right(NULL);
		tmp2->set_parent(tmp1);
		tmp->set_parent(tmp1);
		tmp1->set_right(tmp);
	}
	// tmp2->set_parent(tmp1);
	tmp1->set_left(tmp2);
	tmp->set_left(NULL);
	init_heights(tmp1->get_left());
	tmp1->get_right()->set_r_h(0);
	tmp1->set_l_h(1);
	tmp1->set_r_h(1);
	*node = tmp1;
}

template<class T, class alloc>
void	rotate(Node<T, alloc> **node , std::string &rot)
{
	std::string LL("LL"), RR("RR"), LR("LR"), RL("RL");
	// node = NULL;
	if (rot.length() > 2)
		rot.erase(0, 1);
	// std::cout << rot << std::endl;
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
		left_right_rotate(node);
	else if (rot == RL)
		right_left_rotate(node);
	rot.clear();
}

template < class T, class alloc>
void	calc_height(Node <T, alloc >** root, Node <T, alloc >** node)
{
	Node<T, alloc> *tmp;
	std::string Rotation;
	int i = 0;

	tmp = (*node)->get_parent();
	while (tmp)
	{
		i++;
		if (*node == tmp->get_left())
		{
			tmp->set_l_h(i);
			// if (Rotation.length() != 2)
				Rotation += "R";
		}
		else
		{
			tmp->set_r_h(i);
			// if (Rotation.length() != 2)
				Rotation += "L";
		}
		tmp->set_balance(ft::balance(tmp->get_l_h() , tmp->get_r_h()));
		if (tmp->get_balance() > 1 || tmp->get_balance() < -1)
		{
			if (*root == tmp)
			{
				rotate(root, Rotation);
				tmp = *root;
			}
			else
				rotate(&tmp, Rotation);
			i--;
		}
		*node = tmp;
		tmp = tmp->get_parent();
	}
}


#endif