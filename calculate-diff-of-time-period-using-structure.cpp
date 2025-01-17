struct Time {
    int h, m, s;
};

Time timeDifference(Time t1, Time t2) {
    Time diff;
    int a = t1.h*3600 + t1.m*60 + t1.s;
    int b = t2.h*3600 + t2.m*60 + t2.s;
    int c = abs(a-b);
    diff.h = c/3600;
    c %= 3600;
    diff.m = c/60;
    diff.s = c%60;
    return diff;
}
