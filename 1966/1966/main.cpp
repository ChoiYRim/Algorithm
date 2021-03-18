#include <iostream>
#include <queue>
using namespace std;

int main() {
    int testCase = 0;
    int count = 0;
    int documentNum, docuPosition, important;
    
    cin >> testCase;
    
    // testCase의 수만큼 loop 진행
    for (int i = 0; i < testCase; i++) {
        count = 0;
        cin >> documentNum >> docuPosition;
        // 문서 수와 궁금한 문서 위치 받기
        
        queue<pair<int, int>> queue;
        priority_queue<int> priorityQueue;
        // queue와 우선 순위 queue
        
        for (int j = 0; j < documentNum; j++){
            cin >> important;
            queue.push({j, important});
            priorityQueue.push(important);
        }
        // 중요도를 받고 queue에 넣기
        
        // queue가 빌 때까지 while문 돌리기
        while (!queue.empty()) {
            int k = queue.front().first;
            int v = queue.front().second;
            // queue에서 들어간 것 중 1, 2번째 거를 k, v에 return
            
            queue.pop();
            
            // 2번째가 priorityQueue의 top과 동일하면 pop시키고 count세기
            if(priorityQueue.top() == v) {
                priorityQueue.pop();
                count++;
                // 전에 pop된 요소가 궁금한 문서라면 몇번이나 count했는지 print
                if(k == docuPosition) {
                    cout << count << endl;
                    break;
                }
            } else {
                // 아니면 다시 queue 뒤로 넣기
                queue.push({ k, v});
            }
        }
    }
}
