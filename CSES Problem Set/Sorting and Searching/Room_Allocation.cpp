# include <bits/stdc++.h>
# define pi pair<int,int>
# define mp make_pair
using namespace std;


struct Interval{
	int L, R, index;
};


int cmp(Interval a, Interval b){
	return a.L < b.L;
}
void solve(){
	int N;
	cin >> N;
	vector<Interval> customers(N);
	for(int i = 0; i < N; i++){
		int L, R;
		cin >> L >> R;
		Interval rng = {L, R, i};
		customers[i] = rng;
	}
	sort(customers.begin(), customers.end(), cmp);
	priority_queue<pi> pq;
	vector<int> designatedRooms(N);
	int rooms = 0;
	int lastRoom = 0;
	for(int i = 0; i < N; i++){
		if(pq.empty()){
			lastRoom++;
			pq.emplace(mp(-customers[i].R, lastRoom));
			designatedRooms[customers[i].index] = lastRoom;
		}
		else{
			if(-pq.top().first < customers[i].L){
				pq.emplace(mp(-customers[i].R, pq.top().second));
				designatedRooms[customers[i].index] = pq.top().second;
				pq.pop();
			}
			else{
				lastRoom++;
				pq.emplace(mp(-customers[i].R, lastRoom));
				designatedRooms[customers[i].index] = lastRoom;
			}
		}
		rooms = max(rooms, (int) pq.size());
	}
	cout << rooms << endl;
	for(int i = 0; i < N; i++){
		cout << designatedRooms[i] << " ";
	}
	cout << endl;
	
}



int main(){
	solve();
	return 0;
}

