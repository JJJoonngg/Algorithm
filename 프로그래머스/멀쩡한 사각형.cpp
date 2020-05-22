//
// Created by 김종신 on 2020/05/22.
//
long long solution(int w, int h) {
    long long sum = (long long) w * (long long) h, gcd;
    int tmp = w < h ? w : h;
    for (int i = tmp; i > 0; i--)
        if (!(w % i) && !(h % i)) {
            gcd = i;
            break;
        }

    return sum - gcd * ((w / gcd) + (h / gcd) - 1);
}