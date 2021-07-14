internal int clamp (int min, val, max) {
    if (val < min) return min;
    if (val > max) return max;

    return val;
}