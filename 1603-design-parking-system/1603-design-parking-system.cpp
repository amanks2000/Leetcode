class ParkingSystem {
public:
    vector<int> vec;
    ParkingSystem(int big, int medium, int small) {
        vec = {big, medium, small};
    }
    
    bool addCar(int carType) {
        return --vec[carType-1] >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */