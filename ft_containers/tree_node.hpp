/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:11:47 by gson              #+#    #+#             */
/*   Updated: 2022/12/30 23:26:42 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <iostream>
#include <string>

namespace ft {

enum color { RED, BLACK };

template<class T>
  class NODE
  {
      public :
        typedef T       value_type;
      
      public :
        value_type      data;
        NODE<T>         *l_child;
        NODE<T>         *r_child;
        NODE<T>         *parent;
        int             color;

      public :
          NODE() : data(0), l_child(0), r_child(0), parent(0), color(0)
          {}
          NODE(int color, const value_type& val = value_type()) : data(val), l_child(0), r_child(0), parent(0), color(color)
          {}
          NODE(const NODE& node) : data(node.data), l_child(node.l_child), r_child(node.r_child), parent(node.parent), color(node.color)
          {}
          virtual ~NODE(){};
          NODE& operator=(const NODE& node)
          {
            data = node.data;
            l_child = node.l_child;
            r_child = node.r_child;
            parent = node.parent;
            return *this;
          }

  };
  template<class T>
  bool  operator== (const NODE<T>&lhs, const NODE<T>&rhs)
  {
    if (lhs->data == 0 && rhs->data == 0)
      return true;
    return (lhs->data == rhs.data);
  }
  template<class T>
  bool operator!=(const NODE<T>&lhs, const NODE<T>&rhs)
  {
    return (!(lhs == rhs));
  }
  template <class T>
  struct less : std::binary_function<T,T,bool>
  {
    bool operator() (const T& x, const T& y) const
    {
      return (x < y);
    }
  };
}

#endif
