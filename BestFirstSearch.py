#Method BestFirstSearch for Searching the Goal State                                #-----Chandresh Maniya-----
def BestFirstSearch(graph, start, goal, heuristicValueDict):                                            
    # keep track of all visited nodes                                               #-----Best First Search-----
    explored = []

    # keep track of nodes to be checked
    queue = [start]
    flag = 0

    # keep looping until there are nodes still to be checked
    while queue:
        # pop first node from queue
        node = queue.pop(0)
        if node == goal:
            explored.append(node)
            flag = 1
            break
        else:
            if node not in explored:
                # add node to list of explored nodes
                explored.append(node)
                adjacents = graph[node]
 
                # add neighbours with minimum heuristic Values of node to queue
                localHeuristic = []
                for i in adjacents:
                    localHeuristic.append(heuristicValueDict[i])
                
                #finding minimum heuristic from the list of neighbours
                localMin = min(localHeuristic)

                for key, value in heuristicValueDict.items():
                    if value == localMin:
                        queue.append(key)
                
    if flag == 1:
        print("Succesfully Reached to the Goal!!! :)")
        print(" Final Path : ",explored)
    else:
        print("Goal is Not Rechable :(")
        

#Entering Count of Total Nodes
n = int(input("Enter Number of Nodes: "))
nodes = []  #List of All Nodes

#One by one all nodes will be entered
for i in range(0, n):
    nodes.append(input("Enter Node " + str(i+1) + ": "))

#List of adjacents of all nodes
adjacentList = []

#One by One adjacents of all nodes will be entered
for i in range(0, n):
    adjacentList.append(input("Enter Adjecents of Node " + nodes[i] + " With Space: ").split())

#Graph of all nodes
graph = {}

#Assigning Nodes and Adjacent of Nodes to the dictionary Graph
for (key, value) in zip(nodes, adjacentList):
    graph[key] = value

heuristicValues = []

for i in range(0, n):
    heuristicValues.append(int(input("Enter Heuristic Value of " + nodes[i] + " - G : ")))

heuristicValueDict = {}

for (key, value) in zip(nodes, heuristicValues):
    heuristicValueDict[key] = value

print("Graph :")
print(graph)
print("\n")
source = input("Enter Source Node: ")
goal = input("Enter Goal Node: ")


#Calling BestFirstSearch method
BestFirstSearch(graph, source, goal, heuristicValueDict)