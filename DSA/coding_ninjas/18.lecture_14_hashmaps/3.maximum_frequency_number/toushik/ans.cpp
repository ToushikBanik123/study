#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
class IndexAndCount {
public:
    int index;
    int count;

    IndexAndCount() : index(-1), count(0) {}   // default constructor

    IndexAndCount(int idx) {
        index = idx;
        count = 1;
    }
};

template <typename T>
vector<T> takeInput() {
    vector<T> ansArray;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        T temp;
        cin >> temp;
        ansArray.push_back(temp);
    }
    return ansArray;
}

template <typename T>
unordered_map<T, IndexAndCount<T>> vectorToMap(vector<T>& inputArray) {
    unordered_map<T, IndexAndCount<T>> answerMap;

    for (int i = 0; i < inputArray.size(); i++) {
        T val = inputArray[i];

        if (answerMap.find(val) == answerMap.end()) {
            answerMap[val] = IndexAndCount<T>(i);   // first occurrence
        } else {
            answerMap[val].count++;                // increment count
        }
    }

    return answerMap;
}

int main() {
    vector<int> inputArray = takeInput<int>();
    auto mp = vectorToMap<int>(inputArray);

    // optional: print result
    for (auto& it : mp) {
        cout << it.first << " -> index: "
             << it.second.index << ", count: "
             << it.second.count << endl;
    }

    return 0;
}
