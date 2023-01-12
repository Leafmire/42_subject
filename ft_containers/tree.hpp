/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:26:39 by gson              #+#    #+#             */
/*   Updated: 2023/01/03 17:52:41 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <sys/_types/_size_t.h>
#include "map_iterator.hpp"
#include "tree_node.hpp"

namespace ft {

template <
    class T,
    class Compare,
    class Node_alloc = std::allocator<NODE<T> >,
    class Type_alloc = std::allocator<T>
>
class RBTree {
    public:
        typedef T           value_type;
        typedef NODE<T>     node_value_type;
	    typedef NODE<T>*    node_pointer;
        typedef Node_alloc  node_alloc;
        typedef Type_alloc  type_alloc;

        typedef ft::MapIterator<NODE<T>, T, Compare>        iterator;
        typedef ft::MapConstIterator<NODE<T>, T, Compare>   const_iterator;

        typedef size_t      size_type;
    
    public:
        size_type    node_num;
        node_pointer root;
        node_pointer nil;
        Compare      _comp;

    public:
        RBTree(const Compare& comp = Compare()) : node_num(0), root(0), nil(0), _comp(comp) {
            nil = _node_alloc.allocate(1);
            _node_alloc.construct(nil, NODE<T>(BLACK));
            nil->l_child = nil->parent = nil;
            nil->r_child = root;
        }

        ~RBTree() {
            _node_alloc.destroy(nil);
            _node_alloc.deallocate(nil, 1);
        }

        node_pointer get_grand_node(node_pointer &cur) {
            return cur->parent->parent;
        }
        node_pointer get_uncle_node(node_pointer &cur) {
            node_pointer tmp = get_grand_node(cur);
            if (tmp == nil) {
                return nil;
            }
            if (cur->parent == tmp->l_child) {
                return tmp->r_child;
            }
            else {
                return tmp->l_child;
            }
        }

        node_pointer get_root() const {
            return this->root;
        }
        node_pointer get_nil() const {
            return this->nil;
        }

        size_type get_node_num() const {
            return this->node_num;
        }

        size_type max_size() const {
            return _node_alloc.max_size();
        };

        size_type height_tree(node_pointer cur) {
            if (cur == nil) {
                return 0;
            }
            size_type l_height;
            if (cur->l_child != nil) {
                l_height = height_tree(cur->l_child) + 1;
            }
            size_type r_height;
            if (cur->r_child != nil) {
                r_height = height_tree(cur->r_child) + 1;
            }
            return (l_height >= r_height ? l_height : r_height);
        }

        void insert_fix(node_pointer & cur) {
            while (cur->parent != nil && cur->parent->color == RED) {
                node_pointer grand = get_grand_node(cur);
                if (cur->parent == grand->l_child) { // 부모가 조부모의 왼쪽 자식
                    node_pointer uncle = get_uncle_node(cur);
                    if (uncle->color == RED) { // 삼촌 노드가 RED : 색 반전
                        cur->parent->color = BLACK;
                        uncle->color = BLACK;
                        grand->color = RED;
                        cur = grand;
                    }
                    else { // 삼촌 노드가 BLACK : 회전
                        if (cur == cur->parent->r_child) {
                            cur = cur->parent;
                            l_rotate(cur);
                        }
                        cur->parent->color = !cur->parent->color;
                        grand->color = !grand->color;
                        r_rotate(grand);
                    }
                }
                else { // 부모가 조부모의 오른쪽 자식
                    node_pointer uncle = get_uncle_node(cur);
                    if (uncle->color == RED) { // 삼촌 노드가 RED : 색 반전
                        cur->parent->color = BLACK;
                        uncle->color = BLACK;
                        grand->color = RED;
                        cur = grand;
                    }
                    else { // 삼촌 노드가 BLACK : 회전
                        if (cur == cur->parent->l_child) {
                            cur = cur->parent;
                            r_rotate(cur);
                        }
                        cur->parent->color = !cur->parent->color;
                        grand->color = !grand->color;
                        l_rotate(grand);
                    }
                }
            }

        }

        ft::pair<iterator, bool> insert_node (value_type const & val) {
            node_pointer parent;
            node_pointer tail;

            parent = nil;
            tail = root;
            if (tail == 0) {
                root = _node_alloc.allocate(1);
                _node_alloc.construct(root, NODE<T>(BLACK, val));
                root->parent = nil;
                root->l_child = nil;
                root->r_child = nil;
                tail = root;
                nil->r_child = root;
            }
            else {
                while (tail != nil) {
                    parent = tail;
                    value_type cur_data = tail->data;
                    if (val.first == cur_data.first) {
                        ft::pair<iterator, bool> ret =  ft::make_pair(iterator(tail, nil), false);
                        return ret;
                    }
                    else if (_comp(val.first, cur_data.first)) {
                        tail = tail->l_child;
                    }
                    else {
                        tail = tail->r_child;
                    }
                }
                tail = _node_alloc.allocate(1);
                _node_alloc.construct(tail, NODE<T>(RED, val));
                tail->parent = parent;
                tail->l_child = nil;
                tail->r_child = nil;
                if (_comp(val.first, parent->data.first)) {
                    parent->l_child = tail;
                }
                else {
                    parent->r_child = tail;
                }
                insert_fix(tail);
            }
            ++node_num;
            
            ft::pair<iterator, bool> ret = ft::make_pair(iterator(serach_tree(val), nil), true);
            return ret;
        }

        void rb_transplant(node_pointer &del_node, node_pointer &successor) {
            if (del_node->parent == nil) {
                root = successor;
                nil->r_child = root;
            }
            else if (del_node == del_node->parent->l_child) {
                del_node->parent->l_child = successor;
            }
            else {
                del_node->parent->r_child = successor;
            }
            successor->parent = del_node->parent;
        }

        void del_fix(node_pointer & node) {
            node_pointer sibling = nil;
            while (node != root && node->color == BLACK) {
                if (node == node->parent->l_child) { // 현재 노드가 왼쪽 자식
                    sibling = node->parent->r_child;
                    if (sibling->color == RED) { // CASE 1
                        sibling->color = BLACK;
                        node->parent->color = RED;
                        l_rotate(node->parent);
                        sibling = node->parent->r_child;
                    }
                    if (sibling->l_child->color == BLACK && sibling->r_child->color == BLACK) { // CASE 2
                        sibling->color = RED;
                        node = node->parent;
                    }
                    else {
                        if (sibling->r_child->color == BLACK) { // CASE 3
                            sibling->l_child->color = BLACK;
                            sibling->color = RED;
                            r_rotate(sibling);
                            sibling = node->parent->r_child;
                        }
                        sibling->color = node->parent->color; // CASE 4
                        node->parent->color = BLACK;
                        sibling->r_child->color = BLACK;
                        l_rotate(node->parent);
                        node = root;
                    }
                }
                else { // 현재 노드가 오른쪽 자식
                    sibling = node->parent->l_child;
                    if (sibling->color == RED) { // CASE 1
                        sibling->color = BLACK;
                        node->parent->color = RED;
                        r_rotate(node->parent);
                        sibling = node->parent->l_child;
                    }
                    if (sibling->l_child->color == BLACK && sibling->r_child->color == BLACK) { // CASE 2
                        sibling->color = RED;
                        node = node->parent;
                    }
                    else {
                        if (sibling->l_child->color == BLACK) { // CASE 3
                            sibling->r_child->color = BLACK;
                            sibling->color = RED;
                            l_rotate(sibling);
                            sibling = node->parent->l_child;
                        }
                        sibling->color = node->parent->color; // CASE 4
                        node->parent->color = BLACK;
                        sibling->l_child->color = BLACK;
                        r_rotate(node->parent);
                        node = root;
                    }
                }
            }
            node->color = BLACK;
        }

        void delete_node(value_type const & val) {
            node_pointer del_node = this->serach_tree(val);
            if (del_node == nil) {
                return ;
            }

            node_pointer y = del_node;
            int origin_color = y->color;
            node_pointer successor = nil;


            if (del_node->l_child == nil) {
                successor = del_node->r_child;
                rb_transplant(del_node, del_node->r_child);
            }
            else if (del_node->r_child == nil) {
                successor = del_node->l_child;
                rb_transplant(del_node, del_node->l_child);
            }
            else {
                y = left_maximum(del_node->r_child);
                origin_color = y->color;
                successor = y->r_child;
                if (y->parent == del_node) {
                    successor->parent = y;
                }
                else {
                    rb_transplant(y, y->r_child);
                    y->r_child = del_node->r_child;
                    y->r_child->parent = y;
                }
                rb_transplant(del_node, y);
                y->l_child = del_node->l_child;
                y->l_child->parent = y;
                y->color = del_node->color;
            }
            if (origin_color == BLACK) {
                del_fix(successor);
            }
            _node_alloc.destroy(del_node);
            _node_alloc.deallocate(del_node, 1);
            --node_num;
        }

        node_pointer left_maximum(node_pointer &cur) {
            node_pointer p = cur;
            while (p->l_child != nil) {
                p = p->l_child;
            }
            return p;
        }

        node_pointer find_successor(node_pointer & delnode) {
            if (delnode->l_child == nil) {
                return delnode->r_child;
            }
            else {
                return delnode->l_child;
            }
        }


        node_pointer serach_tree(value_type const & val) const {
            node_pointer tmp = root;
            if (tmp == 0)
                return nil;
            while (tmp != nil) {
                if (_comp(val.first, tmp->data.first)) {
                    tmp = tmp->l_child;
                }
                else if (val.first == tmp->data.first) {
                    return tmp;
                }
                else {
                    tmp = tmp->r_child;
                }
            }
            return nil;
        }

        void clear_tree(node_pointer node) {
            if (node == nil || node_num == 0)
                return ;
            clear_tree(node->l_child);
            clear_tree(node->r_child);

            _node_alloc.destroy(node);
            _node_alloc.deallocate(node, 1);
            --node_num;
            if (node_num == 0) {
                root = 0;
                nil->r_child = root;
            }
        }

        void swap(RBTree & tree) {
            if (this == &tree)
                return ;
            node_pointer copy_root = tree.root;
            node_pointer copy_nil = tree.nil;
            tree.root = this->root;
            tree.nil = this->nil;
            this->root = copy_root;
            this->nil = copy_nil;

            size_type tmp_num = tree.node_num;
            tree.node_num = this->node_num;
            this->node_num = tmp_num;
        }

        void printBT(const std::string& prefix, node_pointer node, bool isLeft)
        {
            if( node != nil )
            {
                std::cout << prefix;

                std::cout << (isLeft ? "├──" : "└──" );

                // print the value of the node
                std::cout << node->data.first << std::endl;

                // enter the next tree level - left and right branch
                printBT( prefix + (isLeft ? "│   " : "    "), node->l_child, true);
                printBT( prefix + (isLeft ? "│   " : "    "), node->r_child, false);
            }
        }

        void printBT()
        {
            printBT("", root, false);    
        }

    private:
        void l_rotate(node_pointer &cur) {

            if (cur == nil || cur->r_child == nil) {
                return ;
            }

            node_pointer tmp = cur->r_child;
            node_pointer l = tmp->l_child;

            l->parent = cur;
            cur->r_child = l;

            if (cur->parent == nil) {
                this->root = tmp;
            }
            else if (cur->parent->l_child == cur) {
                cur->parent->l_child = tmp;
            }
            else {
                cur->parent->r_child = tmp;
            }
            tmp->parent = cur->parent;

            tmp->l_child = cur;
            cur->parent = tmp;
            nil->r_child = root;
        }

        void r_rotate(node_pointer &cur) {
            if (cur == nil || cur->l_child == nil) {
                return ;
            }

            node_pointer tmp = cur->l_child;
            node_pointer r = tmp->r_child;
    
            r->parent = cur;
            cur->l_child = r;

            
            if (cur->parent == nil) {
                this->root = tmp;
            }
            else if (cur->parent->l_child == cur) {
                cur->parent->l_child = tmp;
            }
            else {
                cur->parent->r_child = tmp;
            }
            tmp->parent = cur->parent;

            tmp->r_child = cur;
            cur->parent = tmp;
            nil->r_child = root;
        }

    private:
        node_alloc   _node_alloc;
        type_alloc   _type_alloc;

};

}



#endif