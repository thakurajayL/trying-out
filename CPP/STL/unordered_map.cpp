#include <iostream>
#include <unordered_map>
#include <utility>

template<typename T0, typename T1, typename T2>
struct Node
{
    T0 id;
	T1 x;
	T2 y;

	// constructor
	Node(T0 id, T1 x, T2 y)
	{
		this->id = id;
		this->x = x;
		this->y = y;
	}

	// operator== is required to compare keys in case of hash collision
	bool operator==(const Node &p) const
	{
		return x == p.x && y == p.y && id == p.id;
	}
};

// specialized hash function for unordered_map keys
struct hash_fn
{
	template <class T0, class T1, class T2>
	std::size_t operator() (const Node<T0, T1, T2> &node) const
	{
		std::size_t h1 = std::hash<T1>()(node.x);
		std::size_t h2 = std::hash<T2>()(node.y);
		std::size_t h3 = std::hash<T0>()(node.id);

		return h1 ^ h2 ^ h3;
	}
};

int main()
{
	std::unordered_map<Node<int, std::string,std::string>, int, hash_fn> u_map =
	{
		{{1, "C", "C99"}, 1999},
		{{5, "C", "C99"}, 1999},
		{{2, "C", "C11"}, 2011},
		{{3, "C++", "C++14"}, 2014},
		{{4, "C++", "C++17"}, 2017},
		{{5, "Java", "Java SE 8"}, 2014},
		{{6, "Java", "Java SE 9"}, 2017}
	};
    struct Node<int,std::string, std::string>  n1 = {7, "ajay", "Java SE 9"};
    auto p = std::make_pair(n1, 1981);
    u_map.insert(p);

	for (const auto &entry: u_map)
	{
		std::cout << "{" << entry.first.id<< ","<<entry.first.x << "," << entry.first.y << "}: "
				  << entry.second << '\n';
	}

    struct Node<int,std::string, std::string>  s1 = {7, "ajay", "Java SE 9"};
    auto it = u_map.find(s1);
    if(it != u_map.end())
    {
        //std::cout<<"Found ... "<<it.first.id<<","<<it.first.x<<","<<it.first.y<<std::endl;
        std::cout<<"found "<<it->first.id<<std::endl;
        u_map.erase(it);
        for (const auto &entry: u_map)
        {
            std::cout << "{" << entry.first.id<< ","<<entry.first.x << "," << entry.first.y << "}: "
                << entry.second << '\n';
        }
    }
    else
    {
        std::cout<<"Not found "<<std::endl;
    }

	return 0;
}
