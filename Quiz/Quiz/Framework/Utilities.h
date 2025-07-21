#pragma once

#define INT(c) static_cast<int>(c - '0')

template<typename T, size_t N>
struct NDimVector {
	using type = std::vector<typename NDimVector<T, N - 1>::type>;
};

// 1차원 벡터의 특수화
template<typename T>
struct NDimVector<T, 1> {
	using type = std::vector<T>;
};

// n차원 벡터를 생성하는 함수
template<typename T, size_t N>
typename NDimVector<T, N>::type createNDimVector(const std::vector<size_t>& dims, size_t dimIndex = 0) {
	typename NDimVector<T, N>::type vec(dims[dimIndex]);
	if constexpr (N > 1) {
		for (auto& subVec : vec) {
			subVec = createNDimVector<T, N - 1>(dims, dimIndex + 1);
		}
	}
	return vec;
}

template<typename T>
void* To_Array(string target)
{
	string aElem;
	vector<string> Elems;
	int depth = 0, index = 0;

	while (true)
	{
		char c = target[index];
		switch (c)
		{
		case '[':
		case '{':
		case '(':
		{
			depth++;
		}
		default:
			break;
		}
		index++;
	}

	//auto vec = createNDimVector<T, depth>()

	int maxDepth = depth;
	vector<size_t> dims(maxDepth, 0);

	while (depth != 0)
	{
		char c = target[index];

		switch (c)
		{
		case '[':
		case '{':
		case '(':
		{
			depth++;
		}

		case ',':
		case ']':
		case '+':
		case ')':
		{
			if (c == ',') {}
			else
			{
				depth--;
				depth > 0 ? dims[depth - 1]++;
			}

			
		}



		default:
			aElem += target[index];
		}

	}

	auto vec3D = createNDimVector<T, maxDepth>(dims);

	for (size_t i = 0; i < dims; ++i) {
		for (size_t j = 0; j < ; ++j) {
			for (size_t k = 0; k < 4; ++k) {
				vec3D[i][j][k] = i * 12 + j * 4 + k;
				std::cout << vec3D[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return nullptr;

}