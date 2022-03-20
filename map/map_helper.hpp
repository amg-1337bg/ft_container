#ifndef	MAP_HELPER_HPP
# define MAP_HELPER_HPP

#include "Node.hpp"


int		balance(int l_h, int r_h) {	return l_h - r_h; }

template< class T, class alloc >
int height(Node<T, alloc>* root) {
   int h = 0;

   if (root != NULL) {
    	int l = height(root->get_left());
    	int r = height(root->get_right());
    	int max = std::max(l, r);
    	h = max + 1;
   }
   return h;
}

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

template< class T, class alloc >
Node<T, alloc >	*left_child_occur(Node<T, alloc>* node)
{
	Node<T, alloc >	*tmp = node;
	node = tmp->get_parent();
	while(node)
	{
		if (node->get_left() == tmp)
			return node;
		tmp = node;
		node = node->get_parent();
	}
	return node;
}

template<class T, class alloc>
void	set_to_left(Node<T, alloc> *parent, Node<T, alloc> *child)
{
	parent->set_left(child);
	child->set_parent(parent);
}

template<class T, class alloc>
void	set_to_right(Node<T, alloc> *parent, Node<T, alloc> *child)
{
	parent->set_right(child);
	child->set_parent(parent);
}

template<class T, class alloc>
void	set_to_parent(Node<T, alloc> *parent, Node<T, alloc> *child, bool left_right)
{
	if (left_right)
		parent->set_right(child);
	else
		parent->set_left(child);
	child->set_parent(parent);
}

template<class T, class alloc>
void	left_rotate(Node<T, alloc> **node)
{
	Node<T, alloc> *tmp = *node;
	Node<T, alloc> *tmp1 = tmp->get_left();

	/*
		tmp -> (*node)
				/
			   /
		tmp1->(B)
			 /
			/
		  (C)
	*/
	if (tmp1->get_right())
		set_to_left(tmp, tmp1->get_right());
	else
		tmp->set_left(NULL);
	if (tmp->get_parent())
	{
		if (tmp == tmp->get_parent()->get_left())
			set_to_parent(tmp->get_parent(), tmp1, false);
		else
			set_to_parent(tmp->get_parent(), tmp1, true);
	}
	else
		tmp1->set_parent(NULL);
	set_to_right(tmp1, tmp);
	*node = tmp1;
}

template<class T, class alloc>
void	right_rotate(Node<T, alloc> **node)
{
	Node<T, alloc> *tmp = *node;
	Node<T, alloc> *tmp1 = tmp->get_right();
	
	/*
		tmp -> (*node)
					\
					 \
			tmp1 -> (B)
			 		  \
					   \
					   (C)
	*/
	if (tmp1->get_left())
		set_to_right(tmp, tmp1->get_left());
	else
		tmp->set_right(NULL);
	if (tmp->get_parent())
	{
		if (tmp == tmp->get_parent()->get_left())
			set_to_parent(tmp->get_parent(), tmp1, false);
		else
			set_to_parent(tmp->get_parent(), tmp1, true);
	}
	else
		tmp1->set_parent(NULL);
	set_to_left(tmp1, tmp);
	*node = tmp1;
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
	if (tmp1->get_left())
		set_to_right(tmp, tmp1->get_left());
	else
		tmp->set_right(NULL);
	if (tmp1->get_right())	
		set_to_left(tmp2, tmp1->get_right());
	else
		tmp2->set_left(NULL);
	if (tmp->get_parent())
	{
		if (tmp == tmp->get_parent()->get_left())
			set_to_parent(tmp->get_parent(), tmp1, false);
		else
			set_to_parent(tmp->get_parent(), tmp1, true);
	}
	else
		tmp1->set_parent(NULL);
	set_to_left(tmp1, tmp);
	set_to_right(tmp1, tmp2);
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
	// std::cout << "goo " << tmp->value->first << std::endl;
	if (tmp1->get_right())
		set_to_left(tmp, tmp1->get_right());
	else
		tmp->set_left(NULL);
	if (tmp1->get_left())
		set_to_right(tmp2, tmp1->get_left());
	else
		tmp2->set_right(NULL);
	if (tmp->get_parent())
	{
		if (tmp == tmp->get_parent()->get_left())
			set_to_parent(tmp->get_parent(), tmp1, false);
		else
			set_to_parent(tmp->get_parent(), tmp1, true);
	}
	else
		tmp1->set_parent(NULL);
	set_to_left(tmp1, tmp2);
	set_to_right(tmp1, tmp);
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
		right_rotate(node);
	else if (rot == RR)
		left_rotate(node);
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
	// int i = 0;

	tmp = (*node)->get_parent();
	while (tmp)
	{
		tmp->set_l_h(height(tmp->get_left()));
		tmp->set_r_h(height(tmp->get_right()));
		if (*node == tmp->get_left())
				Rotation += "R";
		else
				Rotation += "L";
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
			// break ;
		}
		*node = tmp;
		tmp = tmp->get_parent();
	}
}
template < class T, class alloc>
void	calc_after_delete(Node <T, alloc >** root, Node <T, alloc >* node)
{
	std::string Rotation;
	while (node)
	{
		node->set_l_h(height(node->get_left()));
		node->set_r_h(height(node->get_right()));
		node->set_balance(ft::balance(node->get_l_h() , node->get_r_h()));
		if (node->get_balance() > 1 || node->get_balance() < -1)
		{
			if (node->get_l_h() > node->get_r_h())
			{
				if (node->get_left() && node->get_left()->get_left())
					Rotation = "RR";
				else
					Rotation = "LR";
			} else
			{
				if (node->get_right() && node->get_right()->get_right())
					Rotation = "LL";
				else
					Rotation = "RL";
			}
			if (*root == node)
			{
				rotate(root, Rotation);
				node = *root;
			}
			else
				rotate(&node, Rotation);
			// break ;
		}
		node = node->get_parent();
	}
}
template < class T, class alloc>
void	delete_node(Node <T, alloc >** root, Node <T, alloc >* node)
{
	Node<T, alloc> *parent = node->get_parent();
	if (parent == NULL)
		return ;
	if (!node->get_left() && !node->get_right()) // Node without child
	{
		if (parent->get_right() == node)
			parent->set_right(NULL);
		else
			parent->set_left(NULL);
		delete node;
		calc_after_delete(root, parent);
	}
	else if ( (node->get_left() && !node->get_right()) || (!node->get_left() && node->get_right()) ) //Node with One Child
	{
		if (node->get_left())
		{
			if (parent->get_left() == node)
				set_to_left(parent, node->get_left());
			else
				set_to_right(parent, node->get_left());
		}
		else
		{
			if (parent->get_left() == node)
				set_to_left(parent, node->get_right());
			else
				set_to_right(parent, node->get_right());
		}
		calc_after_delete(root, parent);
	}
	else
	{
		Node<T, alloc> *most_r, *most_r_parent;
		*most_r = most_right(tmp->get_left());
		*most_r_parent = *most_r->get_parent();
		set_to_right(most_r_parent, most_r->get_left());
		if (parent->get_left() == node)
			set_to_left(parent, most_r)
		else
			set_to_right(parent, most_r);
		set_to_right(most_r, node->get_right());
		delete node;
		calc_after_delete(root, most_r_parent);
	}
}


#endif