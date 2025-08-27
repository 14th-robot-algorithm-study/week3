#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
 
struct Customer {
    int id;
    int arrive;
    int A_used; 
    int B_used; 
};
 
int T;
int N, M, K, A, B;
int ans;
 
int A_time[11], B_time[11];   
int A_end[11], B_end[11];     
int A_customer[11], B_customer[11]; 
 
Customer customer[1001];
 
void simulation() {
    queue<int> waitRec;  
    queue<int> waitRep; 
    int finished = 0;
    int time = 0;
 
    while (finished < K) {
        for (int i = 1; i <= K; i++) {
            if (customer[i].arrive == time) waitRec.push(i);
        }
 
        for (int i = 1; i <= N; i++) {
            if (A_customer[i] && A_end[i] == time) {
                int cid = A_customer[i];
                waitRep.push(cid);
                A_customer[i] = 0;
            }
        }
 
        for (int j = 1; j <= M; j++) {
            if (B_customer[j] && B_end[j] == time) {
                B_customer[j] = 0;
                finished++;
            }
        }
 
        for (int i = 1; i <= N; i++) {
            if (A_customer[i] == 0 && !waitRec.empty()) {
                int cid = waitRec.front();
                waitRec.pop();
                A_customer[i] = cid;
                A_end[i] = time + A_time[i];
                customer[cid].A_used = i;
            }
        }
 
        for (int j = 1; j <= M; j++) {
            if (B_customer[j] == 0 && !waitRep.empty()) {
                int cid = waitRep.front(); 
                waitRep.pop();
                B_customer[j] = cid;
                B_end[j] = time + B_time[j];
                customer[cid].B_used = j;
            }
        }
 
        time++;
    }
}
 
int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M >> K >> A >> B;
        for (int i = 1; i <= N; i++) cin >> A_time[i];
        for (int i = 1; i <= M; i++) cin >> B_time[i];
        for (int i = 1; i <= K; i++) {
            cin >> customer[i].arrive;
            customer[i].id = i;
            customer[i].A_used = 0;
            customer[i].B_used = 0;
        }
 
        memset(A_end, 0, sizeof(A_end));
        memset(B_end, 0, sizeof(B_end));
        memset(A_customer, 0, sizeof(A_customer));
        memset(B_customer, 0, sizeof(B_customer));
 
        simulation();
 
        ans = 0;
        for (int k = 1; k <= K; k++) {
            if (customer[k].A_used == A && customer[k].B_used == B) {
                ans += customer[k].id;
            }
        }
 
        if (ans == 0) ans = -1;
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}
