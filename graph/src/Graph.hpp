template <typename VertexType, typename ElementType>
class Graph
{
private:
    int elements;
public:
    Graph();
    ~Graph();
protected:
    /**
     * @brief Clears the graph, removing all vertices and edges.
     * 
     * This function will reset the graph to an empty state, removing all
     * vertices and edges that have been added. It is a pure virtual function,
     * meaning that it must be implemented by any derived class.
     */
    virtual void clear() = 0;
    /**
     * @brief Appends a vertex with the given element to the graph.
     * 
     * This function adds a new vertex containing the specified element to the graph.
     * The exact behavior of this function depends on the specific implementation
     * of the derived class.
     * 
     * @param element The element to be added as a vertex in the graph.
     */
    virtual void append_vertex(ElementType element) = 0;
    /**
     * @brief Deletes a vertex from the graph.
     * 
     * This function removes the specified vertex from the graph. 
     * Any edges connected to this vertex will also be removed.
     * 
     * @param vertex The vertex to be deleted.
     */
    virtual void delete_vertex(VertexType vertex) = 0;
    /**
     * @brief Modifies the element associated with a given vertex.
     * 
     * This pure virtual function updates the element stored at the specified vertex
     * with a new element provided as an argument.
     * 
     * @param vertex The vertex whose associated element is to be modified.
     * @param newElement The new element to associate with the specified vertex.
     */
    virtual void modify_element(VertexType vertex, ElementType newElement) = 0;
    /**
     * @brief Retrieves the element associated with a given vertex.
     * 
     * This pure virtual function must be implemented by derived classes to
     * return the element corresponding to the specified vertex.
     * 
     * @param vertex The vertex whose associated element is to be retrieved.
     * @return The element associated with the specified vertex.
     */
    virtual char element(VertexType vertex) = 0;
    /**
     * @brief Adds an edge between two vertices with a specified weight.
     * 
     * This pure virtual function must be implemented by derived classes to
     * add an edge between the given vertices with the specified weight.
     * 
     * @param vertex1 The first vertex of the edge.
     * @param vertex2 The second vertex of the edge.
     * @param weight The weight of the edge.
     */
    virtual void add_edge(VertexType vertex1, VertexType vertex2, double weight) = 0;
    /**
     * @brief Deletes an edge between two vertices in the graph.
     * 
     * This function removes the edge connecting the specified vertices
     * from the graph. If the edge does not exist, the graph remains unchanged.
     * 
     * @param vertex1 The first vertex of the edge to be deleted.
     * @param vertex2 The second vertex of the edge to be deleted.
     */
    virtual void delete_edge(VertexType vertex1, VertexType vertex2) = 0;
    /**
     * @brief Modifies the weight of the edge between two vertices.
     * 
     * This function updates the weight of the edge connecting the specified vertices
     * to the new weight provided.
     * 
     * @param vertex1 The first vertex of the edge whose weight is to be modified.
     * @param vertex2 The second vertex of the edge whose weight is to be modified.
     * @param newWeight The new weight to be assigned to the edge.
     */
    virtual void modify_weight(VertexType vertex1, VertexType vertex2, double newWeight) = 0;
    /**
     * @brief Pure virtual function to get the weight of the edge between two vertices.
     * 
     * This function should be overridden in derived classes to provide the specific 
     * implementation for retrieving the weight of the edge connecting vertex1 and vertex2.
     * 
     * @param vertex1 The first vertex of the edge.
     * @param vertex2 The second vertex of the edge.
     * @return double The weight of the edge between vertex1 and vertex2.
     */
    virtual double weight(VertexType vertex1, VertexType vertex2) = 0;
    /**
     * @brief Retrieves the first vertex in the graph.
     * 
     * This pure virtual function must be implemented by derived classes to 
     * return the first vertex in the graph. The definition of the "first" 
     * vertex is dependent on the specific implementation of the graph.
     * 
     * @return VertexType The first vertex in the graph.
     */
    virtual VertexType first_vertex() = 0;
    /**
     * @brief Get the next vertex in the graph.
     * 
     * This function returns the next vertex in the graph relative to the given vertex.
     * The specific behavior and order of traversal depend on the implementation.
     * 
     * @param vertex The current vertex.
     * @return VertexType The next vertex in the graph.
     */
    virtual VertexType next_vertex(VertexType vertex) = 0;
    /**
     * @brief Get the first adjacent vertex of the given vertex.
     * 
     * This function returns the first vertex that is adjacent to the specified vertex.
     * The definition of "first" is dependent on the specific implementation of the graph.
     * 
     * @param vertex The vertex for which to find the first adjacent vertex.
     * @return VertexType The first adjacent vertex.
     */
    virtual VertexType first_adjacent(VertexType vertex) = 0;
    /**
     * @brief Get the next adjacent vertex to the given vertex.
     * 
     * This function returns the next adjacent vertex to the specified vertex
     * in the graph. If there are no more adjacent vertices, the function
     * should return a value indicating the end (implementation-specific).
     * 
     * @param vertex The vertex for which to find the next adjacent vertex.
     * @param adjacent The current adjacent vertex.
     * @return VertexType The next adjacent vertex.
     */
    virtual VertexType next_adjacent(VertexType vertex, VertexType adjacent) = 0;

    /**
     * @brief Checks if the graph is empty.
     * 
     * This function returns true if the graph has no vertices, 
     * otherwise it returns false.
     * 
     * @return true if the graph is empty, false otherwise.
     */
    inline bool empty() const { return this->amount_vertex() == 0; }
    /**
     * @brief Get the number of vertices in the graph.
     * 
     * This function returns the total number of vertices currently present
     * in the graph.
     * 
     * @return int The number of vertices in the graph.
     */
    inline int amount_vertex() const { return elements; }
};


template <typename VertexType, typename ElementType>
Graph<VertexType, ElementType>::Graph(/* args */)
{
}

template <typename VertexType, typename ElementType>
Graph<VertexType, ElementType>::~Graph()
{
}

