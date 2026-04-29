#include <iostream>
#define NOT 999999

int map[4][4] = {
    {0,   50,  NOT, 20 },   // A에서 각 노드까지
    {NOT, 0,   5,   NOT},   // B에서 각 노드까지
    {NOT, NOT, 0,   NOT},   // C에서 각 노드까지
    {NOT, 10,  25,  0  }    // D에서 각 노드까지
};

int result[4] = { 0, 50, NOT, 20 };   // 최소비용 테이블
int visited[4] = { 1, 0, 0, 0 };      // 방문 여부 (A는 시작점이므로 방문됨)

// 방문하지 않은 노드 중 최소 비용 노드 찾기
int findMin()
{
    int min = 987654321;
    int minIndex = -1;

    for (int i = 0; i < 4; i++)
    {
        if (visited[i] == 0 && result[i] < min)
        {
            min = result[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra()
{
    int minIndex = 0;

    for (int i = 0; i < 3; i++)  // 3번 반복 (시작점 제외한 나머지 노드)
    {
        // 1. via가 0인 곳 중에 최소값을 찾기
        minIndex = findMin();

        // 2. a vs b 해서 a가 더 저렴하면 전광판에 갱신해준다.
        // a = 경유지까지 가는 비용 + 경유지에서 목적지까지 가는 비용
        // b = A에서 목적지까지 가는 비용
        for (int j = 0; j < 4; j++)
        {
            int a = result[minIndex] + map[minIndex][j];  // 경유 비용
            int b = result[j];                            // 직행 비용

            if (a < b)
            {
                result[j] = a;  // 더 저렴하면 갱신
            }
        }

        visited[minIndex] = 1;  // 해당 노드를 거쳐서 지나가는 비용과 값을 비교 완료
    }

    // 결과 출력
    std::cout << "=== 최단 거리 결과 ===" << std::endl;
    char nodes[] = { 'A', 'B', 'C', 'D' };
    for (int i = 0; i < 4; i++)
    {
        std::cout << "A → " << nodes[i] << ": " << result[i] << "만원" << std::endl;
    }
}

int main()  // char main()에서 int main()으로 수정
{
    dijkstra();
    return 0;
}