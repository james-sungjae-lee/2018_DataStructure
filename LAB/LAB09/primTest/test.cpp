#include <iostream>
#include <limits.h>

#define V 6

int matrix[V][V] = {
    {100, 5, 100, 12, 100, 100},
    {5, 100, 6, 10, 24, 100},
    {100, 6, 100, 17, 100, 30},
    {12, 10, 17, 100, 20, 100},
    {100, 24, 100, 20, 100, 13},
    {100, 100, 30, 100, 13, 100}
};

int minKey(int key[], bool visited[])
{

   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (visited[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

int printMST(int firstNode[], int n, int matrix[V][V])
{
   int weight = 0;
   std::cout << "MST :  ";
   for (int i = 1; i < V; i++){
     std::cout << "(" << char(firstNode[i]+65) << "," << char(i+65) << ")  -> ";
     weight += matrix[i][firstNode[i]];
   }
   std::cout << "END" << '\n';
   std::cout << "Weight : " << weight << '\n';
   return 0;
}

void primMST(int matrix[V][V])
{
     int firstNode[V];
     int key[V];
     bool visited[V];

     for (int i = 0; i < V; i++){
       key[i] = INT_MAX, visited[i] = false;
     }

     key[0] = 0;
     firstNode[0] = -1;

     for (int count = 0; count < V-1; count++){
       int u = minKey(key, visited);

       visited[u] = true;

       for (int v = 0; v < V; v++){
         if (matrix[u][v] && visited[v] == false && matrix[u][v] <  key[v]){
           firstNode[v]  = u, key[v] = matrix[u][v];
         }
       }
     }

     printMST(firstNode, V, matrix);
}

void MSTbasic(int matrix[V][V]){

}

int main()
{
    std::cout << "   " ;
    for (size_t i = 0; i < V; i++) {
      std::cout << char(i + 65) << "  ";
    }
    std::cout << '\n';
    for (size_t i = 0; i < V; i++) {
      std::cout << char(i+65) << ' ';
      for (size_t j = 0; j < V; j++) {
        std::cout << matrix[i][j] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << '\n';
    MSTbasic(matrix);
    std::cout << '\n';
    primMST(matrix);

    return 0;
}
