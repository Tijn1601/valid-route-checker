# Valid Route Checker
## Description:
This project uses custom classes to create a directional weighted graph. With this graph, the user can give a list of nodes, and the program will check if this route is valid. If it is a valid route, the program will also display the total length of this path. If it is an invalid path, the program will say it is invalid and mark the distance as 0.

## Usage:
When running the program you will need to input the file name for the graph, and after that, you will need to input the file name for the routes that will be checked. For example, "samplegraph.txt sample_routes1.txt" will load the vertices and edges in "samplegraph.txt" and create a weighted directional graph, and then will check the routes on "sample_routes1.txt".

## Commands:
In the routes file, the user will input the routes that the user wants checked. The name of each place should be in order of which place to visit next. Each place in the sequence should be separated with a space. For a new route to be checked, the next list of places should be written on a new line. When the program is executed, it will print out if this route is valid, as well as the length of the path if this path is valid.
