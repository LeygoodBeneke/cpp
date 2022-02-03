#include<vector>

using namespace std;

template<typename T>
class Table{
private:
    std:: vector<std:: vector<T>> table;
public:
    Table(size_t x, size_t y) {
        Resize(x, y);
    }

    pair<size_t, size_t> Size() const{
        if (table.empty() || table[0].empty()) return make_pair(0, 0);
        return std:: make_pair(table.size(), table[0].size());
    }

    void Resize(size_t x, size_t y){
        table.resize(x);
        for (int i = 0; i < x; i++) table[i].resize(y);
    }

    const vector<T>& operator[](size_t idx) const {
        return table[idx];
    }

    vector<T>& operator[](size_t idx){
        return table[idx];
    }
};

void TestTable() {
    Table<int> t(1, 1);
    t[0][0] = 42;
    t.Resize(3, 4);
}

int main() {
    TestTable();
    return 0;
}