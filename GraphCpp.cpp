#include <iostream>

namespace whoamifk_graph {
    template<typename T>
    struct adjNode {
        T _val;
        size_t _cost;
        adjNode* _next;
        adjNode(T val, size_t cost, adjNode* node=nullptr)
            :_val(val),_cost(cost),_next(node)
        {
        }
    };
    template<typename T>
    struct graphEdge {
        T _start_ver;
        T _end_ver;
        size_t _weight;
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
            _head = new adjNode*[nodes]();
            for (size_t i = 0; i < nodes; ++i) _head[i] = nullptr;
            for (size_t i = 0; i < _num_of_edges; ++i) {
                adjNode* newNode = getAdjListNode(edges[i]._end_ver, edges[i]._weight, _head[edges[i]._start_ver]);
                _head[edges[i]._start_ver] = newNode;
            }
        }
        ~Graph() {
            for (int i = 0; i < _nodes; ++i) {
                delete[] _head[i];
            }
            delete[] _head;
        }
    private:
        root _head;
        size_t _nodes;
        adjNode<T>* getAdjListNode(T value, size_t cost, adjNode<T>* head) {
            adjNode<T>* newNode = new adjNode<T>(value,cost,head);
            return newNode;
        }
    };
}

int main()
{
    std::cout << "Hello World!\n";
}
