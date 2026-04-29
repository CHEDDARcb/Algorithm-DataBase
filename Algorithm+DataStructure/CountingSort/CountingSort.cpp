#include <iostream>
#include <queue>

int main()
{
    int arr[5] = { 5, 2, 2, 1, 2 };
    int bucket[6] = { };     // 카운트 배열
    int result[5] = { };     // 결과 배열

    //1. bucket에 arr의 값을 넣어준다.
    for (size_t i = 0; i < 5; i++)
    {
        bucket[arr[i]]++;
    }

    //2. bucket의 값을 누적시킨다.
    for (size_t i = 1; i < 6; i++)
    {
        bucket[i] += bucket[i - 1];
    }

    //3. result에 bucket의 값을 넣어준다.
    for (size_t i = 0; i < 5; i++)
    {
        int index = bucket[arr[i]] - 1;
        result[index] = arr[i];

        bucket[arr[i]]--;  // 같은 값의 다음 위치를 위해 감소
    }

    // 결과 출력
    std::cout << "정렬 결과: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}