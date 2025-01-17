struct Distance {
    int feet;
    int inches;
};

Distance add(Distance d1, Distance d2) {
    Distance sum;
    sum.feet = d1.feet + d2.feet;
    sum.inches = d1.inches + d2.inches;
    while(sum.inches>=12) {
        sum.feet++;
        sum.inches -= 12;
    }
    return sum;
}
