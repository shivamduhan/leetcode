int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int start = 0, total = 0, gas_left = 0;
    for (int i = 0; i<gasSize; i++) {
        gas_left += gas[i] - cost[i]; //
        if (gas_left < 0) {
            start = i+1; //have to start from next gas station
            total += gas_left; 
            gas_left = 0; //will now start again from next station

        }
    }
    return (total + gas_left < 0) ? -1 : start;
}
