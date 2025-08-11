# -*- coding: utf-8 -*-
"""
Created on Sat Apr 22 21:46:27 2023

@author: diana
"""
import networkx as nx 
import matplotlib.pyplot as plt 
import numpy as np
np.set_printoptions(threshold=np.inf)
import pandas as pd


### GRAFO
def grafo(neighbors, weights):
    G = nx.Graph()

    # Add the edges with weights to the graph
    for edge, weight in weights.items():
        G.add_edge(edge[0], edge[1], weight=weight)

    # Set the position of the nodes
    pos = nx.spring_layout(G)

    # Draw the nodes and edges of the graph
    fig, ax = plt.subplots(figsize=(12, 8))
    nx.draw_networkx_nodes(G, pos, node_color='crimson')
    nx.draw_networkx_edges(G, pos, width=0.8, node_size=100)
    nx.draw_networkx_labels(G, pos, font_size=12, font_family='Arial')

    # Add the edge labels
    labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

    # Show the graph
    plt.axis('off')
    plt.show()

    """
    # Create a new Graph
    G = nx.Graph()
    
    # Add nodes to the Graph
    for node in neighbors:
        G.add_node(node)
    
    # Add edges to the Graph
    for edge, weight in weights.items():
        G.add_edge(edge[0], edge[1], weight=weight)
    
    # nx.draw(G, with_labels=True)
    
    
    """
    # Calculate the adjacency matrix with weights
    adj_matrix = nx.adjacency_matrix(G, weight='weight').toarray()
    
    # Create a dictionary to map node labels to indices
    label_dict = {node: i for i, node in enumerate(G.nodes())}
    
    # Set the labels for the adjacency matrix
    adj_matrix_labels = np.empty(adj_matrix.shape, dtype=object)
    for i in range(adj_matrix.shape[0]):
        for j in range(adj_matrix.shape[1]):
            adj_matrix_labels[i, j] = f"{list(label_dict.keys())[i]} - {list(label_dict.keys())[j]}: {adj_matrix[i, j]}"
    
    # Calculate the adjacency list with weights
    adj_list = {}
    for node in G.nodes():
        adj_list[node] = []
        for neighbor, w in G[node].items():
            adj_list[node].append((neighbor, w['weight']))
    
    # Print the Graph, adjacency matrix, and adjacency list with labels
    """
    print("Graph:")
    print(G.nodes())
    print(G.edges())
    print("Adjacency Matrix with Labels:")
    print(adj_matrix_labels)
    print("Adjacency List with Weights:")
    print(adj_list)
    """
    return adj_list

### KRUSKAL ALGORITHM 


# Define a function to find the minimum spanning tree given an adjacency list and a starting node
def kruskal_mst(adj_list, start):
    # Sort all edges in the graph by weight in ascending order
    edges = []
    for node, neighbors in adj_list.items():
        for neighbor, weight in neighbors:
            edges.append((weight, node, neighbor))
    edges.sort()
    
    # Create a dictionary to keep track of which nodes belong to which set
    node_set_dict = {}
    for node in adj_list.keys():
        node_set_dict[node] = node
    
    # Define a function to find the set that a node belongs to
    def find_set(node):
        if node_set_dict[node] != node:
            node_set_dict[node] = find_set(node_set_dict[node])
        return node_set_dict[node]
    
    # Define a function to join two sets
    def union(node1, node2):
        set1 = find_set(node1)
        set2 = find_set(node2)
        node_set_dict[set1] = set2
    
    # Initialize an empty list to hold the edges in the MST
    mst = []
    
    # Iterate over all edges in the graph
    for weight, node1, node2 in edges:
        # If the two nodes are in different sets, add the edge to the MST and join the sets
        if find_set(node1) != find_set(node2):
            mst.append((node1, node2))
            union(node1, node2)
    
    # Return the MST
    return mst


    
###ADYACENCIA
# list of store abbreviations in Mexico
stores = ["SOL","FAV","GLG","OCO","ZAP","ANG","SAN","ECO","CVS","OPE"]

# adjacency matrix initialization
adj_matrix = [[0 for _ in range(len(stores))] for _ in range(len(stores))]

# dictionary mapping store abbreviations to indices in the adjacency matrix
store_indices = {store: i for i, store in enumerate(stores)}
# list of neighboring stores for each store
neighbors = {
    "SOL":["FAV","ZAP","ANG","OCO"],
    "FAV":["OCO","ZAP","SAN","SOL","ANG"],
    "GLG":["ZAP","ANG","OPE","CVS","ECO"],
    "OCO":["FAV","SOL"],
    "ZAP":["FAV","SOL","SAN","ANG","GLG","OPE"],
    "ANG":["FAV","SOL","ZAP","SAN","GLG"],
    "SAN":["FAV","ZAP","ANG","OPE"],
    "ECO":["OPE","GLG","CVS"],
    "CVS":["OPE","GLG","ECO"],
    "OPE":["ZAP","GLG","CVS","ECO","SAN"] 
}

###DISTANCIA EN TIEMPO

distancias = {
    ('OCO','SOL'): 14,
    ('OCO','FAV'): 11,
    ('FAV','SAN'): 20,
    ('FAV','ZAP'): 14,
    ('FAV','SOL'): 12,
    ('FAV','ANG'): 20 ,
    ('SOL','ZAP'): 21,
    ('SOL','ANG'): 20,
    ('SAN','ANG'): 15,
    ('SAN','ZAP'): 13,
    ('ZAP','ANG'): 18,
    ('ZAP','GLG'): 25,
    ('ZAP','OPE'): 15,
    ('ANG','GLG'): 24 ,
    ('OPE','GLG'): 25,
    ('OPE','CVS'): 31,
    ('OPE','ECO'): 28,
    ('OPE','SAN'): 16,
    ('GLG','ECO'): 20,
    ('GLG','CVS'): 23,
    ('ECO','CVS'): 11
}


### OUTPUTS 

print("Grafo distancias en Tiempo de viaje ")
adj_list = grafo(neighbors, distancias)


start_node = 'SOL'
mst = kruskal_mst(adj_list, start_node)

# Create a new graph with only the edges in the MST


mst_graph = nx.Graph()
for node, neighbors in adj_list.items():
    for neighbor, weight in neighbors:
        if (node, neighbor) in mst or (neighbor, node) in mst:
            mst_graph.add_edge(node, neighbor, weight=weight)

# Draw the graph
nx.draw(mst_graph, with_labels=True)

# Set the position of the nodes
pos = nx.spring_layout(mst_graph)

# Draw the nodes and edges of the graph
fig, ax = plt.subplots(figsize=(12, 8))
nx.draw_networkx_nodes(mst_graph, pos, node_color='slategray')
nx.draw_networkx_edges(mst_graph, pos, width=0.8, node_size=100)
nx.draw_networkx_labels(mst_graph, pos, font_size=12, font_family='Arial')

# Add the edge labels
labels = nx.get_edge_attributes(mst_graph, 'weight')
nx.draw_networkx_edge_labels(mst_graph, pos, edge_labels=labels)

# Show the graph
plt.axis('off')

plt.show()




