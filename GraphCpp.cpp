#include <iostream>

namespace whoamifk_graph {
    template<typename T>
    struct adjNode {
        T _val;
        size_t _cost;
        adjNode* _next;
    };
    template<typename T>
    struct graphEdge {
        T _start_ver;
        T _end_ver;
        int _weight;
    };

    template<typename T, class _Alloc=std::allocator<T>>
    class Graph {
    public:
        typedef T** root;
        typedef _Alloc _allocator_type;
        typedef Graph<T, _Alloc> _graph;
        Graph() 
            : _nodes(0),_head(nullptr)
        {

        }
        Graph(graphEdge<T> edges[], size_t _num_of_edges, size_t nodes)
            : _nodes(nodes)
        {

        }
    private:
        root _head;
        size_t _nodes;
   
    };
}

int main()
{
    std::cout << "Hello World!\n";
}
