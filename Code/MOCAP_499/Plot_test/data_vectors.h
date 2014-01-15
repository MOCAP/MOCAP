#ifndef data_vectors_H
#define data_vectors_H

#include <vector>

class data_vectors {
public:
	std::vector<float> * x_values;
	std::vector<float> * y_values;
	std::vector<float> * z_values;

	data_vectors();
};


#endif