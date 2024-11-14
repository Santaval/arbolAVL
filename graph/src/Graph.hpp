template <typename VertexType, typename ElementType>
class Graph
{
private:
    int elements;
public:
    Graph();
    ~Graph();
protected:
    virtual void clear() = 0;
    virtual void append_vertex(ElementType element) = 0;
    virtual void delete_vertex(VertexType vertex) = 0;
    virtual void modify_element(VertexType vertex, ElementType newElement) = 0;
    virtual char element(VertexType vertex) = 0;
    virtual void add_edge(VertexType vertex1, VertexType vertex2, weight) = 0;
    virtual void delete_edge(VertexType vertex1, VertexType vertex2) = 0;
    virtual void modify_weight(VertexType vertex1, VertexType vertex2, weight newWeight) = 0;
    virtual double weight(VertexType vertex1, VertexType vertex2) = 0;
    virtual VertexType first_vertex() = 0;
    virtual VertexType next_vertex(VertexType vertex) = 0;
    virtual VertexType first_adjacent(VertexType vertex) = 0;
    virtual VertexType next_adjacent(VertexType vertex, VertexType adjacent) = 0;

    inline bool empty() const { return this->amount_vertex() == 0; }
    int amount_vertex() const { return elements; }
};


template <typename VertexType, typename ElementType>
Graph<VertexType, ElementType>::Graph(/* args */)
{
}

template <typename VertexType, typename ElementType>
Graph<VertexType, ElementType>::~Graph()
{
}

