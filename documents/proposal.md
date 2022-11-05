## Leading Question 
Bitcoin has become the crypto currency most traded around the globe as its value has skyrocketed throughout the years. As its popularity has increased, more and more people have become Bitcoin users and contributed to Bitcoin trading in the Bitcoin OTC platform. Bitcoin users are anonymous in this platform and thus the issue of fradulent and risky transactions is of high priority. To aid in this issue we will be using the Bitcoin OTC trust weighted signed network dataset (http://snap.stanford.edu/data/soc-sign-bitcoin-otc.html) to sort and organize all members based on their rankings. Those with higher rankings would hold a higher higher position/priority than those with lower rankings. Through this we can implement a find algorithm in which users can search members and see their ranking to be more informed before making transactions. 

## Dataset Acquisition
The dataset that will be used in this project is the Bitcoin OTC trust weighted signed network dataset available at http://snap.stanford.edu/data/soc-sign-bitcoin-otc.html. 

## Data Format
This dataset contains 5,881 Bitcoin members as node and 35,592 edge with each Bitcoin member ranked on a scale from -10 to +10 classified as our edge weight. This dataset is stored in a CSV file with four columns; Source, Target, Rating, Time. Source is the Bitcoin member rating, Target is the Bitcoin member being rate, Rating is as mentioned the rating for the Bitcoin member on a scale from -10 to +10, and Time is the time of the rating in seconds since Epoch. 

## Data Correction
Our project focuses on the data having a Source, Target, and Rating thus if any data is missing any of those three types of information that line will be ignored. This also implies that the whole column designated to Time can be ignored as such information does not contribute to the goal of our project. 

## Data Storage 
We are going to make a node struct that will contain the id of the sender or sendee, and the total sum of all of the ratings they receive. We will then have a list of vertices that is used to represent each node. We will also make a 2d array that will be used as a list of adjacency lists to help traverse the nodes in the graph. Each element within the adjacency list will be the node represenatation of the sender and the edge weight represented as a pair. This will allow us to easily find the number of edges that each individual node is connected to and we can store the sum of all the ratings then and find their average rating even if new transactions happen. Each node will in the vertices list would be every person of the list and we will direct the edges pointing from the sender to the sendee since the sender gives the rating of how the sendee did. n will represent the number of vertices and m is the number of edges, the vertice list will hold up O(n) space, the adjacency list will hold up O(n*m) space.

## Algorithm 
**BFS Traversal** - Based on how we will be implementing our Data Storage as explained above, the implementation of the adjancency list based on the node struct will greatly expedite the creation of the BFS traversal which would prioritize the nodes at the begining as they would be the nodes with best rank. Our graph will have implement nodes ready with the information we need during the data processing into our data storage stage thus no changes would need to be done for input into our BFS traversal as we will just keep using node input and tracking onto a queue. The output of our BFS traversal would be a queue filled with our best ranked Bitcoin member node at the front and worst at the end and when used we would start with the top of the queue as our searches would be based on best ranks. n will represent the number of vertices, the target Big O efficiency will be O(n) for both time and space.

**Prim's Algorithm for Minimum Spanning Tree** - This algorithm gives us a different perspective on visualizing our dataset as we can take the nodes and edges of the data sets and find a tree made of the subtree of edges that depicts a minimized weight of all the edges. The weight in our dataset is the rankings and this tree will highlight the Bitcoin members that might be the most risky to engage in transactions. Due to the algorithms main use of nodes, edges, and the overall data being a weighted undirected graph we wouln't have to covert anything from our stored dataset. The expected output is a small tree that would be printed with the same algorithms as the print tree functions from MPs and Labs that were used to test our codes. n will represent the number of vertices, the target Big O efficiency will be O(n^2) for time and O(n+m) for space.

**Floyd-Warshall Algorithm for Shortest Path** - This algorithm gives us the shortest path between all pairs of vertices in a weighted graph. This would be extremely useful in Bitcoin member transaction suggestion during a Bitcoin member query as it could provide possible Bitcoin members that could be similar matches based on the rank of the Bitcoin member being searched. Similarly to the other algorithms no convertion is needed as this algorithm works on the weighted graph created by the dataset acquired with vertices and edges. n will represent the number of vertices, the target Big O efficiency will be O(n^3) for time and O(n^2) for space.

## Timeline
**Week of November 30** - Look through and decide on the dataset we want to work on and choose what we would want to do with it. Complete data acquisition and familiarize ourselves with data. Complete team contract, porject proposal, and first development log. Completion by November 4. 

**Week of November 6** - Work on creating our data structure for storage and processing our data into our data structure for storage. Complete our data structure storage algorithm along with tests, complete development log, and be halfway done with our traversal algorithm by November 11. 

**Week of November 13** - Test that our data structure works appropriatly and gather all comments, questions, and concerns for the Mid-Project Checkin by November 15. Finish our traversal algorithm, complete development log, and begin our Prim's Algorithm for minimum spanning tree by November 18. 

**Week of November 20** - Complete Prim's Algorithm along with tests, complete development log, and begin creating the Floyd-Warshall Algorithm for Shortest Path by November 25.

**Week of November 27** - Complete Floyd-Warshall Algorithm along with tests, complete development log, and begin the project report by December 2.  

**Week of December 4** - Perform final tests on project and film video presentation by December 6. Add final details to github files, presentation, and report by December 7 and turn in project by December 8.
