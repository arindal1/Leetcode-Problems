class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
     int x = gcd(jug1Capacity,jug2Capacity) ;
     if(jug1Capacity+ jug2Capacity < targetCapacity)
        return false;
     if(targetCapacity % x == 0 )
        return true ;
     return false ;
    }
};
