// Biểu diễn đồ thị bằng dslk 
// Danh sách cạnh
// 2 list : 1 list chưa đỉnh đầu , list còn lại chứa đỉnh cuối

#include <iostream>
#include <fstream>
#include <list>
using namespace std;
list <int> first; // list chua dinh dau
list <int> last; // list chua dinh cuoi
int main() {
	int n, m; // n - so dinh , m - so canh cua Do Thi
	cin >> n >> m;
	int u, v;
	for( int i = 1; i<=m; i++ ) {
		cin >> u >> v;
		first.push_back(u);
		last.push_back(v);
	}

	return 0;
}