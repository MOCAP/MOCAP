using namespace std;

template <class T>	
class DH_Node
{
/* TODO
Add accesors for the params when automatic limb length detection as added
*/
public:
	DH_node();
	DH_node(T a,T alpha, T d, T theta); 
	DH_node * get_parent();
	DH_node * get_children();
	T get_a();
	T get_alpha():
	T get_d();
	T get_theta();
	int update_d(T d);
	int update_theta(T theta);
	
	
	/*
	Simple node types denote the usage of an intermediate joint that has fixed parameters 
	*/
	enum DH_node_type{prismatic, revolute, simple}
	
	
private:

	/*
	a is link length - distance between Z0 and Z1 measured along X1
	alpha is link twist - angle from Z0 to Z1, measured about X1 
	d is link offset - distance from origin O0 to intersection of X1 and Z0
	theta is joint angle - angle from X0 to X1, measured about Z0
	*/
	
	T a;
	T alpha; 
	T d;
	T theta;
	DH_node_type node_type;
	DH_node * parent; 
	DH_node * children; 
	int Update_children();
};

