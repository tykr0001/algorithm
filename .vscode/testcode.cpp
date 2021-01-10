#include<iostream>
#include<stack>
#include<vector>
#include<memory.h>
int main() {
   std::cin.tie(NULL);
   std::ios_base::sync_with_stdio(false);

   int dot_n, line_n;
   int a, b;
   std::cin >> dot_n >> line_n;
   std::vector<int>* graph = new std::vector<int>[dot_n + 1];
   
   for (int i = 0; i < line_n; i++) {
      std::cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   bool* check_list = new bool[dot_n + 1];
   memset(check_list, false, dot_n + 1);

   std::stack<std::pair<int,int>> stack;
   int count = 0;

   bool judge = false;
   for (int i = 1; i < dot_n + 1; i++) {
      if (check_list[i] == false) {
         check_list[i] = true;
         std::pair<int, int> j = std::make_pair(i, 0);
         while (true) {
                if(graph[j.first].size()==0)
                    break;
            for (int k = j.second; k < graph[j.first].size(); k++) {
               if (check_list[graph[j.first][k]] == false) {
                  check_list[graph[j.first][k]] = true;
                  stack.push(std::make_pair(j.first, 0));
                  j = std::make_pair(graph[j.first][k], 0);
                  judge = false;
                  break;
               }
               if (k == graph[j.first].size() - 1)
                  judge = true;
            }
            if (judge)
               if (stack.empty())
                  break;
               else {
                  j = stack.top();
                  stack.pop();
               }
         }
         count++;
      }

      
   }
   std::cout << count;
}