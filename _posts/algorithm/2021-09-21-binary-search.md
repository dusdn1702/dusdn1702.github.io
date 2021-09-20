---
title: "알고리즘 분류별 공부"
excerpt: "이진탐색"
permalink: /algorithms/69

categories:
  - algorithms
tags:
  - algorithms
  - java

---

## 알고리즘 - 이분탐색

가운데로 자르고 있는 쪽 찾고를 반복하는 알고리즘이다.

시간복잡도는 O(log2N)이다.



### 언제 사용하는가?

정렬된 배열이나 리스트를 탐색할 때 사용



### 작동방식

1. 정렬되어 있는 탐색 대상 array[low] 부터 array[high]
2. Mid 값 도출 (low+high)/2
3. Array[mid] 와 key 비교해 key가 크면 low = mid + 1, key가 작으면 low = mid - 1, 같으면 key == mid
4. low>high 동안 반복



### in java

1. 재귀함수

   ```java
   int binarySearch(int key, int low, int high) {
   	int mid;
   
   	if(low <= high) {
   		mid = (low + high) / 2;
   
   		if(key == arr[mid]) { // 탐색 성공 
   			return mid;
   		} else if(key < arr[mid]) {
   			// 왼쪽 부분 arr[0]부터 arr[mid-1]에서의 탐색 
   			return binarySearch(key ,low, mid-1);  
   		} else {
   			// 오른쪽 부분 - arr[mid+1]부터 arr[high]에서의 탐색 
   			return binarySearch(key, mid+1, high); 
   		}
   	}
   
   	return -1; // 탐색 실패 
   }
   ```

2. 반복문

   ```java
   int binarySearch(int key, int low, int high) {
   	int mid;
   
   	while(low <= high) {
   		mid = (low + high) / 2;
   
   		if(key == arr[mid]) {
   			return mid;
   		} else if(key < arr[mid]) {
   			high = mid - 1;
   		} else {
   			low = mid + 1;
   		}
   	}
   
   	return -1; // 탐색 실패 
   }
   ```

#### 프로그래머스 - 입국심사

```java
import java.util.Arrays;

class 입국심사 {
    private int[] arr;
    long answer = 0;
    long all = 0;

    public long solution(int n, int[] times) {
        all = n;
        arr = times;
        Arrays.sort(arr);

        long min = 0;
        long max = (long) arr[arr.length - 1] * n;

        return binarySearch(min, max);
    }

    long binarySearch(long low, long high) {
        while(low <= high) {
            long mid = (low + high) / 2;
            long done = 0;
            for (int j : arr) {
                done += mid / j;
            }
            if(done < all) {
                low = mid + 1;
            } else {
                high = mid - 1;
                answer = mid;
            }
        }
        return answer;
    }
}
```