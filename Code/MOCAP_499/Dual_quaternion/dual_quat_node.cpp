#include "dual_quat_Node.h"

namespace mocap_support
{

template <class T>
dual_quat_Node::dual_quat_Node()
{
}

template <class T>
dual_quat_Node::dual_quat_Node( vector<T> screw_axis, T d, T theta,joint_type node_type)
{
	this.screw_axis = screw_axis; 
	this.d = d;
	this.thetha = theta;
	this.node_type = node_type;
	this.children = new dual_quat_Node[0];
	
	this.parent = new dual_quat_Node();
}

template <class T> 
dual_quat_Node::dual_quat_Node(T a, T alpha, T d, T theta,joint_type node_type, dual_quat_Node * parent)
{
	this.screw_axis = screw_axis; 
	this.d = d;
	this.thetha = theta;
	this.node_type = node_type;
	this.children = new dual_quat_Node[0];
	
	this.parent = parent;
}

template <class T>
 dual_quat_Node * dual_quat_Node::get_parent()
 {
	return parent;
 }

template <class T>
dual_quat_Node * dual_quat_Node::get_children()
{
	return children;
} 

template <class T>
 vector<T> dual_quat_Node::get_screw_axis()
 {
	return screw_axis;
 }

template <class T>
 T dual_quat_Node::get_d()
 {
	return d;
 }
template <class T>
 T dual_quat_Node::get_theta()
 {
	return theta;
 } 
 
 
/*
use a set_d function to change the d value in all other cases,
this is only for prismatic joints, which don't even exist in this project
*/
template <class T>
int dual_quat_Node::update_d(T d)
 {
	if(node_type == DH_node_type.prismatic)
	{
		this.d = d;
		return Update_children();
	} else {
		return -1;
	}
 }

template <class T> 
int dual_quat_Node::update_theta(T theta)
 {
	if( node_type == DH_node_type.revolute)
	{
		this.theta = theta;
		return Update_children();
	} else {
		return -1;
	}
	
 } 
 
template <class T>
int dual_quat_Node::update_screw_axis(vector<T> screw_axis)
 {
	this.screw_axis = screw_axis;
	return Update_children();
 } 
 
 
template <class T>
 int Update_children()
 {
	return 0;
 }
 
 }