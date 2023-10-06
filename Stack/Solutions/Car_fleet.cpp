class Car{
public:
    Car(int position, int speed){
        this->pos = position;
        this->spd = speed;
    }
    int pos;
    int spd;
};


class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        int n = position.size();
        for (int i = 0; i < n ; i ++){
            cars.emplace_back(position.at(i), speed.at(i));
        }
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
            return a.pos<b.pos;
        });

        stack<float> times;
        for (int i = 0; i < n; i++){
            float time = (target - cars.at(i).pos)/(float)cars.at(i).spd;
            while (!times.empty() && time>=times.top()){
                times.pop();
            }
            times.push(time);
        }
        return times.size();
    }
};