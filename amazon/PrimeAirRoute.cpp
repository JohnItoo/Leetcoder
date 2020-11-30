#include <bits/stdc++.h>
using namespace std;

struct Route {
  int id;
  int distance;
public: Route(int idx, int distancex) {
    this->id = idx;
    this->distance = distancex;
  }
};

bool comp1(Route one, Route two) {
  if (one.distance == two.distance) return one.id < two.id;
  return one.distance > two.distance;
}
bool comp2(Route one, Route two) {
  if (one.distance == two.distance) return one.id < two.id;
  return one.distance < two.distance;
}

// O(n*m)
vector<int> bruteforce(int maxTravelDistance, vector<Route> forwardRouteList, vector<Route> returnRouteList) {
  int n = forwardRouteList.size();
  int m = returnRouteList.size();
  vector<int> result(2);
  int mx = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum = forwardRouteList[i].distance + returnRouteList[j].distance;
      if (sum <= maxTravelDistance && sum > mx) {
        result[0] = forwardRouteList[i].id;
        result[1] = returnRouteList[j].id;
        mx = sum;
      }
    }
  }
  return result;
}

//O(n+m)
vector<int> twoPointers(int maxTravelDistance, vector<Route> forwardRouteList, vector<Route> returnRouteList) {
  sort(forwardRouteList.begin(), forwardRouteList.end(), comp1);
  sort(returnRouteList.begin(), returnRouteList.end(), comp2);
  int n = forwardRouteList.size();
  int m = returnRouteList.size();
  vector<int> result(2);
  int mx = 0;
  int i = 0; int j = 0;
  while (i < n && j < m) {
    while (j < m && forwardRouteList[i].distance + returnRouteList[j].distance <= maxTravelDistance) j++;
    if (j - 1 >= 0 && forwardRouteList[i].distance + returnRouteList[j - 1].distance > mx) {

      result[0] = forwardRouteList[i].id;
      result[1] = returnRouteList[j - 1].id;
      mx =  forwardRouteList[i].distance + returnRouteList[j - 1].distance;
    }

    while (j < m && i < n && forwardRouteList[i].distance + returnRouteList[j].distance > maxTravelDistance) i++;

    if (forwardRouteList[i].distance + returnRouteList[j - 1].distance > mx) {

      result[0] = forwardRouteList[i].id;
      result[1] = returnRouteList[j - 1].id;
      mx =  forwardRouteList[i].distance + returnRouteList[j - 1].distance;
    }

  }
  return  result;
}

vector<int> optimize(int maxTravelDistance, vector<Route> forwardRouteList, vector<Route> returnRouteList) {
  // return bruteforce(maxTravelDistance, forwardRouteList, returnRouteList);
  return twoPointers(maxTravelDistance, forwardRouteList, returnRouteList);

}

int main() {
  int mtd; cin >> mtd;
  int n; cin >> n;
  vector<Route> frl;

  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    Route route = Route(x, y);
    frl.push_back(route);
  }

  int m; cin >> m;

  vector<Route> rrl;
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    Route route = Route(x, y);
    rrl.push_back(route);
  }

  vector<int> res = optimize(mtd, frl, rrl);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}








